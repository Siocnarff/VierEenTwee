#ifndef RACING_RACEWEEKEND_H
#define RACING_RACEWEEKEND_H
#include "../racing/CarState.h"
#include "../racing/CarStateBroken.h"
#include "../racing/CarStateDamaged.h"
#include "../racing/CarStateFullHP.h"
//#include "DriverPitStop.h"
#include "../people/Driver.h"
#include "../eng/Car.h"
//#include "../people/Pitcrew.h"
//#include "../log/Race.h"
#include "../racing/strategy/CreateStrategy.h"
#include "../racing/Leaderboard.h"
#include "WeatherConditions.h"
#include "TrackComplexity.h"
#include "Leaderboard.h"
#include <string>
namespace rce{
class RaceWeekend {

private:
	CreateStrategy* strategy;
	Car** car;
	Driver** driver;
	Race* raceConditions;
	Container* container;
	list<Pitcrew*> pitcrew;
	std::string TeamName;
	WeatherConditions DayWeather;
	Leaderboard * team;
	Leaderboard * driver;
	CarState** CState;
	TrackComplexity TC;
	int time[2];
	int score[2];
	int speed;
	int handling;
	int xp;
	bool hometrack;
	int trackID;
	

public:
	RaceWeekend(eng::Car* cars, people::Driver* drivers, log::Race* r, strategy::CreateStategy* s, list<people::Pitcrew*> p, log::Container* c);

	int RacingWeekend();

	eng::Car* getCar(int i);

	void setCar(eng::Car* car, int i);

	Driver* getDriver(int i);

	void setDriver(people::Driver* driver, int i);

	log::Container* getContainer();

	void setContainer(log::Container* container);

	list<people::Pitcrew*> getPitcrew();

	void setPitcrew(list<people::Pitcrew*> pitcrew);

	void notifyCarState(int i);

	int getTime(int i);

	void setTime(int time, int i);

	int getScore(int i);

	void setScore(int score, int i);

	log::WeatherConditions* getDayWeather();

	void setDayWeather(log::WeatherConditions* DayWeather);

	racing::CarState* getCState(int i);

	void setCState(racing::CarState* CState, int i);
	
	void deel_Damage(int i, int d);
};
}
#endif
