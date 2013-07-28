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

	logprintf("  Logger v1.0 loaded");

	return 1;
}



PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	delete gProcess;

	logprintf("  Logger v1.0 unloaded");
}



PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	return amx_Register(amx, amxNatives::loggerNatives, -1);
}



PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx) 
{
	return AMX_ERR_NONE;
}