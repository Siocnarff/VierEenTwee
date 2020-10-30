#include "SimulatorHotCondition.h"
using namespace rce;
SimulatorHotCondition::SimulatorHotCondition()
{

}

void SimulatorHotCondition::SimulateWeather() 
{
	int xp=0;
	std::cout<<"Driver using simulator to train in hot conditions"<<std::endl;
	xp=(getTrackDifficulty()/getTime())*6;
	getDriver()->setXp(getDriver()->getXp()+xp);
}
