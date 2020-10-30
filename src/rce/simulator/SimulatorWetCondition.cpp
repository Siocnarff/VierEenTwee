#include "SimulatorWetCondition.h"

void SimulatorWetCondition::SimulateWeather() 
{

	std::cout<<"Driver using simulator to train in wet conditions"<<std::endl;
	
	ppl::Driver* sav=getDriver();
	int xp=(getTrackDifficulty()/getTime())*9;
    sav->setXp(xp);
}

SimulatorWetCondition::SimulatorWetCondition()
{
	
}