// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smb/smb1_com_tree_connect_andx.bif (plugin mode).


#include "smb1_com_tree_connect_andx.bif.h"

EventHandlerPtr smb1_tree_connect_andx_request; 
void BifEvent::generate_smb1_tree_connect_andx_request(analyzer::Analyzer* analyzer, Connection* c, Val* hdr, StringVal* path, StringVal* service)
	{
	// Note that it is intentional that here we do not
	// check if ::smb1_tree_connect_andx_request is NULL, which should happen *before*
	// BifEvent::generate_smb1_tree_connect_andx_request is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(hdr);
	vl->append(path);
	vl->append(service);

	mgr.QueueEvent(::smb1_tree_connect_andx_request, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr smb1_tree_connect_andx_response; 
void BifEvent::generate_smb1_tree_connect_andx_response(analyzer::Analyzer* analyzer, Connection* c, Val* hdr, StringVal* service, StringVal* native_file_system)
	{
	// Note that it is intentional that here we do not
	// check if ::smb1_tree_connect_andx_response is NULL, which should happen *before*
	// BifEvent::generate_smb1_tree_connect_andx_response is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(hdr);
	vl->append(service);
	vl->append(native_file_system);

	mgr.QueueEvent(::smb1_tree_connect_andx_response, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
