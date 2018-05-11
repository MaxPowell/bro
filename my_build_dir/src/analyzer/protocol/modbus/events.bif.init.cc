// This file was automatically generated by bifcl from /home/ubuntu/bro/src/analyzer/protocol/modbus/events.bif (plugin mode).


#include <list>
#include <string>
#include "plugin/Plugin.h"
#include "events.bif.h"

namespace plugin { namespace Bro_Modbus {

void __bif_events_init(plugin::Plugin* plugin)
	{
	::modbus_message = internal_handler("modbus_message");
	plugin->AddBifItem("modbus_message", plugin::BifItem::EVENT);
	::modbus_exception = internal_handler("modbus_exception");
	plugin->AddBifItem("modbus_exception", plugin::BifItem::EVENT);
	::modbus_read_coils_request = internal_handler("modbus_read_coils_request");
	plugin->AddBifItem("modbus_read_coils_request", plugin::BifItem::EVENT);
	::modbus_read_coils_response = internal_handler("modbus_read_coils_response");
	plugin->AddBifItem("modbus_read_coils_response", plugin::BifItem::EVENT);
	::modbus_read_discrete_inputs_request = internal_handler("modbus_read_discrete_inputs_request");
	plugin->AddBifItem("modbus_read_discrete_inputs_request", plugin::BifItem::EVENT);
	::modbus_read_discrete_inputs_response = internal_handler("modbus_read_discrete_inputs_response");
	plugin->AddBifItem("modbus_read_discrete_inputs_response", plugin::BifItem::EVENT);
	::modbus_read_holding_registers_request = internal_handler("modbus_read_holding_registers_request");
	plugin->AddBifItem("modbus_read_holding_registers_request", plugin::BifItem::EVENT);
	::modbus_read_holding_registers_response = internal_handler("modbus_read_holding_registers_response");
	plugin->AddBifItem("modbus_read_holding_registers_response", plugin::BifItem::EVENT);
	::modbus_read_input_registers_request = internal_handler("modbus_read_input_registers_request");
	plugin->AddBifItem("modbus_read_input_registers_request", plugin::BifItem::EVENT);
	::modbus_read_input_registers_response = internal_handler("modbus_read_input_registers_response");
	plugin->AddBifItem("modbus_read_input_registers_response", plugin::BifItem::EVENT);
	::modbus_write_single_coil_request = internal_handler("modbus_write_single_coil_request");
	plugin->AddBifItem("modbus_write_single_coil_request", plugin::BifItem::EVENT);
	::modbus_write_single_coil_response = internal_handler("modbus_write_single_coil_response");
	plugin->AddBifItem("modbus_write_single_coil_response", plugin::BifItem::EVENT);
	::modbus_write_single_register_request = internal_handler("modbus_write_single_register_request");
	plugin->AddBifItem("modbus_write_single_register_request", plugin::BifItem::EVENT);
	::modbus_write_single_register_response = internal_handler("modbus_write_single_register_response");
	plugin->AddBifItem("modbus_write_single_register_response", plugin::BifItem::EVENT);
	::modbus_write_multiple_coils_request = internal_handler("modbus_write_multiple_coils_request");
	plugin->AddBifItem("modbus_write_multiple_coils_request", plugin::BifItem::EVENT);
	::modbus_write_multiple_coils_response = internal_handler("modbus_write_multiple_coils_response");
	plugin->AddBifItem("modbus_write_multiple_coils_response", plugin::BifItem::EVENT);
	::modbus_write_multiple_registers_request = internal_handler("modbus_write_multiple_registers_request");
	plugin->AddBifItem("modbus_write_multiple_registers_request", plugin::BifItem::EVENT);
	::modbus_write_multiple_registers_response = internal_handler("modbus_write_multiple_registers_response");
	plugin->AddBifItem("modbus_write_multiple_registers_response", plugin::BifItem::EVENT);
	::modbus_read_file_record_request = internal_handler("modbus_read_file_record_request");
	plugin->AddBifItem("modbus_read_file_record_request", plugin::BifItem::EVENT);
	::modbus_read_file_record_response = internal_handler("modbus_read_file_record_response");
	plugin->AddBifItem("modbus_read_file_record_response", plugin::BifItem::EVENT);
	::modbus_write_file_record_request = internal_handler("modbus_write_file_record_request");
	plugin->AddBifItem("modbus_write_file_record_request", plugin::BifItem::EVENT);
	::modbus_write_file_record_response = internal_handler("modbus_write_file_record_response");
	plugin->AddBifItem("modbus_write_file_record_response", plugin::BifItem::EVENT);
	::modbus_mask_write_register_request = internal_handler("modbus_mask_write_register_request");
	plugin->AddBifItem("modbus_mask_write_register_request", plugin::BifItem::EVENT);
	::modbus_mask_write_register_response = internal_handler("modbus_mask_write_register_response");
	plugin->AddBifItem("modbus_mask_write_register_response", plugin::BifItem::EVENT);
	::modbus_read_write_multiple_registers_request = internal_handler("modbus_read_write_multiple_registers_request");
	plugin->AddBifItem("modbus_read_write_multiple_registers_request", plugin::BifItem::EVENT);
	::modbus_read_write_multiple_registers_response = internal_handler("modbus_read_write_multiple_registers_response");
	plugin->AddBifItem("modbus_read_write_multiple_registers_response", plugin::BifItem::EVENT);
	::modbus_read_fifo_queue_request = internal_handler("modbus_read_fifo_queue_request");
	plugin->AddBifItem("modbus_read_fifo_queue_request", plugin::BifItem::EVENT);
	::modbus_read_fifo_queue_response = internal_handler("modbus_read_fifo_queue_response");
	plugin->AddBifItem("modbus_read_fifo_queue_response", plugin::BifItem::EVENT);

	}
} }


