#ifndef RACEWEEKEND_H
#define RACEWEEKEND_H
#include "CarState.h"
#include "DriverPitStop.h"
#include "Driver.h"
#include "Car.h"
//#include "Pitcrew.h"
//#include "Race.h"
#include "CreateStrategy.h"
#include "Leaderboard.h"
using namespace std;
class RaceWeekend {

private:
	CreateStrategy* strategy;
	Car* car[];
	Driver* driver[];
	Race* raceConditions;
	Container* container;
	list<Pitcrew*> pitcrew;
	string TeamName;
	WeatherConditions* DayWeather;
	CarState* CState[];
	int time[];
	int score[];

public:
	RaceWeekend(Car* cars, Driver* drivers, Race* r, CreateStategy* s, list<Pitcrew*> p, Container* c);

	Leaderboard* Race();

	Car* getCar(int i);

	void setCar(Car* car, int i);

	Driver* getDriver(int i);

	void setDriver(Driver* driver, int i);

	Container* getContainer();

	void setContainer(Container* container);

	list<Pitcrew*> getPitcrew();

	void setPitcrew(list<Pitcrew*> pitcrew);

	void notifyCarState();

	int getTime(int i);

	void setTime(int time, int i);

	int getScore(int i);

	void setScore(int score, int i);

	WeatherConditions* getDayWeather();

	void setDayWeather(WeatherConditions* DayWeather);

	CarState* getCState(int i);

	void setCState(CarState* CState, int i);
};

#endif
