// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/arp/events.bif (plugin mode).

#if defined(BRO_IN_NETVAR) || ! defined(_home_ubuntu_bro_my_build_dir_src_analyzer_protocol_arp_events_bif)
#ifndef BRO_IN_NETVAR
#ifndef _home_ubuntu_bro_my_build_dir_src_analyzer_protocol_arp_events_bif
#define _home_ubuntu_bro_my_build_dir_src_analyzer_protocol_arp_events_bif
#include "bro-bif.h"
#endif
#endif

extern EventHandlerPtr arp_request; 
namespace BifEvent {  void generate_arp_request(analyzer::Analyzer* analyzer, StringVal* mac_src, StringVal* mac_dst, AddrVal* SPA, StringVal* SHA, AddrVal* TPA, StringVal* THA);  } 
extern EventHandlerPtr arp_reply; 
namespace BifEvent {  void generate_arp_reply(analyzer::Analyzer* analyzer, StringVal* mac_src, StringVal* mac_dst, AddrVal* SPA, StringVal* SHA, AddrVal* TPA, StringVal* THA);  } 
extern EventHandlerPtr bad_arp; 
namespace BifEvent {  void generate_bad_arp(analyzer::Analyzer* analyzer, AddrVal* SPA, StringVal* SHA, AddrVal* TPA, StringVal* THA, StringVal* explanation);  } 

#endif
