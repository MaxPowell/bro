#ifndef IOSOURCE_PKTSRC_DPDK_SOURCE_H
#define IOSOURCE_PKTSRC_DPDK_SOURCE_H

#include "../PktSrc.h"

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

namespace iosource {
namespace dpdk {

class DpdkSource : public iosource::PktSrc{

public:
	DpdkSource(const std::string& path, bool is_live);
	~DpdkSource() override;

	static PktSrc* Instantiate(const std::string& path, bool is_live);

protected:
	// PktSrc interface.
	void Open() override;
	void Close() override;
	bool ExtractNextPacket(Packet* pkt) override;
	int ExtractNextBurst(Packet bufs[MAX_PKT_BURST]) override;
	int GetLastBurstSize() override;
	void DoneWithPacket() override;
	bool PrecompileFilter(int index, const std::string& filter) override;
	bool SetFilter(int index) override;
	void Statistics(Stats* stats) override;


private:
	bool Configure();
	void ConvertToPacket(struct rte_mbuf* buf, Packet* pkt);
	int setLuaPath(lua_State* L, const char* path);

	Properties props;
	Stats stats;
	int port;
	int last_burst_size;

	lua_State* L;

	struct rte_mbuf *last_burst[MAX_PKT_BURST];
};

}
}

#endif
