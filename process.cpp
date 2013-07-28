#pragma once



#include "process.h"





amxProcess *gProcess;

boost::safe_queue<amxOutput> threadQueue;


extern logprintf_t logprintf;





amxProcess::amxProcess()
{
	this->Active = true;

	boost::thread process(boost::bind(&amxProcess::Thread));
}



amxProcess::~amxProcess()
{
	this->Active = false;
}



void amxProcess::Thread()
{
	char timeform[16];
	time_t rawtime;
	struct tm *timeinfo;

	amxOutput input;

	std::fstream file;

	do
	{
		input = threadQueue.pop();

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(timeform, sizeof timeform, "%X", timeinfo);

		file.open(input.file.c_str(), (std::fstream::out | std::fstream::app));
		file << "[" << timeform << "] " << input.data << std::endl;
		file.close();

		boost::this_thread::sleep(boost::posix_time::milliseconds(1));
	}
	while(gProcess->Active);
}