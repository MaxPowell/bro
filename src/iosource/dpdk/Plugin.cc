#include "plugin/Plugin.h"

#include "Source.h"

namespace plugin {
namespace Bro_Dpdk {

class Plugin : public plugin::Plugin {
public:
	plugin::Configuration Configure()
		{
		AddComponent(new ::iosource::PktSrcComponent("DpdkReader", "dpdk", ::iosource::PktSrcComponent::BOTH, ::iosource::dpdk::DpdkSource::Instantiate));

		plugin::Configuration config;
		config.name = "Bro::Dpdk";
		config.description = "Packet acquisition via dpdk";
		return config;
		}
} plugin;

}
}

