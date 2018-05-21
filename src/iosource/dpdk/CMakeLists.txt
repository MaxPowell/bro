include(BroPlugin)

include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

bro_plugin_begin(Bro Dpdk)
bro_plugin_cc(Source.cc Plugin.cc)
#bif_target(dpdk.bif)
bro_plugin_end()
