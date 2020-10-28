#include "Simulator.h"

// void Simulator::trainDriver(string weather, ppl::Driver* driver,int trackDifficulty,int time) 
// {
// 	this->weather=weather;
// 	this->driver=driver;
// 	this->time=time;
// 	this->trackDifficulty=trackDifficulty;
// }

int Simulator::getTime()
{
	return time;
}

int Simulator::getTrackDifficulty()
{
	return trackDifficulty;
}

string Simulator::getWeather()
{
	return weather;
}

ppl::Driver* Simulator::getDriver()
{
	return this->driver;
}

void Simulator::setDriver(ppl::Driver* d)
{
	driver=d;
}

void Simulator::setWeather(string w)
{
	weather=w;
}

void Simulator::setTime(int t)
{
	time=t;
}

void Simulator::setDifficulty(int dif)
{
	trackDifficulty=dif;
}
