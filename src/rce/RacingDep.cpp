#include "RacingDep.h"

using namespace rce;

void RacingDep::HireEmployees(int b) 
{
	// TODO - implement RacingDep::HireWorker
	throw "Not yet implemented";
}

CreateStrategy* RacingDep::PlanSeasonStrategy(int budget,string weather,int riskLevel) 
{
	//safe ,moderate ,aggressive
    if(strategy)
    {
        delete strategy;
        strategy=NULL;
    }
	int* tyre=new int[3];
	if(budget<25)
	{
		if(weather=="rainy")
		{	tyre[0]=3;
			tyre[1]=2;
			tyre[2]=0;
			strategy=new SafeStrategy(2,tyre,15);
			return strategy->execute();
		}
		else
		{
			tyre[0]=2;
			tyre[1]=3;
			tyre[2]=0;
            strategy=new ModerateStrategy(2,tyre,30);
			return strategy->execute();
		}
	}
	else if(budget>=25 && budget<50)
	{
		if(weather=="rainy")
		{
			tyre[0]=3;
			tyre[1]=2;
			tyre[2]=0;
            strategy=new ModerateStrategy(2,tyre,45);
			return strategy->execute();
		}
		else 
		{
			tyre[0]=0;
			tyre[1]=2;
			tyre[2]=3;
            strategy=new AggressiveStrategy(1,tyre,60);
			return strategy->execute();
		}
	}
	else
	{
		if(weather=="rainy")
		{
			tyre[0]=3;
			tyre[1]=2;
			tyre[2]=0;
            strategy=new ModerateStrategy(1,tyre,75);
			return strategy->execute();
		}
		else
		{
			tyre[0]=2;
			tyre[1]=2;
			tyre[2]=1;
            strategy=new AggressiveStrategy(2,tyre,90);
			return strategy->execute();
		}
	}
}

void RacingDep::trainDriver(string weather, ppl::Driver* driver,int trackDifficulty,int time) 
{
	//create simulator according to weather,track difficulty
	//train ppl::Driver (increase xp) according to track difficulty and time

	if(weather=="wet")
	{
		Simulator* wet=new SimulatorWetCondition();
		wet->setDriver(driver);
		wet->setWeather(weather);
		wet->setDifficulty(trackDifficulty);
		wet->setTime(time);
		wet->SimulateWeather();
	}
	else if(weather=="hot")
	{
		Simulator* hot=new SimulatorHotCondition();
		hot->setDriver(driver);
		hot->setWeather(weather);
		hot->setDifficulty(trackDifficulty);
		hot->setTime(time);
		hot->SimulateWeather();
	}
	else if(weather=="normal")
	{
		Simulator* normal=new SimulatorNormalCondition();
		normal->setDriver(driver);
		normal->setWeather(weather);
		normal->setDifficulty(trackDifficulty);
		normal->setTime(time);
		normal->SimulateWeather();
	}
}

void RacingDep::preRaceArrival(eng::Car* c, ppl::Driver* d, Race* r, Container* con)
{
	// TODO - implement RacingDep::preRaceArrival
	throw "Not yet implemented";
}

int RacingDep::RacingWeekend() 
{
	// TODO - implement RacingDep::Race
	throw "Not yet implemented";
}

void RacingDep::postRacePackUp() 
{
	// TODO - implement RacingDep::postRacePackUp
	throw "Not yet implemented";
}

void RacingDep::registerForSeason(Observer* logisticsDept) 
{
	// TODO - implement RacingDep::registerForSeason
	throw "Not yet implemented";
}

Leaderboard* RacingDep::getResults() 
{
	// TODO - implement RacingDep::getResults
	throw "Not yet implemented";
}

Race* RacingDep::getRace() 
{
	return this->race;
}

void RacingDep::setResult(int result) 
{
	// TODO - implement RacingDep::setResult
	throw "Not yet implemented";
}

int RacingDep::getResult() 
{
	// TODO - implement RacingDep::getResult
	throw "Not yet implemented";
}

string RacingDep::getTeamName() 
{
	// TODO - implement RacingDep::getTeamName
	throw "Not yet implemented";
}

void RacingDep::setTeamName(string TeamName) 
{
	// TODO - implement RacingDep::setTeamName
	throw "Not yet implemented";
}

list<ppl::Person*> RacingDep::getStategist() 
{
	// TODO - implement RacingDep::getStategist
	throw "Not yet implemented";
}

void RacingDep::setStategist(list<ppl::Person*> Stategist) 
{
	// TODO - implement RacingDep::setStategist
	throw "Not yet implemented";
}

list<ppl::Person*> RacingDep::getPitcrew() 
{
	return this->pitcrew;
}

void RacingDep::setPitcrew(list<ppl::Person*> pitcrew) 
{
	this->pitcrew = pitcrew;
}

void RacingDep::SetCarAfterRace() 
{
	// TODO - implement RacingDep::SetCarAfterRace
	throw "Not yet implemented";
}
