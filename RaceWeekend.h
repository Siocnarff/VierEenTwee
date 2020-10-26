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
#include <string>
namespace racing{
class RaceWeekend {

private:
	racing::CreateStrategy* strategy;
	eng::Car* car[];
	people::Driver* driver[];
	log::Race* raceConditions;
	log::Container* container;
	list<people::Pitcrew*> pitcrew;
	std::string TeamName;
	log::WeatherConditions* DayWeather;
	racing::CarState* CState[];
	int time[];
	int score[];

public:
	RaceWeekend(eng::Car* cars, people::Driver* drivers, log::Race* r, strategy::CreateStategy* s, list<people::Pitcrew*> p, log::Container* c);

	racing::Leaderboard* Race();

	eng::Car* getCar(int i);

	void setCar(eng::Car* car, int i);

	Driver* getDriver(int i);

	void setDriver(people::Driver* driver, int i);

	log::Container* getContainer();

	void setContainer(log::Container* container);

	list<people::Pitcrew*> getPitcrew();

	void setPitcrew(list<people::Pitcrew*> pitcrew);

	void notifyCarState();

	int getTime(int i);

	void setTime(int time, int i);

	int getScore(int i);

	void setScore(int score, int i);

	log::WeatherConditions* getDayWeather();

	void setDayWeather(log::WeatherConditions* DayWeather);

	racing::CarState* getCState(int i);

	void setCState(racing::CarState* CState, int i);
};
}
#endif
