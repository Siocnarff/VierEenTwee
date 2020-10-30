#include "RacingDep.h"

using namespace rce;

void RacingDep::HireEmployees(int b) 
{
	// TODO - implement RacingDep::HireWorker
	throw "Not yet implemented";
}

CreateStrategy* RacingDep::PlanSeasonStrategy(int budget)
{
	// TODO - implement RacingDep::PlanSeasonStrategy
	throw "Not yet implemented";
}

void RacingDep::trainDriver(string weather, ppl::Driver* driver,int trackDifficulty,int time) 
{
	//create simulator according to weather,track difficulty
	//train ppl::Driver (increase xp) according to track difficulty and time
	this->driver= driver;
	this->weather= weather;
	this->time= time;
	this->trackDifficulty= trackDifficulty;

	if(weather=="wet")
	{
		Simulator* wet=new SimulatorWetCondition();
		wet->SimulateWeather();
	}
	else if(weather=="hot")
	{
		Simulator* hot=new SimulatorHotCondition();
		hot->SimulateWeather();
	}
	else if(weather=="normal")
	{
		Simulator* normal=new SimulatorNormalCondition();
		normal->SimulateWeather();
	}
}

void RacingDep::preRaceArrival(eng::Car *c, ppl::Driver *d, Race *r, Container *con) {
    std::cout << "arrive at destination" << std::endl;
    car  = c;
    driver = d;
    race = r;
    container = con;
}

int RacingDep::RacingWeekend() {
    std::cout << "Let's start"<<std::endl;
    notify(new eng::Car(0));
    std::cout << "strat packing up" << std::endl;
    notify(new log::Container);
    std::cout << "smoke a cigarette" << std::endl;

    return 5;
}

log::Container* RacingDep::postRacePackUp() { //make container*
    std::cout << container->getState();
    container->unpack();
    container->advanceState();
    std::cout << container->getState();
    return new Container;

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

RacingDep::RacingDep(log::Mediator *mediator) : Colleague(mediator) {}
