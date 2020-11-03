#ifndef RCE_RACEWEEKEND_H
#define RCE_RACEWEEKEND_H
#include "CarState.h"
#include "CarStateBroken.h"
#include "CarStateDamaged.h"
#include "CarStateFullHP.h"
//#include "DriverPitStop.h"
//#include "../people/Driver.h"
#include "Driver.h"
#include "Race.h"
#include "Car.h"
//#include "../eng/Car.h"
//#include "../people/Pitcrew.h"
//#include "../log/Race.h"
//#include "../racing/strategy/CreateStrategy.h"
//#include "../racing/Leaderboard.h"
#include "WeatherConditions.h"
#include "TrackComplexity.h"
#include "RiskLevel.h"
#include "Leaderboard.h"
#include "DriversLeaderboard.h"
#include "TeamLeaderboard.h"
#include "Container.h"
#include <string>
#include "Tyres.h"
#include <list>
//enum RiskLevel {	Safe, Moderate, Aggressive};
namespace rce{

class RaceWeekend: public lg::Colleague {

private:
	CreateStrategy* strategy;
	eng::Car** car;
	ppl::Driver** driver;
	lg::Race* raceConditions;
	rce::Pitstop ** pitstop;
	list<ppl::Pitcrew*> pitcrew;
	std::string TeamName;
	lg::WeatherConditions DayWeather;
	Leaderboard ** lead;
	CarState** CState;
	lg::TrackComplexity TC;
	int time[2];
	int score[2];
	int Damage[2];
	int speed;
	int handling[2];
	int xp;
	bool hometrack;
	int trackID;
	bool brokenstate[2];
	Tyres * tyre;
	bool tyresleft[2];
	

public:
	RaceWeekend(eng::Car** cars, ppl::Driver** drivers, lg::Race* r, rce::CreateStategy* s, list<ppl::Pitcrew*> p, Tyres* t, Leaderboard ** l);

	int * RacingWeekend();

	eng::Car* getCar(int i);

	void setCar(eng::Car* car, int i);

	ppl::Driver* getDriver(int i);

	void setDriver(ppl::Driver* driver, int i);

	list<ppl::Pitcrew*> getPitcrew();

	void setPitcrew(list<ppl::Pitcrew*> pitcrew);

	void getCarnotify(int i);

	int getTime(int i);

	void setTime(int time, int i);

	int getScore(int i);

	void setScore(int score, int i);

	lg::WeatherConditions getDayWeather();

	void setDayWeather();

	CarState* getCState(int i);

	void setCState(CarState* CState, int i);
	
	void deel_Damage(int i, int d);
	
	int getDamage(int i);
	
	void setDamage(int damage, int i);
	
	lg::RiskLevel getRiskLevel();
	
	std::string getState(int i);
	
	void ChangeState(int i);
	
};
}
#endif
