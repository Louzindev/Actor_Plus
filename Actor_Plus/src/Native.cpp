#include "Native.h"

namespace Native {

    cell AMX_NATIVE_CALL HelloWorld(AMX* amx, cell* params) {
        logprintf("Hello, Aki e o louzin");
        return 1;
    }

    AMX_DECLARE_NATIVE(TogglePlayerTargetActor) {
        int playerid = static_cast<int>(params[1]);
        int toggle = static_cast<int>(params[2]);

        actor_p::TogglePlayerTargetActor(playerid, toggle);

        return 1;
    }

    AMX_DECLARE_NATIVE(GetActorWhoPlayerTarget) {
        
        int playerid = static_cast<int>(params[1]);
        int actorid = static_cast<int>(params[2]);

        return actor_p::GetActorWhoPlayerTarget(playerid);
    }

    AMX_DECLARE_NATIVE(SetActorChatBubble) {
        int actorid = static_cast<int>(params[1]);

        char* text = new char[101];
        lzn::amx_GetStr(amx, params[2], text, 100);

        int delay = static_cast<int>(params[3]);

        actor_p::SetActorChatBubble(actorid, static_cast<const char*>(text), delay);
        return 1;
    }


    AMX_NATIVE_INFO PluginNatives[] = {
        {"HelloWorld", HelloWorld},
        {"GetActorWhoPlayerTarget", GetActorWhoPlayerTarget},
        {"SetActorChatBubble", SetActorChatBubble},
        {"TogglePlayerTargetActor", TogglePlayerTargetActor},
        {0, 0}
    };

}