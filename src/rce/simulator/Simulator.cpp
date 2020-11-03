#include "Simulator.h"
using namespace rce;
int Simulator::getTime()
{
	return time;
}

lg::TrackComplexity Simulator::getTrackDifficulty()
{
	return trackDifficulty;
}

lg::WeatherConditions Simulator::getWeather()
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

void Simulator::setWeather(lg::WeatherConditions w)
{
	weather=w;
}

void Simulator::setTime(int t)
{
	time=t;
}

void Simulator::setDifficulty(lg::TrackComplexity dif)
{
	trackDifficulty=dif;
}
