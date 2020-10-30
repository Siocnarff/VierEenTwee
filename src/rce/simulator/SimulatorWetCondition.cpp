#include "SimulatorWetCondition.h"
using namespace rce;
void SimulatorWetCondition::SimulateWeather() 
{
    int xp=0;
    int i;
    if(getTrackDifficulty()==log::Easy)
    {
        i=2;
    }
    else if (getTrackDifficulty()==log::Average)
    {
        i=5;
    }
    else if(getTrackDifficulty()==log::Difficult)
    {
        i=7;
    }
    else
    {
        i=9;
    }
    std::cout<<"Driver using simulator to train in hot conditions"<<std::endl;
    xp=(getTime()/i)*9;
    getDriver()->setXp(getDriver()->getXp()+xp);
}

SimulatorWetCondition::SimulatorWetCondition()
{
	
}