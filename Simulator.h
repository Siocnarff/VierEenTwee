#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <string>
#include <iostream>
#include "Driver.h"
class Simulator 
{
private:
	Driver* driver;
	string weather;
	int time;
	int trackDifficulty;
public:
	void trainDriver(string weather, Driver* driver,int trackDifficulty,int time);
	virtual void SimulateWeather()=0;
	int getTime();
	int getTrackDifficulty();
	string getWeather();
	Driver* getDriver();
};
#endif