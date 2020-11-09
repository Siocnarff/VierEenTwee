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
    pr::Doc::detail("     Racing department is hiring employees\n");
    ppl::HumanResources *PitCrewFactory=new ppl::HirePitCrew();
	ppl::HumanResources *StratFactory=new ppl::HireStrategist();
	Strategist=new ppl::Person* [2];
	pitcrew=new ppl::Person* [b];
    for (int i = 0; i <2 ; ++i)
    {
        Strategist[i]=StratFactory->hire("racing strategist");
    }
    for (int i = 0; i <b ; ++i)
    {
        pitcrew[i]=PitCrewFactory->hire("pitcrew member");
    }
    delete PitCrewFactory;
    delete StratFactory;
}

CreateStrategy* RacingDep::PlanSeasonStrategy(int budget)
{
	//safe ,moderate ,aggressive

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
    std::string output = driver->getName();
    output.append(" is training.\n");
    pr::Doc::detail("     ");
    pr::Doc::detail(output);
    output = "";
    Simulator* simulator;
	if(weather==lg::Rainy)
	{
        simulator=new SimulatorWetCondition();
	}
	else if(weather==lg::Hot)
	{
        simulator=new SimulatorHotCondition();
	}
	else if(weather==lg::Normal)
	{
        simulator=new SimulatorNormalCondition();
	}
    simulator->setDriver(driver);
    simulator->setWeather(weather);
    simulator->setDifficulty(trackDifficulty);
    simulator->setTime(time);
    simulator->run();
    delete simulator;
    return driver;
}

ppl::Driver *RacingDep::trainDriver(ppl::Driver *driver, int time, lg::TrackComplexity trackDifficulty)
{
    std::string output = driver->getName();
    output.append(" is training.\n");
    pr::Doc::summary(output);
    output = "";
    Simulator* normal=new SimulatorNormalCondition();
    normal->setDriver(driver);
    normal->setWeather(lg::Normal);
    normal->setDifficulty(trackDifficulty);
    normal->setTime(time);
    normal->run();
    delete normal;
    return driver;
}

ppl::Driver *RacingDep::trainDriver(ppl::Driver * driver, int time, lg::WeatherConditions weather)
{
    std::string output = driver->getName();
    output.append(" is training.\n");
    pr::Doc::summary(output);
    output = "";
    Simulator* normal=new SimulatorNormalCondition();
    normal->setDriver(driver);
    normal->setWeather(weather);
    normal->setDifficulty(lg::Average);
    normal->setTime(time);
    normal->run();
    delete normal;
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
    for (int i = 0; i < 3; ++i)
    {
        tyres[i] = t[i];
    }
    std::string output = "Unpacking container---------------------------------------------\n";
    pr::Doc::detail(output);
    output = "";
    if(pr::Doc::transparency == 1 || pr::Doc::transparency == 2)
    {
        CarContainer->print();
    }
}

CreateStrategy* RacingDep::changeStrat(lg::RiskLevel risk)
{

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
	car=c;//
}

int * RacingDep::Race()
{
    pr::Doc::summary("  ~Racing team has arrived in " + race->getLocation());
    pr::Doc::summary("\n");
//    lead[0]->setDriver(drivers[0]->getName(), drivers[1]->getName());
    RaceWeekend * racingweekend= new RaceWeekend(cars,drivers,race,strategy,pitcrew,tyres, lead);
    int * Score = racingweekend->RacingWeekend();
//    delete racingweekend;
    pr::Doc::summary("  ~Setting up for racing weekend. (Unpack container)~\n");
    CarContainer->print();
    std::vector<eng::Car*> carresult ;
    bool* k=racingweekend->getBrokenCar();
    for(int i=0;i<2;i++)
    {
        if(k[i])
        {
            notify(cars[i],race);
        }
    }
    for(int h =0; h < 2; h++)
    {
	if(!k[h])
	{
        carresult.push_back(cars[h]);
	}
    }
	if(!carresult.empty())
	{
   		 notifybackCar(carresult,race);
	}
    delete racingweekend;
    return Score;

}

int * RacingDep::getFinalScore()
{
    int *k= lead[0]->getFinalScore();
    return lead[0]->getFinalScore();
}


RacingDep::~RacingDep()
{

    for (int i = 0; i <2; ++i)
    {
        delete Strategist[i];
    }
    delete []Strategist;
    for (int i = 0; i < sizeof(pitcrew); ++i)
    {
        delete pitcrew[i];
    }
    delete []pitcrew;
    for (int i = 0; i < 2; ++i)
    {
//       delete tyres[i];
        delete lead[i];
    }
//    delete []tyres;
    delete []lead;
}

RacingDep::RacingDep()
{
    lead = new Leaderboard*[2];
    lead[0] = new DriversLeaderboard();
    lead[1] = new TeamLeaderboard();
}

lg::Container *RacingDep::postRacePackUp()
{
    std::string output = "Packing container---------------------------------------------\n";
    pr::Doc::detail(output);
    output = "";
    if(pr::Doc::transparency == 1 || pr::Doc::transparency == 2)
    {
        CarContainer->print();
    }
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



