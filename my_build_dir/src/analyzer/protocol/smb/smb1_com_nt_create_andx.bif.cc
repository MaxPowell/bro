// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smb/smb1_com_nt_create_andx.bif (plugin mode).


#include "smb1_com_nt_create_andx.bif.h"

EventHandlerPtr smb1_nt_create_andx_request; 
void BifEvent::generate_smb1_nt_create_andx_request(analyzer::Analyzer* analyzer, Connection* c, Val* hdr, StringVal* file_name)
	{
	// Note that it is intentional that here we do not
	// check if ::smb1_nt_create_andx_request is NULL, which should happen *before*
	// BifEvent::generate_smb1_nt_create_andx_request is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(hdr);
	vl->append(file_name);

	mgr.QueueEvent(::smb1_nt_create_andx_request, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr smb1_nt_create_andx_response; 
void BifEvent::generate_smb1_nt_create_andx_response(analyzer::Analyzer* analyzer, Connection* c, Val* hdr, bro_uint_t file_id, bro_uint_t file_size, Val* times)
	{
	// Note that it is intentional that here we do not
	// check if ::smb1_nt_create_andx_response is NULL, which should happen *before*
	// BifEvent::generate_smb1_nt_create_andx_response is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(hdr);
	vl->append(new Val(file_id, TYPE_COUNT));
	vl->append(new Val(file_size, TYPE_COUNT));
	vl->append(times);

	mgr.QueueEvent(::smb1_nt_create_andx_response, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
