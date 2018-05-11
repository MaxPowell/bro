# This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/gtpv1/events.bif (plugin mode).

## Generated for any GTP message with a GTPv1 header.
##
## c: The connection over which the message is sent.
##
## hdr: The GTPv1 header.
export {
global gtpv1_message: event(c: connection , hdr: gtpv1_hdr );


## Generated for GTPv1 G-PDU packets.  That is, packets with a UDP payload
## that includes a GTP header followed by an IPv4 or IPv6 packet.
##
## outer: The GTP outer tunnel connection.
##
## inner_gtp: The GTP header.
##
## inner_ip: The inner IP and transport layer packet headers.
##
## .. note:: Since this event may be raised on a per-packet basis, handling
##    it may become particularly expensive for real-time analysis.
global gtpv1_g_pdu_packet: event(outer: connection , inner_gtp: gtpv1_hdr , inner_ip: pkt_hdr );


## Generated for GTPv1-C Create PDP Context Request messages.
##
## c: The connection over which the message is sent.
##
## hdr: The GTPv1 header.
##
## elements: The set of Information Elements comprising the message.
global gtpv1_create_pdp_ctx_request: event(c: connection , hdr: gtpv1_hdr , elements: gtp_create_pdp_ctx_request_elements );


## Generated for GTPv1-C Create PDP Context Response messages.
##
## c: The connection over which the message is sent.
##
## hdr: The GTPv1 header.
##
## elements: The set of Information Elements comprising the message.
global gtpv1_create_pdp_ctx_response: event(c: connection , hdr: gtpv1_hdr , elements: gtp_create_pdp_ctx_response_elements );


## Generated for GTPv1-C Update PDP Context Request messages.
##
## c: The connection over which the message is sent.
##
## hdr: The GTPv1 header.
##
## elements: The set of Information Elements comprising the message.
global gtpv1_update_pdp_ctx_request: event(c: connection , hdr: gtpv1_hdr , elements: gtp_update_pdp_ctx_request_elements );


## Generated for GTPv1-C Update PDP Context Response messages.
##
## c: The connection over which the message is sent.
##
## hdr: The GTPv1 header.
##
## elements: The set of Information Elements comprising the message.
global gtpv1_update_pdp_ctx_response: event(c: connection , hdr: gtpv1_hdr , elements: gtp_update_pdp_ctx_response_elements );


## Generated for GTPv1-C Delete PDP Context Request messages.
##
## c: The connection over which the message is sent.
##
## hdr: The GTPv1 header.
##
## elements: The set of Information Elements comprising the message.
global gtpv1_delete_pdp_ctx_request: event(c: connection , hdr: gtpv1_hdr , elements: gtp_delete_pdp_ctx_request_elements );


## Generated for GTPv1-C Delete PDP Context Response messages.
##
## c: The connection over which the message is sent.
##
## hdr: The GTPv1 header.
##
## elements: The set of Information Elements comprising the message.
global gtpv1_delete_pdp_ctx_response: event(c: connection , hdr: gtpv1_hdr , elements: gtp_delete_pdp_ctx_response_elements );


} # end of export section
module GLOBAL;
