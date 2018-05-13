#ifndef IOSOURCE_PKTSRC_DPDK_SOURCE_H
#define IOSOURCE_PKTSRC_DPDK_SOURCE_H

#include "../PktSrc.h"

namespace iosource {
namespace dpdk {

class DpdkSource : public iosource::PktSrc{

public:
	DpdkSource(int port_id, bool is_live);
	~DpdkSource() override;

	static PktSrc* Instantiate(int port_id, bool is_live);
	void ConvertToPacket(struct rte_mbuf* buf, Packet* pkt);

protected:
	// PktSrc interface.
	void Open() override;
	void Close() override;
	bool ExtractNextPacket(Packet* pkt) override;
	int ExtractNextBurst(struct rte_mbuf** bufs) override;
	void DoneWithPacket() override;
	bool PrecompileFilter(int index, const std::string& filter) override;
	bool SetFilter(int index) override;
	void Statistics(Stats* stats) override;


private:
	bool Configure();

	Properties props;
	Stats stats;
	int port;

	const struct rte_mbuf *last_burst[MAX_PKT_BURST];;
};

}
}

#endif
