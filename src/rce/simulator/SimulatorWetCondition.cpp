#include "SimulatorWetCondition.h"

void SimulatorWetCondition::SimulateWeather() 
{
	int xp=0;
	std::cout<<"Driver using simulator to train in wet conditions"<<std::endl;
	// xp=(getTrackDifficulty()/getTime())*9;

	int hold=getDriver()->getXp()+xp;
    getDriver()->setXp(hold);
	
}

SimulatorWetCondition::SimulatorWetCondition()
{
	
}