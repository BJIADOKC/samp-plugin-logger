#pragma once
#pragma warning(disable:4996)



#ifdef LINUX
	#include <alloca.h>
#endif

#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <time.h>

#include <boost/bind.hpp>
#include <boost/thread.hpp>

#define HAVE_STDINT_H

#include "SDK/plugin.h"

#include "natives.h"
#include "process.h"
#include "safe_queue.h"
#include "string.h"





typedef void (*logprintf_t)(char *format, ...);


#define arguments(n) \
	(params[0] == (n << 2))





struct amxOutput
{
	std::string file;
	std::string data;
};