// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smb/smb2_com_tree_connect.bif (plugin mode).


#include "smb2_com_tree_connect.bif.h"

EventHandlerPtr smb2_tree_connect_request; 
void BifEvent::generate_smb2_tree_connect_request(analyzer::Analyzer* analyzer, Connection* c, Val* hdr, StringVal* path)
	{
	// Note that it is intentional that here we do not
	// check if ::smb2_tree_connect_request is NULL, which should happen *before*
	// BifEvent::generate_smb2_tree_connect_request is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(hdr);
	vl->append(path);

	mgr.QueueEvent(::smb2_tree_connect_request, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr smb2_tree_connect_response; 
void BifEvent::generate_smb2_tree_connect_response(analyzer::Analyzer* analyzer, Connection* c, Val* hdr, Val* response)
	{
	// Note that it is intentional that here we do not
	// check if ::smb2_tree_connect_response is NULL, which should happen *before*
	// BifEvent::generate_smb2_tree_connect_response is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(hdr);
	vl->append(response);

	mgr.QueueEvent(::smb2_tree_connect_response, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
namespace BifType { namespace Record{ namespace SMB2 {  RecordType * TreeConnectResponse;  } } }
