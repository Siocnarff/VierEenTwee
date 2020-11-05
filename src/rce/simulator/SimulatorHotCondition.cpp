#include "SimulatorHotCondition.h"
using namespace rce;
SimulatorHotCondition::SimulatorHotCondition()
{

}

void SimulatorHotCondition::SimulateWeather() 
{
	int xp=0;
	int i=0;
	if(getTrackDifficulty()==lg::Easy)
    {

    }
	else if (getTrackDifficulty()==lg::Average)
    {

    }
	else if(getTrackDifficulty()==lg::Difficult)
    {

    }
	else
    {
	    i=5;
    }
	std::cout<<"Driver using simulator to train in hot conditions"<<std::endl;
	xp=(getTime()/i)*6;
	getDriver()->setXp(getDriver()->getXp()+xp);
}
