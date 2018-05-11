// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smb/smb1_com_transaction2.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "smb1_com_transaction2.bif.h"

namespace plugin { namespace Bro_SMB {

void __bif_smb1_com_transaction2_init(plugin::Plugin* plugin)
	{
	::smb1_transaction2_request = internal_handler("smb1_transaction2_request");
	plugin->AddBifItem("smb1_transaction2_request", plugin::BifItem::EVENT);
	::smb1_trans2_find_first2_request = internal_handler("smb1_trans2_find_first2_request");
	plugin->AddBifItem("smb1_trans2_find_first2_request", plugin::BifItem::EVENT);
	::smb1_trans2_query_path_info_request = internal_handler("smb1_trans2_query_path_info_request");
	plugin->AddBifItem("smb1_trans2_query_path_info_request", plugin::BifItem::EVENT);
	::smb1_trans2_get_dfs_referral_request = internal_handler("smb1_trans2_get_dfs_referral_request");
	plugin->AddBifItem("smb1_trans2_get_dfs_referral_request", plugin::BifItem::EVENT);
	BifType::Record::SMB1::Find_First2_Request_Args = internal_type("SMB1::Find_First2_Request_Args")->AsRecordType();
	plugin->AddBifItem("SMB1::Find_First2_Request_Args", plugin::BifItem::TYPE);
	BifType::Record::SMB1::Find_First2_Response_Args = internal_type("SMB1::Find_First2_Response_Args")->AsRecordType();
	plugin->AddBifItem("SMB1::Find_First2_Response_Args", plugin::BifItem::TYPE);
	BifType::Record::SMB1::Trans2_Args = internal_type("SMB1::Trans2_Args")->AsRecordType();
	plugin->AddBifItem("SMB1::Trans2_Args", plugin::BifItem::TYPE);

	}
} }


