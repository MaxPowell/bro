// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/socks/events.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "events.bif.h"

namespace plugin { namespace Bro_SOCKS {

void __bif_events_init(plugin::Plugin* plugin)
	{
	::socks_request = internal_handler("socks_request");
	plugin->AddBifItem("socks_request", plugin::BifItem::EVENT);
	::socks_reply = internal_handler("socks_reply");
	plugin->AddBifItem("socks_reply", plugin::BifItem::EVENT);
	::socks_login_userpass_request = internal_handler("socks_login_userpass_request");
	plugin->AddBifItem("socks_login_userpass_request", plugin::BifItem::EVENT);
	::socks_login_userpass_reply = internal_handler("socks_login_userpass_reply");
	plugin->AddBifItem("socks_login_userpass_reply", plugin::BifItem::EVENT);

	}
} }


