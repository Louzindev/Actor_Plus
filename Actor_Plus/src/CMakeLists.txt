include(AMXConfig)
include(AddSAMPPlugin)

include_directories(Actor_Plus "${CMAKE_SOURCE_DIR}"
    ${CMAKE_SOURCE_DIR}/lib/sdk
)

add_samp_plugin(Actor_Plus 
"${CMAKE_SOURCE_DIR}/lib/sdk/amxplugin.cpp"
"ActorPlus.cxx"
"lzn_lib.cxx"
"main.cxx"
"Native.cxx"
"sampgdk.c"
"main.def"
)

