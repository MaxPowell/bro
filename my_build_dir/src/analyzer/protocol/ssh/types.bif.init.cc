// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/ssh/types.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "types.bif.h"

namespace plugin { namespace Bro_SSH {

void __bif_types_init(plugin::Plugin* plugin)
	{
	BifType::Record::SSH::Algorithm_Prefs = internal_type("SSH::Algorithm_Prefs")->AsRecordType();
	plugin->AddBifItem("SSH::Algorithm_Prefs", plugin::BifItem::TYPE);
	BifType::Record::SSH::Capabilities = internal_type("SSH::Capabilities")->AsRecordType();
	plugin->AddBifItem("SSH::Capabilities", plugin::BifItem::TYPE);

	}
} }


