
#include <assert.h>

#include "bro-config.h"
#include "iosource/Packet.h"

#include "device.h"
#include "Source.h"
#include <rte_mbuf.h>

using namespace iosource::dpdk;

DpdkSource::~DpdkSource(){
	Close();
}

DpdkSource::DpdkSource(const std::string& path, bool is_live){

	props.path = path;
	props.is_live = is_live;
	last_burst_size = 0;
	//last_burst = NULL;
	
	// call bro with -i dpdk::<port_number> 
	port = std::stoi(path);
}

void DpdkSource::Open(){
	/* It will be always opened, just need to configure it */
	if(Configure()){
		props.is_live = true;
		props.link_type = 1; // FIXME This one is harcoded, not sure if it affects bro
		Opened(props);

	}
}

bool DpdkSource::Configure(){
	return !config_device(port,1,0, 0, 0, 0, 0, 0, 0, 0, 8191, RTE_MBUF_DEFAULT_BUF_SIZE);
}

void DpdkSource::Close(){
	//last_burst = 0;
	Closed();
}

void DpdkSource::DoneWithPacket(){
	/* Nothing to do */
}

bool DpdkSource::PrecompileFilter(int index, const std::string& filter){
	return PktSrc::PrecompileBPFFilter(index, filter);
}

bool DpdkSource::SetFilter(int index){
	/* Uh, DPDK has this option? */
	return true;
}

void DpdkSource::Statistics(Stats* s){
	if(!props.is_live)
		s->received = s->dropped = s->link = s->bytes_received = 0;

	else{
		// TODO rte_eth_stats
		s->received = stats.received;
		s->bytes_received = stats.bytes_received;
	}
}

iosource::PktSrc* DpdkSource::Instantiate(const std::string& path, bool is_live){
	return new DpdkSource(path, is_live);
}


bool DpdkSource::ExtractNextPacket(Packet* pkt){
	/* You should never call this function, call burst instead */
	/* It is possible to change the implementation to return one packet */
	/* after calling this function, but dpdk should use bursts */
	return false;
}

int  DpdkSource::ExtractNextBurst(Packet bufs[MAX_PKT_BURST]){
	int n_pkts = rte_eth_rx_burst_export(port, 0, last_burst, MAX_PKT_BURST);
	stats.received+=n_pkts;
	last_burst_size = n_pkts;

	for(int i=0;i<n_pkts;i++)
		ConvertToPacket(last_burst[i], &bufs[i]);
	
	return n_pkts;
}


void  DpdkSource::ConvertToPacket(struct rte_mbuf* buf, Packet* pkt){
	if(buf == NULL || pkt == NULL)
		return;

	pkt_timeval ts = {current_time(true), 0};
	u_char* data = rte_pktmbuf_mtod(buf, u_char*);
		
	/**
	 * Initialize from packet data.
	 *
	 * @param link_type The link type in the form of a \c DLT_* constant.
	 *
	 * @param ts The timestamp associated with the packet.
	 *
	 * @param caplen The number of bytes valid in *data*.
	 *
	 * @param len The wire length of the packet, which must be more or
	 * equal *caplen* (but can't be less).
	 *
	 * @param data A pointer to the raw packet data, starting with the
	 * layer 2 header. The pointer must remain valid for the lifetime of
	 * the Packet instance, unless *copy* is true.
	 *
	 * @param copy If true, the constructor will make an internal copy of
	 * *data*, so that the caller can release its version.
	 *
	 * @param tag A textual tag to associate with the packet for
	 * differentiating the input streams.
	 */
	pkt->Init(props.link_type, &ts, rte_pktmbuf_data_len(buf), rte_pktmbuf_pkt_len(buf), data);
}

int DpdkSource::GetLastBurstSize(){
	return last_burst_size;
}


