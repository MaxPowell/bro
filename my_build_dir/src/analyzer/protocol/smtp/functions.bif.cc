// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smtp/functions.bif (plugin mode).


#include "functions.bif.h"


#line 2 "functions.bif"

#include "analyzer/protocol/smtp/SMTP.h"

#line 11 "functions.bif"
Val* BifFunc::bro_skip_smtp_data(Frame* frame, val_list* BiF_ARGS)
	
#line 12 "functions.bif"
{
	if ( BiF_ARGS->length() != 1 )
		{
		reporter->Error("skip_smtp_data() takes exactly 1 argument(s)");
		return 0;
		}
	Connection* c = (Connection*) ((*BiF_ARGS)[0]->AsRecordVal()->GetOrigin());

#line 12 "functions.bif"

	analyzer::Analyzer* sa = c->FindAnalyzer("SMTP");
	if ( sa )
		static_cast<analyzer::smtp::SMTP_Analyzer*>(sa)->SkipData();
	return 0;
	} // end of BifFunc::bro_skip_smtp_data

#line 17 "functions.bif"
