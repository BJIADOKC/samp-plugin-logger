#pragma once



#include "logger.h"





class amxProcess
{

public:

	bool Active;

	amxProcess();
	virtual ~amxProcess();

	static void Thread();
};