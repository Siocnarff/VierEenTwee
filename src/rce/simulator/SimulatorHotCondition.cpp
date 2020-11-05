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
        i=5;
    }
	else if (getTrackDifficulty()==lg::Average)
    {
        i=10;
    }
	else if(getTrackDifficulty()==lg::Difficult)
    {
        i=15;
    }
	else
    {
	    i=20;
    }
	std::cout<<"Driver using simulator to train in hot conditions"<<std::endl;
	xp=i*(((getTime()/5)/100)*6);
	if(getDriver()->getXp()+xp>=100)
    {
        getDriver()->setXp(100);
    }
	else
    {
        getDriver()->setXp(getDriver()->getXp()+xp);
    }

}
