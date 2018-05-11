// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/rdp/events.bif (plugin mode).


#include "events.bif.h"

EventHandlerPtr rdp_connect_request; 
void BifEvent::generate_rdp_connect_request(analyzer::Analyzer* analyzer, Connection* c, StringVal* cookie)
	{
	// Note that it is intentional that here we do not
	// check if ::rdp_connect_request is NULL, which should happen *before*
	// BifEvent::generate_rdp_connect_request is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(cookie);

	mgr.QueueEvent(::rdp_connect_request, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr rdp_negotiation_response; 
void BifEvent::generate_rdp_negotiation_response(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t security_protocol)
	{
	// Note that it is intentional that here we do not
	// check if ::rdp_negotiation_response is NULL, which should happen *before*
	// BifEvent::generate_rdp_negotiation_response is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(security_protocol, TYPE_COUNT));

	mgr.QueueEvent(::rdp_negotiation_response, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr rdp_negotiation_failure; 
void BifEvent::generate_rdp_negotiation_failure(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t failure_code)
	{
	// Note that it is intentional that here we do not
	// check if ::rdp_negotiation_failure is NULL, which should happen *before*
	// BifEvent::generate_rdp_negotiation_failure is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(failure_code, TYPE_COUNT));

	mgr.QueueEvent(::rdp_negotiation_failure, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr rdp_client_core_data; 
void BifEvent::generate_rdp_client_core_data(analyzer::Analyzer* analyzer, Connection* c, Val* data)
	{
	// Note that it is intentional that here we do not
	// check if ::rdp_client_core_data is NULL, which should happen *before*
	// BifEvent::generate_rdp_client_core_data is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(data);

	mgr.QueueEvent(::rdp_client_core_data, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr rdp_gcc_server_create_response; 
void BifEvent::generate_rdp_gcc_server_create_response(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t result)
	{
	// Note that it is intentional that here we do not
	// check if ::rdp_gcc_server_create_response is NULL, which should happen *before*
	// BifEvent::generate_rdp_gcc_server_create_response is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(result, TYPE_COUNT));

	mgr.QueueEvent(::rdp_gcc_server_create_response, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr rdp_server_security; 
void BifEvent::generate_rdp_server_security(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t encryption_method, bro_uint_t encryption_level)
	{
	// Note that it is intentional that here we do not
	// check if ::rdp_server_security is NULL, which should happen *before*
	// BifEvent::generate_rdp_server_security is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(encryption_method, TYPE_COUNT));
	vl->append(new Val(encryption_level, TYPE_COUNT));

	mgr.QueueEvent(::rdp_server_security, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr rdp_server_certificate; 
void BifEvent::generate_rdp_server_certificate(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t cert_type, int permanently_issued)
	{
	// Note that it is intentional that here we do not
	// check if ::rdp_server_certificate is NULL, which should happen *before*
	// BifEvent::generate_rdp_server_certificate is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(cert_type, TYPE_COUNT));
	vl->append(new Val(permanently_issued, TYPE_BOOL));

	mgr.QueueEvent(::rdp_server_certificate, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr rdp_begin_encryption; 
void BifEvent::generate_rdp_begin_encryption(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t security_protocol)
	{
	// Note that it is intentional that here we do not
	// check if ::rdp_begin_encryption is NULL, which should happen *before*
	// BifEvent::generate_rdp_begin_encryption is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(security_protocol, TYPE_COUNT));

	mgr.QueueEvent(::rdp_begin_encryption, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
