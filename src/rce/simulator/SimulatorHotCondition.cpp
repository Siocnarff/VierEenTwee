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

    std::string output = "\t\tDriver using simulator to train in hot conditions\n";
    pr::Doc::detail(output);
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
