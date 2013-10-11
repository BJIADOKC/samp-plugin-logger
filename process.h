#pragma once



#include "logger.h"





class amxProcess
{

public:

	bool Active;

	amxProcess();
	~amxProcess(); // removed virtual, g++ crashes

	static void Thread();
};