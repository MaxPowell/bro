
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
	/* No need for this */
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
		// TODO Probably I will have to manually count all packets

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
	stats.received+=n_packets;
	last_burst = bufs	
	
	return n_pkts;
}
