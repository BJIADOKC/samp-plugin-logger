#pragma once



#include "string.h"





amxString *gString;





void amxString::Set(AMX *amx, cell param, std::string str)
{
	cell *destination;

	amx_GetAddr(amx, param, &destination);
	amx_SetString(destination, str.c_str(), NULL, NULL, str.length());
}



std::string amxString::Get(AMX *amx, cell param)
{
	char *dest = NULL;

	amx_StrParam(amx, param, dest);

	return std::string(dest);
}