#pragma once



#include "process.h"





amxProcess *gProcess;

boost::mutex gMutex;
std::queue<amxOutput> threadQueue;


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
	struct tm *timeinfo;

	time_t rawtime;
	amxOutput input;

	boost::mutex localMutex;
	std::fstream file;

	do
	{
		while(!threadQueue.empty())
		{
			boost::mutex::scoped_lock lock(localMutex);
			input = threadQueue.front();
			threadQueue.pop();
			lock.unlock();

			time(&rawtime);
			timeinfo = localtime(&rawtime);
			strftime(timeform, sizeof timeform, "%X", timeinfo);

			file.open(input.file.c_str(), (std::fstream::out | std::fstream::app));
			file << "[" << timeform << "] " << input.data << std::endl;
			file.close();

			boost::this_thread::sleep(boost::posix_time::milliseconds(1));
		}

		boost::this_thread::sleep(boost::posix_time::milliseconds(1));
	}
	while(gProcess->Active);
}