#pragma once



#include "logger.h"





class amxNatives
{

public:

	static const AMX_NATIVE_INFO loggerNatives[];

	static cell AMX_NATIVE_CALL Log(AMX *amx, cell *params);
};