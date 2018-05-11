// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/bittorrent/events.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "events.bif.h"

namespace plugin { namespace Bro_BitTorrent {

void __bif_events_init(plugin::Plugin* plugin)
	{
	::bittorrent_peer_handshake = internal_handler("bittorrent_peer_handshake");
	plugin->AddBifItem("bittorrent_peer_handshake", plugin::BifItem::EVENT);
	::bittorrent_peer_keep_alive = internal_handler("bittorrent_peer_keep_alive");
	plugin->AddBifItem("bittorrent_peer_keep_alive", plugin::BifItem::EVENT);
	::bittorrent_peer_choke = internal_handler("bittorrent_peer_choke");
	plugin->AddBifItem("bittorrent_peer_choke", plugin::BifItem::EVENT);
	::bittorrent_peer_unchoke = internal_handler("bittorrent_peer_unchoke");
	plugin->AddBifItem("bittorrent_peer_unchoke", plugin::BifItem::EVENT);
	::bittorrent_peer_interested = internal_handler("bittorrent_peer_interested");
	plugin->AddBifItem("bittorrent_peer_interested", plugin::BifItem::EVENT);
	::bittorrent_peer_not_interested = internal_handler("bittorrent_peer_not_interested");
	plugin->AddBifItem("bittorrent_peer_not_interested", plugin::BifItem::EVENT);
	::bittorrent_peer_have = internal_handler("bittorrent_peer_have");
	plugin->AddBifItem("bittorrent_peer_have", plugin::BifItem::EVENT);
	::bittorrent_peer_bitfield = internal_handler("bittorrent_peer_bitfield");
	plugin->AddBifItem("bittorrent_peer_bitfield", plugin::BifItem::EVENT);
	::bittorrent_peer_request = internal_handler("bittorrent_peer_request");
	plugin->AddBifItem("bittorrent_peer_request", plugin::BifItem::EVENT);
	::bittorrent_peer_piece = internal_handler("bittorrent_peer_piece");
	plugin->AddBifItem("bittorrent_peer_piece", plugin::BifItem::EVENT);
	::bittorrent_peer_cancel = internal_handler("bittorrent_peer_cancel");
	plugin->AddBifItem("bittorrent_peer_cancel", plugin::BifItem::EVENT);
	::bittorrent_peer_port = internal_handler("bittorrent_peer_port");
	plugin->AddBifItem("bittorrent_peer_port", plugin::BifItem::EVENT);
	::bittorrent_peer_unknown = internal_handler("bittorrent_peer_unknown");
	plugin->AddBifItem("bittorrent_peer_unknown", plugin::BifItem::EVENT);
	::bittorrent_peer_weird = internal_handler("bittorrent_peer_weird");
	plugin->AddBifItem("bittorrent_peer_weird", plugin::BifItem::EVENT);
	::bt_tracker_request = internal_handler("bt_tracker_request");
	plugin->AddBifItem("bt_tracker_request", plugin::BifItem::EVENT);
	::bt_tracker_response = internal_handler("bt_tracker_response");
	plugin->AddBifItem("bt_tracker_response", plugin::BifItem::EVENT);
	::bt_tracker_response_not_ok = internal_handler("bt_tracker_response_not_ok");
	plugin->AddBifItem("bt_tracker_response_not_ok", plugin::BifItem::EVENT);
	::bt_tracker_weird = internal_handler("bt_tracker_weird");
	plugin->AddBifItem("bt_tracker_weird", plugin::BifItem::EVENT);

	}
} }


