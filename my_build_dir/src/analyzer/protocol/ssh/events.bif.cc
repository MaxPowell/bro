// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/ssh/events.bif (plugin mode).


#include "events.bif.h"

EventHandlerPtr ssh_server_version; 
void BifEvent::generate_ssh_server_version(analyzer::Analyzer* analyzer, Connection* c, StringVal* version)
	{
	// Note that it is intentional that here we do not
	// check if ::ssh_server_version is NULL, which should happen *before*
	// BifEvent::generate_ssh_server_version is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(version);

	mgr.QueueEvent(::ssh_server_version, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssh_client_version; 
void BifEvent::generate_ssh_client_version(analyzer::Analyzer* analyzer, Connection* c, StringVal* version)
	{
	// Note that it is intentional that here we do not
	// check if ::ssh_client_version is NULL, which should happen *before*
	// BifEvent::generate_ssh_client_version is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(version);

	mgr.QueueEvent(::ssh_client_version, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssh_auth_successful; 
void BifEvent::generate_ssh_auth_successful(analyzer::Analyzer* analyzer, Connection* c, int auth_method_none)
	{
	// Note that it is intentional that here we do not
	// check if ::ssh_auth_successful is NULL, which should happen *before*
	// BifEvent::generate_ssh_auth_successful is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(auth_method_none, TYPE_BOOL));

	mgr.QueueEvent(::ssh_auth_successful, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssh_auth_attempted; 
void BifEvent::generate_ssh_auth_attempted(analyzer::Analyzer* analyzer, Connection* c, int authenticated)
	{
	// Note that it is intentional that here we do not
	// check if ::ssh_auth_attempted is NULL, which should happen *before*
	// BifEvent::generate_ssh_auth_attempted is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(authenticated, TYPE_BOOL));

	mgr.QueueEvent(::ssh_auth_attempted, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssh_capabilities; 
void BifEvent::generate_ssh_capabilities(analyzer::Analyzer* analyzer, Connection* c, StringVal* cookie, Val* capabilities)
	{
	// Note that it is intentional that here we do not
	// check if ::ssh_capabilities is NULL, which should happen *before*
	// BifEvent::generate_ssh_capabilities is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(cookie);
	vl->append(capabilities);

	mgr.QueueEvent(::ssh_capabilities, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssh2_server_host_key; 
void BifEvent::generate_ssh2_server_host_key(analyzer::Analyzer* analyzer, Connection* c, StringVal* key)
	{
	// Note that it is intentional that here we do not
	// check if ::ssh2_server_host_key is NULL, which should happen *before*
	// BifEvent::generate_ssh2_server_host_key is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(key);

	mgr.QueueEvent(::ssh2_server_host_key, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssh1_server_host_key; 
void BifEvent::generate_ssh1_server_host_key(analyzer::Analyzer* analyzer, Connection* c, StringVal* p, StringVal* e)
	{
	// Note that it is intentional that here we do not
	// check if ::ssh1_server_host_key is NULL, which should happen *before*
	// BifEvent::generate_ssh1_server_host_key is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(p);
	vl->append(e);

	mgr.QueueEvent(::ssh1_server_host_key, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssh_encrypted_packet; 
void BifEvent::generate_ssh_encrypted_packet(analyzer::Analyzer* analyzer, Connection* c, int orig, bro_uint_t len)
	{
	// Note that it is intentional that here we do not
	// check if ::ssh_encrypted_packet is NULL, which should happen *before*
	// BifEvent::generate_ssh_encrypted_packet is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(orig, TYPE_BOOL));
	vl->append(new Val(len, TYPE_COUNT));

	mgr.QueueEvent(::ssh_encrypted_packet, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssh2_dh_server_params; 
void BifEvent::generate_ssh2_dh_server_params(analyzer::Analyzer* analyzer, Connection* c, StringVal* p, StringVal* q)
	{
	// Note that it is intentional that here we do not
	// check if ::ssh2_dh_server_params is NULL, which should happen *before*
	// BifEvent::generate_ssh2_dh_server_params is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(p);
	vl->append(q);

	mgr.QueueEvent(::ssh2_dh_server_params, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssh2_gss_error; 
void BifEvent::generate_ssh2_gss_error(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t major_status, bro_uint_t minor_status, StringVal* err_msg)
	{
	// Note that it is intentional that here we do not
	// check if ::ssh2_gss_error is NULL, which should happen *before*
	// BifEvent::generate_ssh2_gss_error is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(major_status, TYPE_COUNT));
	vl->append(new Val(minor_status, TYPE_COUNT));
	vl->append(err_msg);

	mgr.QueueEvent(::ssh2_gss_error, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssh2_ecc_key; 
void BifEvent::generate_ssh2_ecc_key(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* q)
	{
	// Note that it is intentional that here we do not
	// check if ::ssh2_ecc_key is NULL, which should happen *before*
	// BifEvent::generate_ssh2_ecc_key is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(q);

	mgr.QueueEvent(::ssh2_ecc_key, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
