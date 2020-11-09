#include <strategy/SafeStrategy.h>
#include <strategy/ModerateStrategy.h>
#include <strategy/AggressiveStrategy.h>
#include <simulator/SimulatorWetCondition.h>
#include <simulator/SimulatorHotCondition.h>
#include <simulator/SimulatorNormalCondition.h>
#include "RacingDep.h"

#include <utility>
using namespace rce;

void RacingDep::hireEmployees(int b)
{
    ppl::HireRacingDep *PitCrewFactory=new ppl::HirePitCrew();
	ppl::HireRacingDep *StratFactory=new ppl::HireStrategist();
	Strategist=new ppl::Person* [2];
	pitcrew=new ppl::Person* [b];
    for (int i = 0; i <2 ; ++i)
    {
        Strategist[i]=StratFactory->source("racing strategist");
    }
    for (int i = 0; i <b ; ++i)
    {
        pitcrew[i]=PitCrewFactory->source("pitcrew member");
    }
}

CreateStrategy* RacingDep:: PlanSeasonStrategy(int budget)
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
			tyre[0]=3;
			tyre[1]=2;
			tyre[2]=0;
			strategy=new SafeStrategy(2,tyre,lg::Safe);
            notify(tyre);
			return strategy->execute();
	}
	else if(budget>=25 && budget<50)
	{

			tyre[0]=3;
			tyre[1]=2;
			tyre[2]=0;
            strategy=new ModerateStrategy(2,tyre,lg::Moderate);
            notify(tyre);
			return strategy->execute();

	}
	else
	{
			tyre[0]=2;
			tyre[1]=2;
			tyre[2]=1;
            strategy=new AggressiveStrategy(2,tyre,lg::Aggressive);
            notify(tyre);
			return strategy->execute();
	}
}


ppl::Driver *RacingDep::trainDriver(ppl::Driver *driver, int time, lg::WeatherConditions weather,lg::TrackComplexity trackDifficulty)
{
	//create simulator according to weather,track difficulty
	//train ppl::Driver (increase xp) according to track difficulty and time

	//net sodat nie error gee nie.
	//todo hkm kan mens nie enums hier gebruik nie?

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
	return driver;
}

ppl::Driver *RacingDep::trainDriver(ppl::Driver *driver, int time, lg::TrackComplexity trackDifficulty)
{
    Simulator* normal=new SimulatorNormalCondition();
    normal->setDriver(driver);
    normal->setWeather(lg::Normal);
    normal->setDifficulty(trackDifficulty);
    normal->setTime(time);
    normal->SimulateWeather();
    return driver;
}

ppl::Driver *RacingDep::trainDriver(ppl::Driver * driver, int time, lg::WeatherConditions weather)
{
    Simulator* normal=new SimulatorNormalCondition();
    normal->setDriver(driver);
    normal->setWeather(weather);
    normal->setDifficulty(lg::Average);
    normal->setTime(time);
    normal->SimulateWeather();
    return driver;
}

void RacingDep::preRaceArrival(std::vector<eng::Car*> c, std::vector<ppl::Driver*> d, lg::Race* r, lg::Container* con , std::vector<Tyres *> t)
{
    cars = new eng::Car*[2];
    drivers = new ppl::Driver*[2];
    tyres = new Tyres*[2];
    CarContainer = con;
    race = r;
    for(int i = 0; i < 2; i++)
    {
        tyres[i] = t[i];
        cars[i] = c[i];
        drivers[i] = d[i];
    }
//    CarContainer->print();
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
        strategy=new SafeStrategy(2,tyre,lg::Safe);
        notify(tyre);
        return strategy->execute();
    }
    else if(risk==lg::Moderate)
    {
        tyre[0]=3;
        tyre[1]=2;
        tyre[2]=0;
        strategy=new ModerateStrategy(2,tyre,lg::Moderate);
        notify(tyre);
        return strategy->execute();
    }
    else
    {
        tyre[0]=2;
        tyre[1]=2;
        tyre[2]=1;
        strategy=new AggressiveStrategy(2,tyre,lg::Aggressive);
        notify(tyre);
        return strategy->execute();
    }
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

ppl::Person** RacingDep::getStrategist()
{
    return Strategist;
}

void RacingDep::setStrategist(ppl::Person** Strategist)
{
    this->Strategist=std::move(Strategist);
}

ppl::Person** RacingDep::getPitcrew()
{
	return pitcrew;
}

void RacingDep::setPitcrew(ppl::Person** pitcrew)
{
	//mens kan nie een list net aan 'n ander assign nie. Jy moet elementwise deurgaan
    this->pitcrew = pitcrew;
}

void RacingDep::SetCarAfterRace(eng::Car* c)
{
	car=c;// todo double check
}

int * RacingDep::Race()
{
    pr::Doc::summary("  ~Racing team has arrived in " + race->getLocation());
    pr::Doc::summary("\n");
    RaceWeekend* racingWeekend= new RaceWeekend(cars, drivers, race, strategy, pitcrew, tyres, lead);
    pr::Doc::summary("  ~Setting up for racing weekend. (Unpack container)~\n");
    CarContainer->print();
    int * Score = racingWeekend->RacingWeekend();
    delete racingWeekend;
    std::vector<eng::Car*> carResult ;
    bool* k=racingWeekend->getBrokenCar();
    for(int i=0;i<2;i++)
    {
        if(k[i])
        {
            notify(cars[i],race);
        }
    }
    for(int h =0; h < 2; h++)
    {
        carResult.push_back(cars[h]);
    }
    notifybackCar(carResult,race);

    return Score;
    //ToDo final stuff for array
}

int * RacingDep::getFinalScore()
{
    return lead[0]->getFinalScore();
}


RacingDep::~RacingDep()
{
//    std::cout << "destructor" << std::endl;
}

RacingDep::RacingDep()
{
//    std::cout << "Constructor" << std::endl;
    lead = new Leaderboard*[2];
    lead[0] = new DriversLeaderboard();
    lead[1] = new TeamLeaderboard();
}

lg::Container *RacingDep::postRacePackUp()
{
    CarContainer->print();
    return CarContainer;
}

void RacingDep::getCarnotify(int i,lg::Race* r)
{
    notify(cars[i],r);
}

void RacingDep::notifybackCar(std::vector<eng::Car*> c, lg::Race *r)
{
    notify(c,r);
}



