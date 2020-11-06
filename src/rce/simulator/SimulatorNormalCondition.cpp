#include <Doc.h>
#include "SimulatorNormalCondition.h"
using namespace rce;
void SimulatorNormalCondition::SimulateWeather() 
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

   pr::Doc::detail("Driver using simulator to train in normal conditions\n");
    xp=i*(((getTime()/5)/100)*3);
    if(getDriver()->getXp()+xp>=100)
    {
        getDriver()->setXp(100);
    }
    else
    {
        getDriver()->setXp(getDriver()->getXp()+xp);
    }
}

SimulatorNormalCondition::SimulatorNormalCondition()
{
	
}