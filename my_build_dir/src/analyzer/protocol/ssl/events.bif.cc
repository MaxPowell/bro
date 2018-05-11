// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/ssl/events.bif (plugin mode).


#include "events.bif.h"

EventHandlerPtr ssl_client_hello; 
void BifEvent::generate_ssl_client_hello(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t version, double possible_ts, StringVal* client_random, StringVal* session_id, Val* ciphers)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_client_hello is NULL, which should happen *before*
	// BifEvent::generate_ssl_client_hello is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(version, TYPE_COUNT));
	vl->append(new Val(possible_ts, TYPE_TIME));
	vl->append(client_random);
	vl->append(session_id);
	vl->append(ciphers);

	mgr.QueueEvent(::ssl_client_hello, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_server_hello; 
void BifEvent::generate_ssl_server_hello(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t version, double possible_ts, StringVal* server_random, StringVal* session_id, bro_uint_t cipher, bro_uint_t comp_method)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_server_hello is NULL, which should happen *before*
	// BifEvent::generate_ssl_server_hello is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(version, TYPE_COUNT));
	vl->append(new Val(possible_ts, TYPE_TIME));
	vl->append(server_random);
	vl->append(session_id);
	vl->append(new Val(cipher, TYPE_COUNT));
	vl->append(new Val(comp_method, TYPE_COUNT));

	mgr.QueueEvent(::ssl_server_hello, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_extension; 
void BifEvent::generate_ssl_extension(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t code, StringVal* val)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_extension is NULL, which should happen *before*
	// BifEvent::generate_ssl_extension is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(new Val(code, TYPE_COUNT));
	vl->append(val);

	mgr.QueueEvent(::ssl_extension, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_extension_elliptic_curves; 
void BifEvent::generate_ssl_extension_elliptic_curves(analyzer::Analyzer* analyzer, Connection* c, int is_orig, Val* curves)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_extension_elliptic_curves is NULL, which should happen *before*
	// BifEvent::generate_ssl_extension_elliptic_curves is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(curves);

	mgr.QueueEvent(::ssl_extension_elliptic_curves, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_extension_ec_point_formats; 
void BifEvent::generate_ssl_extension_ec_point_formats(analyzer::Analyzer* analyzer, Connection* c, int is_orig, Val* point_formats)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_extension_ec_point_formats is NULL, which should happen *before*
	// BifEvent::generate_ssl_extension_ec_point_formats is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(point_formats);

	mgr.QueueEvent(::ssl_extension_ec_point_formats, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_extension_signature_algorithm; 
void BifEvent::generate_ssl_extension_signature_algorithm(analyzer::Analyzer* analyzer, Connection* c, int is_orig, Val* signature_algorithms)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_extension_signature_algorithm is NULL, which should happen *before*
	// BifEvent::generate_ssl_extension_signature_algorithm is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(signature_algorithms);

	mgr.QueueEvent(::ssl_extension_signature_algorithm, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_extension_key_share; 
void BifEvent::generate_ssl_extension_key_share(analyzer::Analyzer* analyzer, Connection* c, int is_orig, Val* curves)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_extension_key_share is NULL, which should happen *before*
	// BifEvent::generate_ssl_extension_key_share is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(curves);

	mgr.QueueEvent(::ssl_extension_key_share, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_server_curve; 
 void BifEvent::generate_ssl_server_curve(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t curve)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_server_curve is NULL, which should happen *before*
	// BifEvent::generate_ssl_server_curve is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(curve, TYPE_COUNT));

	mgr.QueueEvent(::ssl_server_curve, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_ecdh_server_params; 
void BifEvent::generate_ssl_ecdh_server_params(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t curve, StringVal* point)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_ecdh_server_params is NULL, which should happen *before*
	// BifEvent::generate_ssl_ecdh_server_params is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(curve, TYPE_COUNT));
	vl->append(point);

	mgr.QueueEvent(::ssl_ecdh_server_params, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_dh_server_params; 
void BifEvent::generate_ssl_dh_server_params(analyzer::Analyzer* analyzer, Connection* c, StringVal* p, StringVal* q, StringVal* Ys)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_dh_server_params is NULL, which should happen *before*
	// BifEvent::generate_ssl_dh_server_params is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(p);
	vl->append(q);
	vl->append(Ys);

	mgr.QueueEvent(::ssl_dh_server_params, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_server_signature; 
void BifEvent::generate_ssl_server_signature(analyzer::Analyzer* analyzer, Connection* c, Val* signature_and_hashalgorithm, StringVal* signature)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_server_signature is NULL, which should happen *before*
	// BifEvent::generate_ssl_server_signature is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(signature_and_hashalgorithm);
	vl->append(signature);

	mgr.QueueEvent(::ssl_server_signature, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_ecdh_client_params; 
void BifEvent::generate_ssl_ecdh_client_params(analyzer::Analyzer* analyzer, Connection* c, StringVal* point)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_ecdh_client_params is NULL, which should happen *before*
	// BifEvent::generate_ssl_ecdh_client_params is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(point);

	mgr.QueueEvent(::ssl_ecdh_client_params, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_dh_client_params; 
void BifEvent::generate_ssl_dh_client_params(analyzer::Analyzer* analyzer, Connection* c, StringVal* Yc)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_dh_client_params is NULL, which should happen *before*
	// BifEvent::generate_ssl_dh_client_params is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(Yc);

	mgr.QueueEvent(::ssl_dh_client_params, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_rsa_client_pms; 
void BifEvent::generate_ssl_rsa_client_pms(analyzer::Analyzer* analyzer, Connection* c, StringVal* pms)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_rsa_client_pms is NULL, which should happen *before*
	// BifEvent::generate_ssl_rsa_client_pms is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(pms);

	mgr.QueueEvent(::ssl_rsa_client_pms, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_extension_application_layer_protocol_negotiation; 
void BifEvent::generate_ssl_extension_application_layer_protocol_negotiation(analyzer::Analyzer* analyzer, Connection* c, int is_orig, Val* protocols)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_extension_application_layer_protocol_negotiation is NULL, which should happen *before*
	// BifEvent::generate_ssl_extension_application_layer_protocol_negotiation is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(protocols);

	mgr.QueueEvent(::ssl_extension_application_layer_protocol_negotiation, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_extension_server_name; 
void BifEvent::generate_ssl_extension_server_name(analyzer::Analyzer* analyzer, Connection* c, int is_orig, Val* names)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_extension_server_name is NULL, which should happen *before*
	// BifEvent::generate_ssl_extension_server_name is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(names);

	mgr.QueueEvent(::ssl_extension_server_name, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_extension_signed_certificate_timestamp; 
void BifEvent::generate_ssl_extension_signed_certificate_timestamp(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t version, StringVal* logid, bro_uint_t timestamp, Val* signature_and_hashalgorithm, StringVal* signature)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_extension_signed_certificate_timestamp is NULL, which should happen *before*
	// BifEvent::generate_ssl_extension_signed_certificate_timestamp is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(new Val(version, TYPE_COUNT));
	vl->append(logid);
	vl->append(new Val(timestamp, TYPE_COUNT));
	vl->append(signature_and_hashalgorithm);
	vl->append(signature);

	mgr.QueueEvent(::ssl_extension_signed_certificate_timestamp, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_extension_supported_versions; 
void BifEvent::generate_ssl_extension_supported_versions(analyzer::Analyzer* analyzer, Connection* c, int is_orig, Val* versions)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_extension_supported_versions is NULL, which should happen *before*
	// BifEvent::generate_ssl_extension_supported_versions is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(versions);

	mgr.QueueEvent(::ssl_extension_supported_versions, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_extension_psk_key_exchange_modes; 
void BifEvent::generate_ssl_extension_psk_key_exchange_modes(analyzer::Analyzer* analyzer, Connection* c, int is_orig, Val* modes)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_extension_psk_key_exchange_modes is NULL, which should happen *before*
	// BifEvent::generate_ssl_extension_psk_key_exchange_modes is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(modes);

	mgr.QueueEvent(::ssl_extension_psk_key_exchange_modes, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_established; 
void BifEvent::generate_ssl_established(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_established is NULL, which should happen *before*
	// BifEvent::generate_ssl_established is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::ssl_established, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_alert; 
void BifEvent::generate_ssl_alert(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t level, bro_uint_t desc)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_alert is NULL, which should happen *before*
	// BifEvent::generate_ssl_alert is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(new Val(level, TYPE_COUNT));
	vl->append(new Val(desc, TYPE_COUNT));

	mgr.QueueEvent(::ssl_alert, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_session_ticket_handshake; 
void BifEvent::generate_ssl_session_ticket_handshake(analyzer::Analyzer* analyzer, Connection* c, bro_uint_t ticket_lifetime_hint, StringVal* ticket)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_session_ticket_handshake is NULL, which should happen *before*
	// BifEvent::generate_ssl_session_ticket_handshake is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(ticket_lifetime_hint, TYPE_COUNT));
	vl->append(ticket);

	mgr.QueueEvent(::ssl_session_ticket_handshake, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_heartbeat; 
void BifEvent::generate_ssl_heartbeat(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t length, bro_uint_t heartbeat_type, bro_uint_t payload_length, StringVal* payload)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_heartbeat is NULL, which should happen *before*
	// BifEvent::generate_ssl_heartbeat is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(new Val(length, TYPE_COUNT));
	vl->append(new Val(heartbeat_type, TYPE_COUNT));
	vl->append(new Val(payload_length, TYPE_COUNT));
	vl->append(payload);

	mgr.QueueEvent(::ssl_heartbeat, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_application_data; 
void BifEvent::generate_ssl_application_data(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t length)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_application_data is NULL, which should happen *before*
	// BifEvent::generate_ssl_application_data is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(new Val(length, TYPE_COUNT));

	mgr.QueueEvent(::ssl_application_data, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_encrypted_data; 
void BifEvent::generate_ssl_encrypted_data(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t content_type, bro_uint_t length)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_encrypted_data is NULL, which should happen *before*
	// BifEvent::generate_ssl_encrypted_data is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(new Val(content_type, TYPE_COUNT));
	vl->append(new Val(length, TYPE_COUNT));

	mgr.QueueEvent(::ssl_encrypted_data, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_stapled_ocsp; 
void BifEvent::generate_ssl_stapled_ocsp(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* response)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_stapled_ocsp is NULL, which should happen *before*
	// BifEvent::generate_ssl_stapled_ocsp is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(response);

	mgr.QueueEvent(::ssl_stapled_ocsp, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_handshake_message; 
void BifEvent::generate_ssl_handshake_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t msg_type, bro_uint_t length)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_handshake_message is NULL, which should happen *before*
	// BifEvent::generate_ssl_handshake_message is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(new Val(msg_type, TYPE_COUNT));
	vl->append(new Val(length, TYPE_COUNT));

	mgr.QueueEvent(::ssl_handshake_message, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr ssl_change_cipher_spec; 
void BifEvent::generate_ssl_change_cipher_spec(analyzer::Analyzer* analyzer, Connection* c, int is_orig)
	{
	// Note that it is intentional that here we do not
	// check if ::ssl_change_cipher_spec is NULL, which should happen *before*
	// BifEvent::generate_ssl_change_cipher_spec is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));

	mgr.QueueEvent(::ssl_change_cipher_spec, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
