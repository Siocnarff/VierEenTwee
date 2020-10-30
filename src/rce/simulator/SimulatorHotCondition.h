#ifndef SIMULATORHOTCONDITION_H
#define SIMULATORHOTCONDITION_H

#include "Simulator.h"
using namespace rce;

class SimulatorHotCondition :public Simulator 
{

public:
	SimulatorHotCondition();
	void SimulateWeather();
};
#endif
