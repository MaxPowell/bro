// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/ntlm/types.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "types.bif.h"

namespace plugin { namespace Bro_NTLM {

void __bif_types_init(plugin::Plugin* plugin)
	{
	BifType::Record::NTLM::Negotiate = internal_type("NTLM::Negotiate")->AsRecordType();
	plugin->AddBifItem("NTLM::Negotiate", plugin::BifItem::TYPE);
	BifType::Record::NTLM::Challenge = internal_type("NTLM::Challenge")->AsRecordType();
	plugin->AddBifItem("NTLM::Challenge", plugin::BifItem::TYPE);
	BifType::Record::NTLM::Authenticate = internal_type("NTLM::Authenticate")->AsRecordType();
	plugin->AddBifItem("NTLM::Authenticate", plugin::BifItem::TYPE);
	BifType::Record::NTLM::NegotiateFlags = internal_type("NTLM::NegotiateFlags")->AsRecordType();
	plugin->AddBifItem("NTLM::NegotiateFlags", plugin::BifItem::TYPE);
	BifType::Record::NTLM::Version = internal_type("NTLM::Version")->AsRecordType();
	plugin->AddBifItem("NTLM::Version", plugin::BifItem::TYPE);
	BifType::Record::NTLM::AVs = internal_type("NTLM::AVs")->AsRecordType();
	plugin->AddBifItem("NTLM::AVs", plugin::BifItem::TYPE);

	}
} }


