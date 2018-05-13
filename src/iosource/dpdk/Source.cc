
#include <assert.h>

#include "bro-config.h"

#include "Source.h"
#include "iosource/Packet.h"

#include "device.h"

using namespace iosource::dpdk;

DpdkSource::~DpdkSource(){
	Close();
}

DpdkSource::DpdkSource(int port_id, bool is_live){

	props.path = std::to_string(port_id);
	props.is_live = is_live;
	last_burst = 0;
	port = port_id;
}

void DpdkSource::Open(){
	/* It will be always opened, just need to configure it */
	if(Configure()){
		props.is_live = true;
		Opened(props);
	}
}

bool DpdkSource::Configure(){
	return !config_device(port,1,0, 0, 0, 0, 0, 0, 0, 0, 8191, RTE_MBUF_DEFAULT_BUF_SIZE);
}

void DpdkSource::Close(){
	last_burst = 0;
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
		// TODO Probably I will have to manually count all packets/bytes/dropped
		s->received = stats.received;
		s->bytes_received = stats.bytes_received;
	}
}

iosource::PktSrc* DpdkSource::Instantiate(int port_id, bool is_live){
	return new DpdkSource(port_id, is_live);
}


bool DpdkSource::ExtractNextPacket(Packet* pkt){
	/* You should never call this function, call burst instead */
	return false;
}

int ExtractNextBurst(struct rte_mbuf** bufs){
	int n_pkts = rte_eth_rx_burst_export(port, 0, bufs, MAX_PKT_BURST);
	stats.received+=n_pkts;
	last_burst = bufs;
	
	return n_pkts;
}


void ConvertToPacket(struct rte_mbuf* buf, Packet* pkt){
	if(buf == NULL || pkt == NULL)
		return;
	
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
	pkt->Init(props.link_type, &current_hdr.ts, current_hdr.caplen, current_hdr.len, buf);
}

