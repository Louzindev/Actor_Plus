#ifndef NATIVE_H_INCLUDED
#define NATIVE_H_INCLUDED
#include "main.h"
#include "amx/amx.h"
#include "lzn_lib.h"
#include "ActorPlus.h"

typedef cell AMX_NATIVE_CALL(*AMX_Function_t)(AMX* amx, cell* params);

#define AMX_DECLARE_NATIVE(name) \
	cell AMX_NATIVE_CALL name(AMX* amx, cell* params)

namespace Native {
    
    // native HelloWorld(); 
    AMX_DECLARE_NATIVE(HelloWorld);
    // native GetActorWhoPlayerTarget(const playerid);
    AMX_DECLARE_NATIVE(GetActorWhoPlayerTarget);
    // native TogglePlayerTargetActor(const playerid, Togle);
    AMX_DECLARE_NATIVE(TogglePlayerTargetActor);
    // native SetActorChatBubble(const actorid, const str[]);
    AMX_DECLARE_NATIVE(SetActorChatBubble);
    // native CheckVersion(major, minor, patch);
    AMX_DECLARE_NATIVE(CheckVersion);
    extern AMX_NATIVE_INFO PluginNatives[];
}

#endif