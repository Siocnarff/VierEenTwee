#include "RacingDep.h"
using namespace rce;

void RacingDep::HireEmployees(int b)
{
	// TODO - implement RacingDep::HireWorker
	throw "Not yet implemented";
}

CreateStrategy* RacingDep::PlanSeasonStrategy(int budget)
{
	//safe ,moderate ,aggressive
	log::RiskLevel risk;
    if(strategy)
    {
        delete strategy;
        strategy=NULL;
    }
	int* tyre=new int[3];
	if(budget<25)
	{
	    risk=log::Safe;
			tyre[0]=3;
			tyre[1]=2;
			tyre[2]=0;
			strategy=new SafeStrategy(2,tyre,risk);
			return strategy->execute();
	}
	else if(budget>=25 && budget<50)
	{
	    risk=log::Moderate;
        tyre[0]=2;
        tyre[1]=3;
        tyre[2]=0;
        strategy=new ModerateStrategy(2,tyre,risk);
        return strategy->execute();
	}
	else
	{
	    risk=log::Aggressive;
		tyre[0]=2;
		tyre[1]=2;
		tyre[2]=1;
		strategy=new AggressiveStrategy(2,tyre,risk);
		return strategy->execute();
	}
}

ppl::Driver*  RacingDep::trainDriver(ppl::Driver * driver, int time, log::WeatherConditions weather, log::TrackComplexity trackDifficulty)
{
	//create simulator according to weather,track difficulty
	//train ppl::Driver (increase xp) according to track difficulty and time

	if(weather==log::Rainy)
	{
		Simulator* wet=new SimulatorWetCondition();
		wet->setDriver(driver);
		wet->setWeather(weather);
		wet->setDifficulty(trackDifficulty);
		wet->setTime(time);
		wet->SimulateWeather();
        return driver;
	}
	else if(weather==log::Hot)
	{
		Simulator* hot=new SimulatorHotCondition();
		hot->setDriver(driver);
		hot->setWeather(weather);
		hot->setDifficulty(trackDifficulty);
		hot->setTime(time);
		hot->SimulateWeather();
        return driver;
	}
	else if(weather==log::Normal)
	{
		Simulator* normal=new SimulatorNormalCondition();
		normal->setDriver(driver);
		normal->setWeather(weather);
		normal->setDifficulty(trackDifficulty);
		normal->setTime(time);
		normal->SimulateWeather();
        return driver;
    }
}

ppl::Driver* trainDriver(ppl::Driver * driver, int time, log::WeatherConditions weather)
{
    if(weather==log::Rainy)
    {
        Simulator* wet=new SimulatorWetCondition();
        wet->setDriver(driver);
        wet->setWeather(weather);
        wet->setDifficulty(log::Average);
        wet->setTime(time);
        wet->SimulateWeather();
        return driver;
    }
    else if(weather==log::Hot)
    {
        Simulator* hot=new SimulatorHotCondition();
        hot->setDriver(driver);
        hot->setWeather(weather);
        hot->setDifficulty(log::Average);
        hot->setTime(time);
        hot->SimulateWeather();
        return driver;
    }
    else if(weather==log::Normal)
    {
        Simulator* normal=new SimulatorNormalCondition();
        normal->setDriver(driver);
        normal->setWeather(weather);
        normal->setDifficulty(log::Average);
        normal->setTime(time);
        normal->SimulateWeather();
        return driver;
    }
}

ppl::Driver* trainDriver(ppl::Driver *driver, int time, log::TrackComplexity t)
{
        Simulator* normal=new SimulatorNormalCondition();
        normal->setDriver(driver);
        normal->setWeather(log::Normal);
        normal->setDifficulty(t);
        normal->setTime(time);
        normal->SimulateWeather();
        return driver;
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

CreateStrategy* RacingDep::changeStrat(log::RiskLevel risk)
{
    if(strategy)
    {
        delete strategy;
        strategy=NULL;
    }
        int* tyre=new int[3];
    if(risk==log::Safe)
    {
        tyre[0]=3;
        tyre[1]=2;
        tyre[2]=0;
        strategy=new SafeStrategy(2,tyre,risk);
        return strategy->execute();
    }
    else if(risk==log::Moderate)
    {
        tyre[0]=2;
        tyre[1]=3;
        tyre[2]=0;
        strategy=new ModerateStrategy(2,tyre,risk);
        return strategy->execute();
    }
    else
    {
        tyre[0]=2;
        tyre[1]=2;
        tyre[2]=1;
        strategy=new AggressiveStrategy(2,tyre,risk);
        return strategy->execute();
    }
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

std::string RacingDep::getTeamName()
{
	// TODO - implement RacingDep::getTeamName
	throw "Not yet implemented";
}

void RacingDep::setTeamName(std::string TeamName)
{
	// TODO - implement RacingDep::setTeamName
	throw "Not yet implemented";
}

std::list<ppl::Person*> RacingDep::getStategist()
{
	// TODO - implement RacingDep::getStategist
	throw "Not yet implemented";
}

void RacingDep::setStategist(std::list<ppl::Person*> Stategist)
{
	// TODO - implement RacingDep::setStategist
	throw "Not yet implemented";
}

std::list<ppl::Person*> RacingDep::getPitcrew()
{
	return this->pitcrew;
}

void RacingDep::setPitcrew(std::list<ppl::Person*> pitcrew)
{
	this->pitcrew = pitcrew;
}

void RacingDep::SetCarAfterRace()
{
	// TODO - implement RacingDep::SetCarAfterRace
	throw "Not yet implemented";
}
