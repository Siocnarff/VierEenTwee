#include <rce/strategy/AggressiveStrategy.h>
#include <rce/strategy/ModerateStrategy.h>
#include <rce/strategy/SafeStrategy.h>
#include <ppl/specialists/Driver.h>
#include <log/enums/WeatherConditions.h>
#include <rce/simulator/Simulator.h>
#include <rce/simulator/SimulatorWetCondition.h>
#include <rce/simulator/SimulatorNormalCondition.h>
#include <rce/simulator/SimulatorHotCondition.h>
#include <eng/Car.h>
#include <log/races/Race.h>
#include <log/races/Container.h>
#include "RacingDep.h"

using namespace rce;

void RacingDep::hireEmployees(int b)
{
	// TODO - implement RacingDep::HireWorker
	throw "Not yet implemented";
}

//CreateStrategy* RacingDep::PlanSeasonStrategy(int budget,std::string weather,int riskLevel)
rce::CreateStrategy *RacingDep::PlanSeasonStrategy(int budget)
{
    //Net sodat die code nie aan log se kant so baie errors het nie
    std::string weather = "";
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

//void RacingDep::trainDriver(std::string weather, ppl::Driver* driver,int trackDifficulty,int time)
ppl::Driver *RacingDep::trainDriver(ppl::Driver *driver, int time, log::WeatherConditions)
{
	//create simulator according to weather,track difficulty
	//train ppl::Driver (increase xp) according to track difficulty and time

	//net sodat nie error gee nie.
	std::string weather = "";
	int trackDifficulty = -1;

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

ppl::Driver *RacingDep::trainDriver(ppl::Driver *, int time, log::TrackComplexity) {
    return nullptr;
}

ppl::Driver *RacingDep::trainDriver(ppl::Driver *, int time, log::WeatherConditions, log::TrackComplexity) {
    return nullptr;
}

void RacingDep::preRaceArrival(eng::Car** c, ppl::Driver** d, log::Race* r, log::Container* con)
{
	// TODO - implement RacingDep::preRaceArrival
	//throw "Not yet implemented";
}

/*int RacingDep::RacingWeekend()
{
	// TODO - implement RacingDep::Race
	throw "Not yet implemented";
}*/

/*void RacingDep::postRacePackUp()
{
	// TODO - implement RacingDep::postRacePackUp
	throw "Not yet implemented";
}*/

/*void RacingDep::registerForSeason(log::Observer* logisticsDept)
{
	// TODO - implement RacingDep::registerForSeason
	throw "Not yet implemented";
}*/

Leaderboard* RacingDep::getResults() 
{
	// TODO - implement RacingDep::getResults
	throw "Not yet implemented";
}

log::Race* RacingDep::getRace()
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
	//return this->pitcrew;
}

void RacingDep::setPitcrew(std::list<ppl::Person*> pitcrew)
{
	//mens kan nie een list net aan 'n ander assign nie. Jy moet elementwise deurgaan
    //this->pitcrew = pitcrew;
}

void RacingDep::SetCarAfterRace() 
{
	// TODO - implement RacingDep::SetCarAfterRace
	throw "Not yet implemented";
}

int *RacingDep::RacingWeekend() {
    return nullptr;
}

log::Container *RacingDep::postRacePackUp() {
    return nullptr;
}

RacingDep::~RacingDep() {

}

RacingDep::RacingDep() {
    std::cout << "Constructor" << std::endl;
}

int *RacingDep::getFinalResults() {
    //return array {score1,postition1,score2, postion2}
    throw "Not yet implemented";
}




