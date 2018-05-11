// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smb/smb2_com_negotiate.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "smb2_com_negotiate.bif.h"

namespace plugin { namespace Bro_SMB {

void __bif_smb2_com_negotiate_init(plugin::Plugin* plugin)
	{
	::smb2_negotiate_request = internal_handler("smb2_negotiate_request");
	plugin->AddBifItem("smb2_negotiate_request", plugin::BifItem::EVENT);
	::smb2_negotiate_response = internal_handler("smb2_negotiate_response");
	plugin->AddBifItem("smb2_negotiate_response", plugin::BifItem::EVENT);
	BifType::Record::SMB2::NegotiateResponse = internal_type("SMB2::NegotiateResponse")->AsRecordType();
	plugin->AddBifItem("SMB2::NegotiateResponse", plugin::BifItem::TYPE);

	}
} }


