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
    // native IsPlayerAimingActor(const playerid, const actorid);
    AMX_DECLARE_NATIVE(IsPlayerAimingActor);
    // native SetActorChatBubble(const actorid, const str[]);
    AMX_DECLARE_NATIVE(SetActorChatBubble);
    // native SetActorName(const actorid, const name[]);
    AMX_DECLARE_NATIVE(SetActorName);
    // native GetActorName(const int actor, dest[], size = sizeof(dest));
    AMX_DECLARE_NATIVE(GetActorName);
    // native ToggleActorTalk(const int actorid, bool toggle);
    AMX_DECLARE_NATIVE(ToggleActorTalk);
    AMX_NATIVE_INFO PluginNatives[];
}

#endif