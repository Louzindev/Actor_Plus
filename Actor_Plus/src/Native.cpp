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
        int patch = static_cast<int>(params[3]);

        if (major == MAJOR_VERSION) {
            if (minor < MINOR_VERSION) {
                logprintf("\n=============> WARNING <=============");
                logprintf("You're using an old version include for Actor_Plus");
                logprintf("Actual Version: %d.%d.%d", major, minor, patch);
                logprintf("Go to https://github.com/LouzinDeev/Actor_Plus and download the last version");
                logprintf("=============> WARNING <=============\n\n");
            }
            else if (minor > MINOR_VERSION) {
                logprintf("\n=============> WARNING <=============");
                logprintf("You're using an old version plugin for Actor_Plus");
                logprintf("Actual Version: %d.%d.%d", MAJOR_VERSION, MINOR_VERSION, PATCH_VERSION);
                logprintf("Go to https://github.com/LouzinDeev/Actor_Plus and download the last version");
                logprintf("\n=============> WARNING <=============");
            }
        }
        if (major == MAJOR_VERSION && minor == MINOR_VERSION) {
            if (patch < PATCH_VERSION) {
                logprintf("You're using an old patch include for Actor_Plus, Consider update it.");
            }
            if (patch > PATCH_VERSION) {
                logprintf("You're using an old patch plugin for Actor_Plus, Consider update it.");
            }
        }
        if (major > MAJOR_VERSION) {
            logprintf("\n=============> ERROR <=============");
            logprintf("You're using an old version plugin for Actor_Plus");
            logprintf("Actual Version: %d.%d.%d", MAJOR_VERSION, MINOR_VERSION, PATCH_VERSION);
            logprintf("Go to https://github.com/LouzinDeev/Actor_Plus and download the last version");
            logprintf("Shuting down...");
            logprintf("\n=============> ERROR <=============");
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            GameModeExit();
        }
        if (major < MAJOR_VERSION) {
            logprintf("\n=============> ERROR <=============");
            logprintf("You're using an old version include for Actor_Plus");
            logprintf("Actual Version: %d.%d.%d", major, minor, patch);
            logprintf("Go to https://github.com/LouzinDeev/Actor_Plus and download the last version");
            logprintf("Shuting down...");
            logprintf("\n=============> ERROR <=============");
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            GameModeExit();
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