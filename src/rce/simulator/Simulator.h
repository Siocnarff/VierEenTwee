#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <string>
#include <iostream>
#include "Driver.h"
using namespace std;
class Simulator 
{
private:
	ppl::Driver* driver;
	string weather;
	int time;
	int trackDifficulty;
public:
	void trainDriver(string weather, ppl::Driver* driver,int trackDifficulty,int time);
	virtual void SimulateWeather()=0;
	int getTime();
	int getTrackDifficulty();
	string getWeather();
	ppl::Driver* getDriver();
};
#endif