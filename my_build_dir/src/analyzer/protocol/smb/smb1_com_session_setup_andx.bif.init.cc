// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smb/smb1_com_session_setup_andx.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "smb1_com_session_setup_andx.bif.h"

namespace plugin { namespace Bro_SMB {

void __bif_smb1_com_session_setup_andx_init(plugin::Plugin* plugin)
	{
	::smb1_session_setup_andx_request = internal_handler("smb1_session_setup_andx_request");
	plugin->AddBifItem("smb1_session_setup_andx_request", plugin::BifItem::EVENT);
	::smb1_session_setup_andx_response = internal_handler("smb1_session_setup_andx_response");
	plugin->AddBifItem("smb1_session_setup_andx_response", plugin::BifItem::EVENT);
	BifType::Record::SMB1::SessionSetupAndXRequest = internal_type("SMB1::SessionSetupAndXRequest")->AsRecordType();
	plugin->AddBifItem("SMB1::SessionSetupAndXRequest", plugin::BifItem::TYPE);
	BifType::Record::SMB1::SessionSetupAndXResponse = internal_type("SMB1::SessionSetupAndXResponse")->AsRecordType();
	plugin->AddBifItem("SMB1::SessionSetupAndXResponse", plugin::BifItem::TYPE);
	BifType::Record::SMB1::SessionSetupAndXCapabilities = internal_type("SMB1::SessionSetupAndXCapabilities")->AsRecordType();
	plugin->AddBifItem("SMB1::SessionSetupAndXCapabilities", plugin::BifItem::TYPE);

	}
} }


