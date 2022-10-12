include(AMXConfig)
include(AddSAMPPlugin)

include_directories(Actor_Plus 
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/lib/sdk
)

add_samp_plugin(Actor_Plus 
    ${CMAKE_SOURCE_DIR}/lib/sdk/amxplugin.cpp
    ActorPlus.cpp
    lzn_lib.cpp
    main.cpp
    Native.cpp
    sampgdk.c
    main.def
)

