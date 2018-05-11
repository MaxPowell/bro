// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smb/smb1_com_close.bif (plugin mode).


#include "smb1_com_close.bif.h"

EventHandlerPtr smb1_close_request; 
void BifEvent::generate_smb1_close_request(analyzer::Analyzer* analyzer, Connection* c, Val* hdr, bro_uint_t file_id)
	{
	// Note that it is intentional that here we do not
	// check if ::smb1_close_request is NULL, which should happen *before*
	// BifEvent::generate_smb1_close_request is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(hdr);
	vl->append(new Val(file_id, TYPE_COUNT));

	mgr.QueueEvent(::smb1_close_request, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
