#include <strategy/SafeStrategy.h>
#include <strategy/ModerateStrategy.h>
#include <strategy/AggressiveStrategy.h>
#include <simulator/SimulatorWetCondition.h>
#include <simulator/SimulatorHotCondition.h>
#include <simulator/SimulatorNormalCondition.h>
#include "RacingDep.h"

#include <utility>
using namespace rce;

void RacingDep::HireEmployees(int b)
{
    ppl::HirePitCrew *PitCrewFactory=new ppl::HirePitCrew();
	ppl::HireStrategist *StratFactory=new ppl::HireStrategist();
    for (int i = 0; i <2 ; ++i)
    {
        Strategist.push_back(StratFactory->source("racing strategist"));
    }
    for (int i = 0; i <b ; ++i)
    {
        pitcrew.push_back(PitCrewFactory->source("pitcrew member"));
    }
}

CreateStrategy* RacingDep::PlanSeasonStrategy(int budget)
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

//void RacingDep::trainDriver(std::string weather, ppl::Driver* driver,int trackDifficulty,int time)
ppl::Driver *RacingDep::trainDriver(ppl::Driver *driver, int time, lg::WeatherConditions)
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

ppl::Driver *RacingDep::trainDriver(ppl::Driver *, int time, lg::TrackComplexity) {
    return nullptr;
}

ppl::Driver *RacingDep::trainDriver(ppl::Driver *, int time, lg::WeatherConditions, lg::TrackComplexity) {
    return nullptr;
}

void RacingDep::preRaceArrival(eng::Car** c, ppl::Driver** d, lg::Race* r, lg::Container* con)
{
    cars = new eng::Car*[2];
	drivers = bew ppl::Driver*[2];
	CarContainer = con;
	race = r;
	for(int i = 0; i < 2; i++)
	{
		cars[i] = c[i];
		drivers[i] = d[i];
	}
	CarContainer->unpack();
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

/*void RacingDep::registerForSeason(lg::Observer* logisticsDept)
{
	// TODO - implement RacingDep::registerForSeason
	throw "Not yet implemented";
}*/

Leaderboard* RacingDep::getResults() 
{
	// TODO - implement RacingDep::getResults
	throw "Not yet implemented";
}

lg::Race* RacingDep::getRace()
{
	return this->race;
}

std::string RacingDep::getTeamName()
{
    return TeamName;
}

void RacingDep::setTeamName(std::string TeamName)
{
	this->TeamName=std::move(TeamName);
}

std::list<ppl::Person*> RacingDep::getStrategist()
{
    return Strategist;
}

void RacingDep::setStrategist(std::list<ppl::Person*> Strategist)
{
    this->Strategist=std::move(Strategist);
}

std::list<ppl::Person*> RacingDep::getPitcrew()
{
	return pitcrew;
}

void RacingDep::setPitcrew(std::list<ppl::Person*> pitcrew)
{
	//
}

void RacingDep::SetCarAfterRace(eng::Car* c)
{
	car=c;// todo double check
}

int * RacingDep::Race()
{
    RaceWeekend * racingweekend= new RaceWeekend(cars,drivers,race,strategy,pitcrew,tyres, lead);
    int * Score = racingweekend->RacingWeekend();
    delete racingweekend;
    CarContainer->pack();
    return Score;
    //ToDo final stuff for array
}

int * RacingDep::getFinalScore()
{
    return lead[0]->getFinalScore();
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




