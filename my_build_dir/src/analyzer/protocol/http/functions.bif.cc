// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/http/functions.bif (plugin mode).


#include "functions.bif.h"


#line 2 "functions.bif"

#include "analyzer/protocol/http/HTTP.h"

#line 13 "functions.bif"
Val* BifFunc::bro_skip_http_entity_data(Frame* frame, val_list* BiF_ARGS)
	
#line 14 "functions.bif"
{
	if ( BiF_ARGS->length() != 2 )
		{
		reporter->Error("skip_http_entity_data() takes exactly 2 argument(s)");
		return 0;
		}
	Connection* c = (Connection*) ((*BiF_ARGS)[0]->AsRecordVal()->GetOrigin());
	int is_orig = (int) ((*BiF_ARGS)[1]->AsBool());

#line 14 "functions.bif"

	analyzer::ID id = mgr.CurrentAnalyzer();
	if ( id )
		{
		analyzer::Analyzer* ha = c->FindAnalyzer(id);

		if ( ha )
			{
			if ( ha->IsAnalyzer("HTTP") )
				static_cast<analyzer::http::HTTP_Analyzer*>(ha)->SkipEntityData(is_orig);
			else
				reporter->Error("non-HTTP analyzer associated with connection record");
			}
		else
			reporter->Error("could not find analyzer for skip_http_entity_data");

		}
	else
		reporter->Error("no analyzer associated with connection record");

	return 0;
	} // end of BifFunc::bro_skip_http_entity_data

#line 35 "functions.bif"

#line 50 "functions.bif"
Val* BifFunc::bro_unescape_URI(Frame* frame, val_list* BiF_ARGS)
	
#line 51 "functions.bif"
{
	if ( BiF_ARGS->length() != 1 )
		{
		reporter->Error("unescape_URI() takes exactly 1 argument(s)");
		return 0;
		}
	StringVal* URI = (StringVal*) ((*BiF_ARGS)[0]->AsStringVal());

#line 51 "functions.bif"

	const u_char* line = URI->Bytes();
	const u_char* const line_end = line + URI->Len();

	return new StringVal(analyzer::http::unescape_URI(line, line_end, 0));
	} // end of BifFunc::bro_unescape_URI

#line 56 "functions.bif"
