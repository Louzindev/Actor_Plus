#include "main.h"
#include "Native.h"
#include "ActorPlus.h"

logprintf_t logprintf;
extern void* pAMXFunctions;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES | sampgdk::Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData) {
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

    logprintf(" * ActorPlus %d.%d loaded\n\tAuthor: LouzinDeev", MAJOR_VERSION, MINOR_VERSION);
    return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
    logprintf(" * ActorPlus %d.%d unloaded.", MAJOR_VERSION, MINOR_VERSION);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx) {
    return amx_Register(amx, Native::PluginNatives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx) {
    return AMX_ERR_NONE;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit() {
    actor_p::GetServerActors();
    return true;
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
    sampgdk::ProcessTick();
}


