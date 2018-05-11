// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smb/smb2_com_create.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "smb2_com_create.bif.h"

namespace plugin { namespace Bro_SMB {

void __bif_smb2_com_create_init(plugin::Plugin* plugin)
	{
	::smb2_create_request = internal_handler("smb2_create_request");
	plugin->AddBifItem("smb2_create_request", plugin::BifItem::EVENT);
	::smb2_create_response = internal_handler("smb2_create_response");
	plugin->AddBifItem("smb2_create_response", plugin::BifItem::EVENT);
	BifType::Record::SMB2::CreateRequest = internal_type("SMB2::CreateRequest")->AsRecordType();
	plugin->AddBifItem("SMB2::CreateRequest", plugin::BifItem::TYPE);
	BifType::Record::SMB2::CreateResponse = internal_type("SMB2::CreateResponse")->AsRecordType();
	plugin->AddBifItem("SMB2::CreateResponse", plugin::BifItem::TYPE);

	}
} }


