#ifndef SIMULATORNORMALCONDITION_H
#define SIMULATORNORMALCONDITION_H

#include "Simulator.h"
using namespace rce;

class SimulatorNormalCondition :public Simulator 
{
public:
	SimulatorNormalCondition();
	void SimulateWeather();
};

#endif
