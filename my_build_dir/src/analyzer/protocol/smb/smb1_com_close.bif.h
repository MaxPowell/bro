// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/smb/smb1_com_close.bif (plugin mode).

#if defined(BRO_IN_NETVAR) || ! defined(_home_ubuntu_bro_my_build_dir_src_analyzer_protocol_smb_smb1_com_close_bif)
#ifndef BRO_IN_NETVAR
#ifndef _home_ubuntu_bro_my_build_dir_src_analyzer_protocol_smb_smb1_com_close_bif
#define _home_ubuntu_bro_my_build_dir_src_analyzer_protocol_smb_smb1_com_close_bif
#include "bro-bif.h"
#endif
#endif

extern EventHandlerPtr smb1_close_request; 
namespace BifEvent {  void generate_smb1_close_request(analyzer::Analyzer* analyzer, Connection* c, Val* hdr, bro_uint_t file_id);  } 

#endif
