// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/conn-size/events.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "events.bif.h"

namespace plugin { namespace Bro_ConnSize {

void __bif_events_init(plugin::Plugin* plugin)
	{
	::conn_bytes_threshold_crossed = internal_handler("conn_bytes_threshold_crossed");
	plugin->AddBifItem("conn_bytes_threshold_crossed", plugin::BifItem::EVENT);
	::conn_packets_threshold_crossed = internal_handler("conn_packets_threshold_crossed");
	plugin->AddBifItem("conn_packets_threshold_crossed", plugin::BifItem::EVENT);

	}
} }


