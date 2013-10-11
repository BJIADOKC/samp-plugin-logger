#pragma once



#include "natives.h"





extern logprintf_t logprintf;
extern amxString *gString;

extern boost::mutex gMutex;
extern std::queue<amxOutput> threadQueue;





const AMX_NATIVE_INFO amxNatives::loggerNatives[] =
{
	{"log", amxNatives::Log},

	{NULL, NULL}
};



// native log(file[], string[]);
cell AMX_NATIVE_CALL amxNatives::Log(AMX *amx, cell *params)
{
	if(!arguments(2))
	{
		logprintf("Logger warning: Invalid argument count (%i) in native 'log'", (params[0] >> 2));

		return NULL;
	}

	amxOutput output;

	output.file = gString->Get(amx, params[1]);
	output.data = gString->Get(amx, params[2]);

	boost::mutex::scoped_lock lock(gMutex);
	threadQueue.push(output);
	lock.unlock();

	return 1;
}