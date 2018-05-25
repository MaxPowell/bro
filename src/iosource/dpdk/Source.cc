
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
	
	// TODO call with -i dpdk::<port_number> 
	//port = port_id;

	if(!L){
		L=lua_open();
		luaL_openlibs(L);
		//setLuaPath(L, "aaa"); // FIXME hardcoded
		printf("ALLAHU AKBAAAAAAAAAAAAAAAAR");
		if(luaL_dofile(L, "packet.lua"))
			printf("Error loading file :D\n");
	}
}

void DpdkSource::Open(){
	/* It will be always opened, just need to configure it */
	if(Configure()){
		props.is_live = true;
		props.link_type = 0; // FIXME This one is harcoded, not sure if it affects bro
		Opened(props);		 // Done just to avoid crash on Opened()

	}
}

bool DpdkSource::Configure(){
	// TODO look for port number
	return !config_device(port,1,0, 0, 0, 0, 0, 0, 0, 0, 8191, RTE_MBUF_DEFAULT_BUF_SIZE);
}

void DpdkSource::Close(){
	//last_burst = 0;
	Closed();
}

void DpdkSource::DoneWithPacket(){
	/* Nothing to do */ // TODO create DoneWithBurst?
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
	/* It is possible tochange the implementation to return one packet */
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
	uint8_t data_int = 0;
			printf("ALLAHU AKBAAAAAAAAAAAAAAAAR_2");
	/* Get packet data with lua */
	lua_getglobal(L, "pkt");
			printf("ALLAHU AKBAAAAAAAAAAAAAAAAR_3");
	lua_getfield(L, -1, "getBytes");
			printf("ALLAHU AKBAAAAAAAAAAAAAAAAR_4");
	lua_pushvalue(L, -2);
			printf("ALLAHU AKBAAAAAAAAAAAAAAAAR_5");
	lua_call(L, 1, 1);
			printf("ALLAHU AKBAAAAAAAAAAAAAAAAR_6");
	data_int = lua_tointeger(L, -1);
			printf("ALLAHU AKBAAAAAAAAAAAAAAAAR_7");
	lua_pop(L, 1);
			printf("ALLAHU AKBAAAAAAAAAAAAAAAAR_8");

	uint8_t* data = (uint8_t*) data_int;

	if (!data){
		printf("Something went wrong with lua\n");
	}
		
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
	pkt->Init(buf->l2_type, &ts, rte_pktmbuf_data_len(buf), rte_pktmbuf_pkt_len(buf), data); // FIXME link type
}

int DpdkSource::GetLastBurstSize(){
	return last_burst_size;
}

int setLuaPath(lua_State* L, const char* path){
    lua_getglobal( L, "package" );
    lua_getfield( L, -1, "path" ); // get field "path" from table at top of stack (-1)
    std::string cur_path = lua_tostring( L, -1 ); // grab path string from top of stack
    cur_path.append( ";" ); // do your path magic here
    cur_path.append( path );
    lua_pop( L, 1 ); // get rid of the string on the stack we just pushed on line 5
    lua_pushstring( L, cur_path.c_str() ); // push the new one
    lua_setfield( L, -2, "path" ); // set the field "path" in table at -2 with value at top of stack
    lua_pop( L, 1 ); // get rid of package table from top of stack
    return 0; // all done!
}

