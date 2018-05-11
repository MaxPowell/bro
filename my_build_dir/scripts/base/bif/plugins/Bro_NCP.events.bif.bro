# This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/ncp/events.bif (plugin mode).

## Generated for NCP requests (Netware Core Protocol).
##
## See `Wikipedia <http://en.wikipedia.org/wiki/NetWare_Core_Protocol>`__ for
## more information about the NCP protocol.
##
## c: The connection.
##
## frame_type: The frame type, as specified by the protocol.
##
## length: The length of the request body, excluding the frame header.
##
## func: The requested function, as specified by the protocol.
##
## .. bro:see:: ncp_reply
##
## .. todo:: Bro's current default configuration does not activate the protocol
##    analyzer that generates this event; the corresponding script has not yet
##    been ported to Bro 2.x. To still enable this event, one needs to
##    register a port for it or add a DPD payload signature.
export {
global ncp_request: event(c: connection , frame_type: count , length: count , func: count );


## Generated for NCP replies (Netware Core Protocol).
##
## See `Wikipedia <http://en.wikipedia.org/wiki/NetWare_Core_Protocol>`__ for
## more information about the NCP protocol.
##
## c: The connection.
##
## frame_type: The frame type, as specified by the protocol.
##
## length: The length of the request body, excluding the frame header.
##
## req_frame: The frame type from the corresponding request.
##
## req_func: The function code from the corresponding request.
##
## completion_code: The reply's completion code, as specified by the protocol.
##
## .. bro:see:: ncp_request
##
## .. todo:: Bro's current default configuration does not activate the protocol
##    analyzer that generates this event; the corresponding script has not yet
##    been ported to Bro 2.x. To still enable this event, one needs to
##    register a port for it or add a DPD payload signature.
global ncp_reply: event(c: connection , frame_type: count , length: count , req_frame: count , req_func: count , completion_code: count );


} # end of export section
module GLOBAL;
