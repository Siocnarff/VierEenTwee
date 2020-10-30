#include "Simulator.h"
using namespace rce;
int Simulator::getTime()
{
	return time;
}

log::TrackComplexity Simulator::getTrackDifficulty()
{
	return trackDifficulty;
}

log::WeatherConditions Simulator::getWeather()
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

void Simulator::setWeather(log::WeatherConditions w)
{
	weather=w;
}

void Simulator::setTime(int t)
{
	time=t;
}

void Simulator::setDifficulty(log::TrackComplexity dif)
{
	trackDifficulty=dif;
}
