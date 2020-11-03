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
	lg::RiskLevel risk;
    if(strategy)
    {
        delete strategy;
        strategy=NULL;
    }
	int* tyre=new int[3];
	if(budget<25)
	{
	    risk=lg::Safe;
			tyre[0]=3;
			tyre[1]=2;
			tyre[2]=0;
			strategy=new SafeStrategy(2,tyre,risk);
			notify(tyre);
			return strategy->execute();
	}
	else if(budget>=25 && budget<50)
	{
	    risk=lg::Moderate;
        tyre[0]=2;
        tyre[1]=3;
        tyre[2]=0;
        strategy=new ModerateStrategy(2,tyre,risk);
        notify(tyre);
        return strategy->execute();
	}
	else
	{
	    risk=lg::Aggressive;
		tyre[0]=2;
		tyre[1]=2;
		tyre[2]=1;
		strategy=new AggressiveStrategy(2,tyre,risk);
        notify(tyre);
		return strategy->execute();
	}
}

ppl::Driver*  RacingDep::trainDriver(ppl::Driver * driver, int time, lg::WeatherConditions weather, lg::TrackComplexity trackDifficulty)
{
	//create simulator according to weather,track difficulty
	//train ppl::Driver (increase xp) according to track difficulty and time

	if(weather==lg::Rainy)
	{
		Simulator* wet=new SimulatorWetCondition();
		wet->setDriver(driver);
		wet->setWeather(weather);
		wet->setDifficulty(trackDifficulty);
		wet->setTime(time);
		wet->SimulateWeather();
        return driver;
	}
	else if(weather==lg::Hot)
	{
		Simulator* hot=new SimulatorHotCondition();
		hot->setDriver(driver);
		hot->setWeather(weather);
		hot->setDifficulty(trackDifficulty);
		hot->setTime(time);
		hot->SimulateWeather();
        return driver;
	}
	else if(weather==lg::Normal)
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

ppl::Driver* trainDriver(ppl::Driver * driver, int time, lg::WeatherConditions weather)
{
    if(weather==lg::Rainy)
    {
        Simulator* wet=new SimulatorWetCondition();
        wet->setDriver(driver);
        wet->setWeather(weather);
        wet->setDifficulty(lg::Average);
        wet->setTime(time);
        wet->SimulateWeather();
        return driver;
    }
    else if(weather==lg::Hot)
    {
        Simulator* hot=new SimulatorHotCondition();
        hot->setDriver(driver);
        hot->setWeather(weather);
        hot->setDifficulty(lg::Average);
        hot->setTime(time);
        hot->SimulateWeather();
        return driver;
    }
    else if(weather==lg::Normal)
    {
        Simulator* normal=new SimulatorNormalCondition();
        normal->setDriver(driver);
        normal->setWeather(weather);
        normal->setDifficulty(lg::Average);
        normal->setTime(time);
        normal->SimulateWeather();
        return driver;
    }
}

ppl::Driver* trainDriver(ppl::Driver *driver, int time, lg::TrackComplexity t)
{
        Simulator* normal=new SimulatorNormalCondition();
        normal->setDriver(driver);
        normal->setWeather(lg::Normal);
        normal->setDifficulty(t);
        normal->setTime(time);
        normal->SimulateWeather();
        return driver;
}

void RacingDep::preRaceArrival(eng::Car* c, ppl::Driver* d, lg::Race* r, lg::Container* con)
{
	// TODO unpack container
}

lg::Container* RacingDep::postRacePackUp()
{
	// TODO - pack container -- do we need to send anything?
}

CreateStrategy* RacingDep::changeStrat(lg::RiskLevel risk)
{
    if(strategy)
    {
        delete strategy;
        strategy=NULL;
    }
        int* tyre=new int[3];
    if(risk==lg::Safe)
    {
        tyre[0]=3;
        tyre[1]=2;
        tyre[2]=0;
        strategy=new SafeStrategy(2,tyre,risk);
        notify(tyre);
        return strategy->execute();
    }
    else if(risk==lg::Moderate)
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

void RacingDep::registerForSeason(lg::Observer* logisticsDept)
{
	// TODO - implement RacingDep::registerForSeason
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
