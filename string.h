#pragma once



#include "logger.h"





class amxString
{

public:

	void Set(AMX *amx, cell param, std::string str);
	std::string Get(AMX *amx, cell param);
};