#include "broLibmoon.h"

extern int port_id; /* Port used - From Net.cc */
//extern Packet* current_pkt; /* Current packet pointer - From Net.cc */

void startCapturing(){
	struct rte_mbuf *bufs[MAX_PKT_BURST]; /* Where captured packets are gonna be stored */
	struct rte_mbuf *pkt = NULL;
	int n_pkt = 0;

	if(port_id >= 0){
		n_pkt = rte_eth_rx_burst_export(port_id, 0, bufs, MAX_PKT_BURST);
		if(n_pkt > 0){ //TODO Implement likely() to improve performance
			for(int i=0;i<n_pkt;i++){
				pkt = bufs[i];
				printf("I read something!\n");

				//pkt->Init(props.link_type, &current_hdr.ts, current_hdr.caplen, current_hdr.len, pkt);

			}
		}
	}

}
