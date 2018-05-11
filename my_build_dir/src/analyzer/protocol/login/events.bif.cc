// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/login/events.bif (plugin mode).


#include "events.bif.h"

EventHandlerPtr rsh_request; 
void BifEvent::generate_rsh_request(analyzer::Analyzer* analyzer, Connection* c, StringVal* client_user, StringVal* server_user, StringVal* line, int new_session)
	{
	// Note that it is intentional that here we do not
	// check if ::rsh_request is NULL, which should happen *before*
	// BifEvent::generate_rsh_request is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(client_user);
	vl->append(server_user);
	vl->append(line);
	vl->append(new Val(new_session, TYPE_BOOL));

	mgr.QueueEvent(::rsh_request, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr rsh_reply; 
void BifEvent::generate_rsh_reply(analyzer::Analyzer* analyzer, Connection* c, StringVal* client_user, StringVal* server_user, StringVal* line)
	{
	// Note that it is intentional that here we do not
	// check if ::rsh_reply is NULL, which should happen *before*
	// BifEvent::generate_rsh_reply is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(client_user);
	vl->append(server_user);
	vl->append(line);

	mgr.QueueEvent(::rsh_reply, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr login_failure; 
void BifEvent::generate_login_failure(analyzer::Analyzer* analyzer, Connection* c, StringVal* user, StringVal* client_user, StringVal* password, StringVal* line)
	{
	// Note that it is intentional that here we do not
	// check if ::login_failure is NULL, which should happen *before*
	// BifEvent::generate_login_failure is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(user);
	vl->append(client_user);
	vl->append(password);
	vl->append(line);

	mgr.QueueEvent(::login_failure, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr login_success; 
void BifEvent::generate_login_success(analyzer::Analyzer* analyzer, Connection* c, StringVal* user, StringVal* client_user, StringVal* password, StringVal* line)
	{
	// Note that it is intentional that here we do not
	// check if ::login_success is NULL, which should happen *before*
	// BifEvent::generate_login_success is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(user);
	vl->append(client_user);
	vl->append(password);
	vl->append(line);

	mgr.QueueEvent(::login_success, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr login_input_line; 
void BifEvent::generate_login_input_line(analyzer::Analyzer* analyzer, Connection* c, StringVal* line)
	{
	// Note that it is intentional that here we do not
	// check if ::login_input_line is NULL, which should happen *before*
	// BifEvent::generate_login_input_line is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(line);

	mgr.QueueEvent(::login_input_line, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr login_output_line; 
void BifEvent::generate_login_output_line(analyzer::Analyzer* analyzer, Connection* c, StringVal* line)
	{
	// Note that it is intentional that here we do not
	// check if ::login_output_line is NULL, which should happen *before*
	// BifEvent::generate_login_output_line is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(line);

	mgr.QueueEvent(::login_output_line, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr login_confused; 
void BifEvent::generate_login_confused(analyzer::Analyzer* analyzer, Connection* c, StringVal* msg, StringVal* line)
	{
	// Note that it is intentional that here we do not
	// check if ::login_confused is NULL, which should happen *before*
	// BifEvent::generate_login_confused is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(msg);
	vl->append(line);

	mgr.QueueEvent(::login_confused, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr login_confused_text; 
void BifEvent::generate_login_confused_text(analyzer::Analyzer* analyzer, Connection* c, StringVal* line)
	{
	// Note that it is intentional that here we do not
	// check if ::login_confused_text is NULL, which should happen *before*
	// BifEvent::generate_login_confused_text is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(line);

	mgr.QueueEvent(::login_confused_text, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr login_terminal; 
void BifEvent::generate_login_terminal(analyzer::Analyzer* analyzer, Connection* c, StringVal* terminal)
	{
	// Note that it is intentional that here we do not
	// check if ::login_terminal is NULL, which should happen *before*
	// BifEvent::generate_login_terminal is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(terminal);

	mgr.QueueEvent(::login_terminal, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr login_display; 
void BifEvent::generate_login_display(analyzer::Analyzer* analyzer, Connection* c, StringVal* display)
	{
	// Note that it is intentional that here we do not
	// check if ::login_display is NULL, which should happen *before*
	// BifEvent::generate_login_display is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(display);

	mgr.QueueEvent(::login_display, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr authentication_accepted; 
void BifEvent::generate_authentication_accepted(analyzer::Analyzer* analyzer, StringVal* name, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::authentication_accepted is NULL, which should happen *before*
	// BifEvent::generate_authentication_accepted is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(name);
	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::authentication_accepted, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr authentication_rejected; 
void BifEvent::generate_authentication_rejected(analyzer::Analyzer* analyzer, StringVal* name, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::authentication_rejected is NULL, which should happen *before*
	// BifEvent::generate_authentication_rejected is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(name);
	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::authentication_rejected, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr authentication_skipped; 
void BifEvent::generate_authentication_skipped(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::authentication_skipped is NULL, which should happen *before*
	// BifEvent::generate_authentication_skipped is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::authentication_skipped, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr login_prompt; 
void BifEvent::generate_login_prompt(analyzer::Analyzer* analyzer, Connection* c, StringVal* prompt)
	{
	// Note that it is intentional that here we do not
	// check if ::login_prompt is NULL, which should happen *before*
	// BifEvent::generate_login_prompt is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());
	vl->append(prompt);

	mgr.QueueEvent(::login_prompt, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr activating_encryption; 
void BifEvent::generate_activating_encryption(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::activating_encryption is NULL, which should happen *before*
	// BifEvent::generate_activating_encryption is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::activating_encryption, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr inconsistent_option; 
void BifEvent::generate_inconsistent_option(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::inconsistent_option is NULL, which should happen *before*
	// BifEvent::generate_inconsistent_option is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::inconsistent_option, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr bad_option; 
void BifEvent::generate_bad_option(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::bad_option is NULL, which should happen *before*
	// BifEvent::generate_bad_option is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::bad_option, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
EventHandlerPtr bad_option_termination; 
void BifEvent::generate_bad_option_termination(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::bad_option_termination is NULL, which should happen *before*
	// BifEvent::generate_bad_option_termination is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::bad_option_termination, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
