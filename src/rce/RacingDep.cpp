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
			notify(tyre);
			return strategy->execute();
	}
	else if(budget>=25 && budget<50)
	{
	    risk=log::Moderate;
        tyre[0]=2;
        tyre[1]=3;
        tyre[2]=0;
        strategy=new ModerateStrategy(2,tyre,risk);
        notify(tyre);
        return strategy->execute();
	}
	else
	{
	    risk=log::Aggressive;
		tyre[0]=2;
		tyre[1]=2;
		tyre[2]=1;
		strategy=new AggressiveStrategy(2,tyre,risk);
        notify(tyre);
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

void RacingDep::preRaceArrival(eng::Car* c, ppl::Driver* d, log::Race* r, Container* con)
{
	// TODO unpack container
}

void RacingDep::postRacePackUp()
{
	// TODO - pack container -- do we need to send anything?
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
        notify(tyre);
        return strategy->execute();
    }
    else if(risk==log::Moderate)
    {
        tyre[0]=2;
        tyre[1]=3;
        tyre[2]=0;
        strategy=new ModerateStrategy(2,tyre,risk);
        notify(tyre);
        return strategy->execute();
    }
    else
    {
        tyre[0]=2;
        tyre[1]=2;
        tyre[2]=1;
        strategy=new AggressiveStrategy(2,tyre,risk);
        notify(tyre);
        return strategy->execute();
    }
}

void RacingDep::registerForSeason(Observer* logisticsDept)
{
	// TODO - implement RacingDep::registerForSeason
}

log::Race* RacingDep::getRace()
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
