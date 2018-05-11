// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smb/events.bif (plugin mode).


#include "events.bif.h"

EventHandlerPtr smb_pipe_connect_heuristic; 
void BifEvent::generate_smb_pipe_connect_heuristic(analyzer::Analyzer* analyzer, Connection* c)
	{
	// Note that it is intentional that here we do not
	// check if ::smb_pipe_connect_heuristic is NULL, which should happen *before*
	// BifEvent::generate_smb_pipe_connect_heuristic is called to avoid unnecessary Val
	// allocation.

	val_list* vl = new val_list;

	vl->append(c->BuildConnVal());

	mgr.QueueEvent(::smb_pipe_connect_heuristic, vl, SOURCE_LOCAL, analyzer->GetID(), timer_mgr, c);
	} // event generation
