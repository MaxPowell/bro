// This file was automatically generated by bifcl from /home/ubuntu/bro/src/input/readers/raw/raw.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "raw.bif.h"

namespace plugin { namespace Bro_RawReader {

void __bif_raw_init(plugin::Plugin* plugin)
	{
	BifConst::InputRaw::record_separator = internal_const_val("InputRaw::record_separator")->AsStringVal();
	plugin->AddBifItem("InputRaw::record_separator", plugin::BifItem::CONSTANT);

	}
} }


