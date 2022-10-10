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

    AMX_DECLARE_NATIVE(CheckVersion) {
        int major = static_cast<int>(params[1]);
        int minor = static_cast<int>(params[2]);

        if (major == MAJOR_VERSION) {
            if (minor < MINOR_VERSION) {
                logprintf("\n=============> WARNING <=============");
                logprintf("You're using an old version include for Actor_Plus");
                logprintf("Actual Version: %d.%d", major, minor);
                logprintf("Go to https://github.com/LouzinDeev/Actor_Plus and download the last version");
                logprintf("=============> WARNING <=============\n\n");
            }
            else if (minor > MINOR_VERSION) {
                logprintf("You're using an old version plugin for Actor_Plus");
                logprintf("Actual Version: %d.%d", MAJOR_VERSION, MINOR_VERSION);
                logprintf("Go to https://github.com/LouzinDeev/Actor_Plus and download the last version");
            }
        }
        if (major > MAJOR_VERSION) {
            logprintf("You're using an old version plugin for Actor_Plus");
            logprintf("Actual Version: %d.%d", MAJOR_VERSION, MINOR_VERSION);
            logprintf("Go to https://github.com/LouzinDeev/Actor_Plus and download the last version");
        }
        if (major < MAJOR_VERSION) {
            logprintf("You're using an old version include for Actor_Plus");
            logprintf("Actual Version: %d.%d", major, minor);
            logprintf("Go to https://github.com/LouzinDeev/Actor_Plus and download the last version");
        }
        return 1;
    }

    AMX_NATIVE_INFO PluginNatives[] = {
        {"HelloWorld", HelloWorld},
        {"GetActorWhoPlayerTarget", GetActorWhoPlayerTarget},
        {"SetActorChatBubble", SetActorChatBubble},
        {"TogglePlayerTargetActor", TogglePlayerTargetActor},
        {"CheckVersion", CheckVersion},
        {0, 0}
    };

}