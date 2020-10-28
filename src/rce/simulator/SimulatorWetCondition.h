#ifndef SIMULATORWETCONDITION_H
#define SIMULATORWETCONDITION_H

#include "Simulator.h"

class SimulatorWetCondition :public Simulator 
{
public:
	SimulatorWetCondition();
	void SimulateWeather();
};

#endif
