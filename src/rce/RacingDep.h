#ifndef RACINGDEP_H
#define RACINGDEP_H

#include "Simulator.h"
#include "SimulatorHotCondition.h"
#include "SimulatorNormalCondition.h"
#include "SimulatorWetCondition.h"

#include "CreateStrategy.h"
#include "Driver.h"

#include <string>
#include <list>
class RacingDep 
{

private:
	int risklevel;
	int budget;
	Race* race;
	int results;
	CreateStrategy* strategy;
	Container* CarContainer;
	string TeamName;
	list<ppl::Person*> Stategist;
	list<ppl::Person*> pitcrew;
	Car* car;
	
/// ppl::Driver array of size 2?
/// car array of size 2? 
/// different strategies for each ppl::Driver and car?
public:
	void HireEmployees(int b);
	CreateStrategy* PlanSeasonStrategy(int budget);//weather
	void trainDriver(string weather, ppl::Driver* ppl::Driver,int trackDifficulty,int time);//weather and time 
	void preRaceArrival(Car* c, ppl::Driver* d, Race* r, Container* con);
	int RacingWeekend();// why is it an int?
	void postRacePackUp();// return the container with tires in
	
	void registerForSeason(Observer* logisticsDept);// is it needed?
	
	Leaderboard* getResults();
	void setResult(int result);
	int getResult();

	Race* getRace();
	string getTeamName();
	void setTeamName(string TeamName);
	void SetCarAfterRace();

	list<ppl::Person*> getStategist();
	void setStategist(list<ppl::Person*> Stategist);
	list<ppl::Person*> getPitcrew();
	void setPitcrew(list<ppl::Person*> pitcrew);
};

#endif
