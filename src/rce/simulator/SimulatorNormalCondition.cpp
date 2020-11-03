#include "SimulatorNormalCondition.h"
using namespace rce;
void SimulatorNormalCondition::SimulateWeather() 
{
    int xp=0;
    int i;
    if(getTrackDifficulty()==lg::Easy)
    {
        i=2;
    }
    else if (getTrackDifficulty()==lg::Average)
    {
        i=5;
    }
    else if(getTrackDifficulty()==lg::Difficult)
    {
        i=7;
    }
    else
    {
        i=9;
    }
    std::cout<<"Driver using simulator to train in normal conditions"<<std::endl;
    xp=(getTime()/i)*3;
    getDriver()->setXp(getDriver()->getXp()+xp);
}

SimulatorNormalCondition::SimulatorNormalCondition()
{
	
}