##! This is the implementation of the metrics framework.

@load base/frameworks/notice

module Metrics;

export {
	redef enum Log::ID += { METRICS };
	
	type ID: enum {
		NOTHING,
	};
	
	## The default interval used for "breaking" metrics and writing the 
	## current value to the logging stream.
	const default_break_interval = 15mins &redef;
	
	type Index: record {
		## Host is the value to which this metric applies.
		host:         addr &optional;
		
		## A non-address related metric or a sub-key for an address based metric.
		## An example might be successful SSH connections by client IP address
		## where the client string would be the index value.
		## Another example might be number of HTTP requests to a particular
		## value in a Host header.  This is an example of a non-host based
		## metric since multiple IP addresses could respond for the same Host
		## header value.
		str:        string &optional;
		
		## The CIDR block that this metric applies to.  This is typically
		## only used internally for host based aggregation.
		network:      subnet &optional;
	} &log;
	
	type Info: record {
		ts:           time   &log;
		metric_id:    ID     &log;
		filter_name:  string &log;
		index:        Index  &log;
		value:        count  &log;
	};
	
	# TODO: configure a metrics filter logging stream to log the current
	#       metrics configuration in case someone is looking through
	#       old logs and the configuration has changed since then.
	type Filter: record {
		## The :bro:type:`Metrics::ID` that this filter applies to.
		id:                ID                      &optional;
		## The name for this filter so that multiple filters can be
		## applied to a single metrics to get a different view of the same
		## metric data being collected (different aggregation, break, etc).
		name:              string                  &default="default";
		## A predicate so that you can decide per index if you would like
		## to accept the data being inserted.
		pred:              function(index: Index): bool &optional;
		## Global mask by which you'd like to aggregate traffic.
		aggregation_mask:  count                   &optional;
		## This is essentially applying names to various subnets.
		aggregation_table: table[subnet] of subnet &optional;
		## The interval at which the metric should be "broken" and written
		## to the logging stream.
		break_interval:    interval                &default=default_break_interval;
		## This determines if the result of this filter is sent to the metrics
		## logging stream.  One use for the logging framework is as an internal
		## thresholding and statistics gathering utility that is meant to
		## never log but rather to generate notices and derive data.
		log:               bool                    &default=T;
		## A straight threshold for generating a notice.
		notice_threshold:  count                   &optional;
		## A series of thresholds at which to generate notices.
		## TODO: This is not implemented yet!
		notice_thresholds: vector of count         &optional;
		## If this and a $notice_threshold value are set, this notice type
		## will be generated by the metrics framework.
		note:              Notice::Type            &optional;
	};
	
	global add_filter: function(id: ID, filter: Filter);
	global add_data: function(id: ID, index: Index, increment: count);
	
	# This is the event that is used to "finish" metrics and adapt the metrics
	# framework for clustered or non-clustered usage.
	global log_it: event(filter: Filter);	
	
	global log_metrics: event(rec: Info);
}

redef record Notice::Info += {
	metric_index: Index &log &optional;
};

global metric_filters: table[ID] of vector of Filter = table();
global filter_store: table[ID, string] of Filter = table();

type MetricTable: table[Index] of count &default=0;
# This is indexed by metric ID and stream filter name.
global store: table[ID, string] of MetricTable = table();

# This stores the current threshold index for filters using the
# $notice_thresholds element.
global thresholds: table[string] of count = {} &default=0;

event bro_init() &priority=5
	{
	Log::create_stream(METRICS, [$columns=Info, $ev=log_metrics]);
	}

function write_log(ts: time, filter: Filter, data: MetricTable)
	{
	for ( index in data )
		{
		local val = data[index];
		local m: Info = [$ts=ts, 
		                 $metric_id=filter$id,
		                 $filter_name=filter$name,
		                 $index=index,
		                 $value=val];

		if ( m$index?$host &&
		     filter?$notice_threshold &&
		     m$value >= filter$notice_threshold )
			{
			NOTICE([$note=filter$note,
			        $msg=fmt("Metrics threshold crossed by %s %d/%d", index$host, m$value, filter$notice_threshold),
			        $src=m$index$host, $n=m$value,
			        $metric_index=index]);
			}
		
		else if ( filter?$notice_thresholds &&
		          m$value >= filter$notice_thresholds[thresholds[cat(filter$id,filter$name)]] )
			{
			# TODO: implement this
			}
		
		if ( filter$log )
			Log::write(METRICS, m);
		}
	}


function reset(filter: Filter)
	{
	store[filter$id, filter$name] = table();
	}

function add_filter(id: ID, filter: Filter)
	{
	if ( filter?$aggregation_table && filter?$aggregation_mask )
		{
		print "INVALID Metric filter: Defined $aggregation_table and $aggregation_mask.";
		return;
		}
	if ( [id, filter$name] in store )
		{
		print fmt("INVALID Metric filter: Filter with name \"%s\" already exists.", filter$name);
		return;
		}
	if ( filter?$notice_threshold && filter?$notice_thresholds )
		{
		print "INVALID Metric filter: Defined both $notice_threshold and $notice_thresholds";
		return;
		}
	
	if ( ! filter?$id )
		filter$id = id;
	
	if ( id !in metric_filters )
		metric_filters[id] = vector();
	metric_filters[id][|metric_filters[id]|] = filter;

	filter_store[id, filter$name] = filter;
	store[id, filter$name] = table();
	
	schedule filter$break_interval { Metrics::log_it(filter) };
	}
	
function add_data(id: ID, index: Index, increment: count)
	{
	if ( id !in metric_filters )
		return;
	
	local filters = metric_filters[id];
	
	# Add the data to any of the defined filters.
	for ( filter_id in filters )
		{
		local filter = filters[filter_id];
		
		# If this filter has a predicate, run the predicate and skip this
		# index if the predicate return false.
		if ( filter?$pred &&
		     ! filter$pred(index) )
			next;
		
		local filt_store = store[id, filter$name];
		if ( index?$host )
			{
			if ( filter?$aggregation_mask )
				{
				index$network = mask_addr(index$host, filter$aggregation_mask);
				delete index$host;
				}
			else if ( filter?$aggregation_table )
				{
				index$network = filter$aggregation_table[index$host];
				delete index$host;
				}
			}

		if ( index !in filt_store )
			filt_store[index] = 0;
		filt_store[index] += increment;
		}
	}
