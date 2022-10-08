#include "main.h"
#include "Native.h"


logprintf_t logprintf;
extern void* pAMXFunctions;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData) {
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

    logprintf(" * Test plugin was loaded.");
    return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
    logprintf(" * Test plugin was unloaded.");
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx) {
    return amx_Register(amx, Native::PluginNatives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx) {
    return AMX_ERR_NONE;
}

