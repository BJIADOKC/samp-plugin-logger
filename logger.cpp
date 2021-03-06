#pragma once



#include "logger.h"





logprintf_t logprintf;


extern void *pAMXFunctions;
extern amxProcess *gProcess;





PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() 
{
	return (SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES);
}



PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) 
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
	
	gProcess = new amxProcess();

	logprintf("  Logger v%s by BJIADOKC loaded", PLUGIN_VERSION);

	return 1;
}



PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	logprintf("  Logger v%s by BJIADOKC unloaded", PLUGIN_VERSION);

	delete gProcess;
}



PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	return amx_Register(amx, amxNatives::loggerNatives, -1);
}



PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx) 
{
	return AMX_ERR_NONE;
}