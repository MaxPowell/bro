// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/irc/events.bif (plugin mode).

#if defined(BRO_IN_NETVAR) || ! defined(_home_ubuntu_bro_my_build_dir_src_analyzer_protocol_irc_events_bif)
#ifndef BRO_IN_NETVAR
#ifndef _home_ubuntu_bro_my_build_dir_src_analyzer_protocol_irc_events_bif
#define _home_ubuntu_bro_my_build_dir_src_analyzer_protocol_irc_events_bif
#include "bro-bif.h"
#endif
#endif

extern EventHandlerPtr irc_request; 
namespace BifEvent {  void generate_irc_request(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* prefix, StringVal* command, StringVal* arguments);  } 
extern EventHandlerPtr irc_reply; 
namespace BifEvent {  void generate_irc_reply(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* prefix, bro_uint_t code, StringVal* params);  } 
extern EventHandlerPtr irc_message; 
namespace BifEvent {  void generate_irc_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* prefix, StringVal* command, StringVal* message);  } 
extern EventHandlerPtr irc_quit_message; 
namespace BifEvent {  void generate_irc_quit_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* nick, StringVal* message);  } 
extern EventHandlerPtr irc_privmsg_message; 
namespace BifEvent {  void generate_irc_privmsg_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* source, StringVal* target, StringVal* message);  } 
extern EventHandlerPtr irc_notice_message; 
namespace BifEvent {  void generate_irc_notice_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* source, StringVal* target, StringVal* message);  } 
extern EventHandlerPtr irc_squery_message; 
namespace BifEvent {  void generate_irc_squery_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* source, StringVal* target, StringVal* message);  } 
extern EventHandlerPtr irc_join_message; 
namespace BifEvent {  void generate_irc_join_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, Val* info_list);  } 
extern EventHandlerPtr irc_part_message; 
namespace BifEvent {  void generate_irc_part_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* nick, Val* chans, StringVal* message);  } 
extern EventHandlerPtr irc_nick_message; 
namespace BifEvent {  void generate_irc_nick_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* who, StringVal* newnick);  } 
extern EventHandlerPtr irc_invalid_nick; 
namespace BifEvent {  void generate_irc_invalid_nick(analyzer::Analyzer* analyzer, Connection* c, int is_orig);  } 
extern EventHandlerPtr irc_network_info; 
namespace BifEvent {  void generate_irc_network_info(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t users, bro_uint_t services, bro_uint_t servers);  } 
extern EventHandlerPtr irc_server_info; 
namespace BifEvent {  void generate_irc_server_info(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t users, bro_uint_t services, bro_uint_t servers);  } 
extern EventHandlerPtr irc_channel_info; 
namespace BifEvent {  void generate_irc_channel_info(analyzer::Analyzer* analyzer, Connection* c, int is_orig, bro_uint_t chans);  } 
extern EventHandlerPtr irc_who_line; 
namespace BifEvent {  void generate_irc_who_line(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* target_nick, StringVal* channel, StringVal* user, StringVal* host, StringVal* server, StringVal* nick, StringVal* params, bro_uint_t hops, StringVal* real_name);  } 
extern EventHandlerPtr irc_names_info; 
namespace BifEvent {  void generate_irc_names_info(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* c_type, StringVal* channel, Val* users);  } 
extern EventHandlerPtr irc_whois_operator_line; 
namespace BifEvent {  void generate_irc_whois_operator_line(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* nick);  } 
extern EventHandlerPtr irc_whois_channel_line; 
namespace BifEvent {  void generate_irc_whois_channel_line(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* nick, Val* chans);  } 
extern EventHandlerPtr irc_whois_user_line; 
namespace BifEvent {  void generate_irc_whois_user_line(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* nick, StringVal* user, StringVal* host, StringVal* real_name);  } 
extern EventHandlerPtr irc_oper_response; 
namespace BifEvent {  void generate_irc_oper_response(analyzer::Analyzer* analyzer, Connection* c, int is_orig, int got_oper);  } 
extern EventHandlerPtr irc_global_users; 
namespace BifEvent {  void generate_irc_global_users(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* prefix, StringVal* msg);  } 
extern EventHandlerPtr irc_channel_topic; 
namespace BifEvent {  void generate_irc_channel_topic(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* channel, StringVal* topic);  } 
extern EventHandlerPtr irc_who_message; 
namespace BifEvent {  void generate_irc_who_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* mask, int oper);  } 
extern EventHandlerPtr irc_whois_message; 
namespace BifEvent {  void generate_irc_whois_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* server, StringVal* users);  } 
extern EventHandlerPtr irc_oper_message; 
namespace BifEvent {  void generate_irc_oper_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* user, StringVal* password);  } 
extern EventHandlerPtr irc_kick_message; 
namespace BifEvent {  void generate_irc_kick_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* prefix, StringVal* chans, StringVal* users, StringVal* comment);  } 
extern EventHandlerPtr irc_error_message; 
namespace BifEvent {  void generate_irc_error_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* prefix, StringVal* message);  } 
extern EventHandlerPtr irc_invite_message; 
namespace BifEvent {  void generate_irc_invite_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* prefix, StringVal* nickname, StringVal* channel);  } 
extern EventHandlerPtr irc_mode_message; 
namespace BifEvent {  void generate_irc_mode_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* prefix, StringVal* params);  } 
extern EventHandlerPtr irc_squit_message; 
namespace BifEvent {  void generate_irc_squit_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* prefix, StringVal* server, StringVal* message);  } 
extern EventHandlerPtr irc_dcc_message; 
namespace BifEvent {  void generate_irc_dcc_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* prefix, StringVal* target, StringVal* dcc_type, StringVal* argument, AddrVal* address, bro_uint_t dest_port, bro_uint_t size);  } 
extern EventHandlerPtr irc_user_message; 
namespace BifEvent {  void generate_irc_user_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* user, StringVal* host, StringVal* server, StringVal* real_name);  } 
extern EventHandlerPtr irc_password_message; 
namespace BifEvent {  void generate_irc_password_message(analyzer::Analyzer* analyzer, Connection* c, int is_orig, StringVal* password);  } 
extern EventHandlerPtr irc_starttls; 
namespace BifEvent {  void generate_irc_starttls(analyzer::Analyzer* analyzer, Connection* c);  } 

#endif
