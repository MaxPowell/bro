// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/netbios/events.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "events.bif.h"

namespace plugin { namespace Bro_NetBIOS {

void __bif_events_init(plugin::Plugin* plugin)
	{
	::netbios_session_message = internal_handler("netbios_session_message");
	plugin->AddBifItem("netbios_session_message", plugin::BifItem::EVENT);
	::netbios_session_request = internal_handler("netbios_session_request");
	plugin->AddBifItem("netbios_session_request", plugin::BifItem::EVENT);
	::netbios_session_accepted = internal_handler("netbios_session_accepted");
	plugin->AddBifItem("netbios_session_accepted", plugin::BifItem::EVENT);
	::netbios_session_rejected = internal_handler("netbios_session_rejected");
	plugin->AddBifItem("netbios_session_rejected", plugin::BifItem::EVENT);
	::netbios_session_raw_message = internal_handler("netbios_session_raw_message");
	plugin->AddBifItem("netbios_session_raw_message", plugin::BifItem::EVENT);
	::netbios_session_ret_arg_resp = internal_handler("netbios_session_ret_arg_resp");
	plugin->AddBifItem("netbios_session_ret_arg_resp", plugin::BifItem::EVENT);
	::netbios_session_keepalive = internal_handler("netbios_session_keepalive");
	plugin->AddBifItem("netbios_session_keepalive", plugin::BifItem::EVENT);

	}
} }


