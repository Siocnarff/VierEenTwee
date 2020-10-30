#ifndef RACING_RACEWEEKEND_H
#define RACING_RACEWEEKEND_H

//#include "DriverPitStop.h"
#include "../eng/Car.h"
//#include "../people/Pitcrew.h"
//#include "../log/Race.h"
#include "strategy/CreateStrategy.h"
#include "leaderboard/Leaderboard.h"
#include "WeatherConditions.h"
#include "TrackComplexity.h"
#include "Leaderboard.h"
#include <string>
#include <log/races/Race.h>
#include <rce/carState/CarState.h>
#include <log/races/Container.h>

namespace rce {
    class RaceWeekend {

    private:
        CreateStrategy *strategy;
        eng::Car **car;
        ppl::Driver **driver;
        log::Race *raceConditions;
        log::Container *container;
        std::list<Pitcrew *> pitcrew;
        std::string TeamName;
        log::WeatherConditions DayWeather;
        Leaderboard *team;
        //Leaderboard *driver;
        CarState **CState;
        log::TrackComplexity TC;
        int time[2];
        int score[2];
        int speed;
        int handling;
        int xp;
        bool hometrack;
        int trackID;


    public:
        RaceWeekend(eng::Car *cars, ppl::Driver *drivers, log::Race *r, CreateStrategy *s,
                    list<Pitcrew *> p, log::Container *c);

        int RacingWeekend();

        eng::Car *getCar(int i);

        void setCar(eng::Car *car, int i);

        ppl::Driver *getDriver(int i);

        void setDriver(ppl::Driver *driver, int i);

        log::Container *getContainer();

        void setContainer(log::Container *container);

        list<Pitcrew *> getPitcrew();

        void setPitcrew(std::list<Pitcrew *> pitcrew);

        void notifyCarState(int i);

        int getTime(int i);

        void setTime(int time, int i);

        int getScore(int i);

        void setScore(int score, int i);

        log::WeatherConditions *getDayWeather();

        void setDayWeather(log::WeatherConditions *DayWeather);

        rce::CarState *getCState(int i);

        void setCState(rce::CarState *CState, int i);

        void deel_Damage(int i, int d);
    };
}
#endif
