# This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/http/functions.bif (plugin mode).


export {


## Skips the data of the HTTP entity.
##
## c: The HTTP connection.
##
## is_orig: If true, the client data is skipped, and the server data otherwise.
##
## .. bro:see:: skip_smtp_data
global skip_http_entity_data: function(c: connection , is_orig: bool ): any ;


## Unescapes all characters in a URI (decode every ``%xx`` group).
##
## URI: The URI to unescape.
##
## Returns: The unescaped URI with all ``%xx`` groups decoded.
##
## .. note::
##
##      Unescaping reserved characters may cause loss of information.
##      :rfc:`2396`: A URI is always in an "escaped" form, since escaping or
##      unescaping a completed URI might change its semantics.  Normally, the
##      only time escape encodings can safely be made is when the URI is
##      being created from its component parts.
global unescape_URI: function(URI: string ): string ;

} # end of export section
module GLOBAL;
