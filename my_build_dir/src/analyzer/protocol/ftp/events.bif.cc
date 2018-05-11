// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/ftp/events.bif (plugin mode).


#include "events.bif.h"

EventHandlerPtr ftp_request; 
void BifEvent::generate_ftp_request(analyzer::Analyzer* analyzer, Connection* c, StringVal* command, StringVal* arg)
	{
	// Note that it is intentional that here we do not
	// check if ::ftp_request is NULL, which should happen *before*
	// BifEvent::generate_ftp_request is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(command);
	vl->append(arg);

	mgr.QueueEvent(::ftp_request, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ftp_reply; 
void BifEvent::generate_ftp_reply(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t code, StringVal* msg, int cont_resp)
	{
	// Note that it is intentional that here we do not
	// check if ::ftp_reply is NULL, which should happen *before*
	// BifEvent::generate_ftp_reply is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(code, TYPE_COUNT));
	vl->append(msg);
	vl->append(new Val(cont_resp, TYPE_BOOL));

	mgr.QueueEvent(::ftp_reply, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
