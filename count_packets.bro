global n_pkts:int;

event bro_init(){
	n_pkts = 0;
}

event raw_packet(p: raw_pkt_hdr){
	n_pkts = n_pkts + 1;
}

event bro_done(){
	print fmt("Packets added by the script: %d", n_pkts);
}
