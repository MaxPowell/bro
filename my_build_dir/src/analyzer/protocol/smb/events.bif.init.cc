// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smb/events.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "events.bif.h"

namespace plugin { namespace Bro_SMB {

void __bif_events_init(plugin::Plugin* plugin)
	{
	::smb_pipe_connect_heuristic = internal_handler("smb_pipe_connect_heuristic");
	plugin->AddBifItem("smb_pipe_connect_heuristic", plugin::BifItem::EVENT);

	}
} }


