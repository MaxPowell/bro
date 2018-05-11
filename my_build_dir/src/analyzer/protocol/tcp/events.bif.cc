// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/tcp/events.bif (plugin mode).


#include "events.bif.h"

EventHandlerPtr new_connection_contents; 
void BifEvent::generate_new_connection_contents(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::new_connection_contents is NULL, which should happen *before*
	// BifEvent::generate_new_connection_contents is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::new_connection_contents, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr connection_attempt; 
void BifEvent::generate_connection_attempt(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::connection_attempt is NULL, which should happen *before*
	// BifEvent::generate_connection_attempt is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::connection_attempt, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr connection_established; 
void BifEvent::generate_connection_established(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::connection_established is NULL, which should happen *before*
	// BifEvent::generate_connection_established is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::connection_established, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr partial_connection; 
void BifEvent::generate_partial_connection(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::partial_connection is NULL, which should happen *before*
	// BifEvent::generate_partial_connection is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::partial_connection, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr connection_partial_close; 
void BifEvent::generate_connection_partial_close(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::connection_partial_close is NULL, which should happen *before*
	// BifEvent::generate_connection_partial_close is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::connection_partial_close, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr connection_finished; 
void BifEvent::generate_connection_finished(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::connection_finished is NULL, which should happen *before*
	// BifEvent::generate_connection_finished is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::connection_finished, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr connection_half_finished; 
void BifEvent::generate_connection_half_finished(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::connection_half_finished is NULL, which should happen *before*
	// BifEvent::generate_connection_half_finished is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::connection_half_finished, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr connection_rejected; 
void BifEvent::generate_connection_rejected(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::connection_rejected is NULL, which should happen *before*
	// BifEvent::generate_connection_rejected is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::connection_rejected, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr connection_reset; 
void BifEvent::generate_connection_reset(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::connection_reset is NULL, which should happen *before*
	// BifEvent::generate_connection_reset is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::connection_reset, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr connection_pending; 
void BifEvent::generate_connection_pending(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::connection_pending is NULL, which should happen *before*
	// BifEvent::generate_connection_pending is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::connection_pending, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr connection_SYN_packet; 
void BifEvent::generate_connection_SYN_packet(analyzer::Analyzer* analyzer, Connection* c, Val* pkt)
	{
	// Note that it is intentional that here we do not
	// check if ::connection_SYN_packet is NULL, which should happen *before*
	// BifEvent::generate_connection_SYN_packet is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(pkt);

	mgr.QueueEvent(::connection_SYN_packet, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr connection_first_ACK; 
void BifEvent::generate_connection_first_ACK(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::connection_first_ACK is NULL, which should happen *before*
	// BifEvent::generate_connection_first_ACK is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::connection_first_ACK, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr connection_EOF; 
void BifEvent::generate_connection_EOF(analyzer::Analyzer* analyzer, Connection* c, int is_orig)
	{
	// Note that it is intentional that here we do not
	// check if ::connection_EOF is NULL, which should happen *before*
	// BifEvent::generate_connection_EOF is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));

	mgr.QueueEvent(::connection_EOF, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr tcp_packet; 
void BifEvent::generate_tcp_packet(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* flags, bro_uint_t seq, bro_uint_t ack, bro_uint_t len, StringVal* payload)
	{
	// Note that it is intentional that here we do not
	// check if ::tcp_packet is NULL, which should happen *before*
	// BifEvent::generate_tcp_packet is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(flags);
	vl->append(new Val(seq, TYPE_COUNT));
	vl->append(new Val(ack, TYPE_COUNT));
	vl->append(new Val(len, TYPE_COUNT));
	vl->append(payload);

	mgr.QueueEvent(::tcp_packet, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr tcp_option; 
void BifEvent::generate_tcp_option(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t opt, bro_uint_t optlen)
	{
	// Note that it is intentional that here we do not
	// check if ::tcp_option is NULL, which should happen *before*
	// BifEvent::generate_tcp_option is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(new Val(opt, TYPE_COUNT));
	vl->append(new Val(optlen, TYPE_COUNT));

	mgr.QueueEvent(::tcp_option, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr tcp_contents; 
void BifEvent::generate_tcp_contents(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t seq, StringVal* contents)
	{
	// Note that it is intentional that here we do not
	// check if ::tcp_contents is NULL, which should happen *before*
	// BifEvent::generate_tcp_contents is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(new Val(seq, TYPE_COUNT));
	vl->append(contents);

	mgr.QueueEvent(::tcp_contents, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr tcp_rexmit; 
void BifEvent::generate_tcp_rexmit(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t seq, bro_uint_t len, bro_uint_t data_in_flight, bro_uint_t window)
	{
	// Note that it is intentional that here we do not
	// check if ::tcp_rexmit is NULL, which should happen *before*
	// BifEvent::generate_tcp_rexmit is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(new Val(seq, TYPE_COUNT));
	vl->append(new Val(len, TYPE_COUNT));
	vl->append(new Val(data_in_flight, TYPE_COUNT));
	vl->append(new Val(window, TYPE_COUNT));

	mgr.QueueEvent(::tcp_rexmit, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr contents_file_write_failure; 
void BifEvent::generate_contents_file_write_failure(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* msg)
	{
	// Note that it is intentional that here we do not
	// check if ::contents_file_write_failure is NULL, which should happen *before*
	// BifEvent::generate_contents_file_write_failure is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(new Val(is_orig, TYPE_BOOL));
	vl->append(msg);

	mgr.QueueEvent(::contents_file_write_failure, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
