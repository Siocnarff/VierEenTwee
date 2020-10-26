#ifndef RACINGDEP_H
#define RACINGDEP_H

#include "Simulator.h"
#include "SimulatorHotCondition.h"
#include "SimulatorNormalCondition.h"
#include "SimulatorWetCondition.h"

#include "CreateStategy.h"
#include "Driver.h"
#include <string>
class RacingDep 
{

private:
	int risklevel;
	int budget;
	Race* race;
	int results;
	CreateStategy* strategy;
	Container* CarContainer;
	string TeamName;
	list<Person*> Stategist;
	list<Person*> pitcrew;
	Car* car;
	
/// driver array of size 2?
/// car array of size 2? 
/// different strategies for each driver and car?
public:
	void HireEmployees(int b);
	CreateStrategy* PlanSeasonStrategy(int budget);//weather
	void trainDriver(string weather, Driver* driver,int trackDifficulty,int time);//weather and time 
	void preRaceArrival(Car* c, Driver* d, Race* r, Container* con);
	int RacingWeekend();// why is it an int?
	void postRacePackUp();// return the container with tires in
	
	void registerForSeason(Observer* logisticsDept);// is it needed
	
	Leaderboard* getResults();
	void setResult(int result);
	int getResult();

	Race* getRace();
	string getTeamName();
	void setTeamName(string TeamName);
	void SetCarAfterRace();

	list<Person*> getStategist();
	void setStategist(list<Person*> Stategist);
	list<Person*> getPitcrew();
	void setPitcrew(list<Person*> pitcrew);
};

#endif
