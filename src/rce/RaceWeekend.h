#ifndef RCE_RACEWEEKEND_H
#define RCE_RACEWEEKEND_H
#include "../rce/carState/CarState.h"
#include "../rce/carState/CarStateBroken.h"
#include "../rce/carState/CarStateDamaged.h"
#include "../rce/carState/CarStateFullHP.h"
//#include "../rce/RacingDep.h"
#include "../log/Colleague.h"

#include "../rce/strategy/CreateStrategy.h"
#include "../rce/strategy/SafeStrategy.h"
#include "../rce/strategy/ModerateStrategy.h"
#include "../rce/strategy/AggressiveStrategy.h"
#include "DriverPitStop.h"
#include "../rce/pitstop/Pitstop.h"
#include "../ppl/specialists/Driver.h"
#include "Driver.h"
#include "Race.h"
#include "Car.h"
#include "../eng/Car.h"
#include "../ppl/specialists/PitCrew.h"
#include "../log/races/Race.h"
#include "../rce/strategy/CreateStrategy.h"
#include "../rce/leaderboard/Leaderboard.h"
#include "../pr/Doc.h"
#include "WeatherConditions.h"
#include "TrackComplexity.h"
#include "RiskLevel.h"
#include "../rce/leaderboard/Leaderboard.h"
#include "../rce/leaderboard/DriversLeaderboard.h"
#include "TeamLeaderboard.h"
#include "../log/containers/Container.h"
#include <string>
#include "Tyres.h"
#include "../rce/pitstop/SetOfTyres.h"
#include <list>
#include "../rce/pitstop/DriverPitStop.h"
#include <vector>
//enum RiskLevel {	Safe, Moderate, Aggressive};
namespace rce{

class RaceWeekend
{

    private:
        bool broken [2];
        CreateStrategy* strategy;
        eng::Car** car;
        ppl::Driver** driver;
        lg::Race* raceConditions;
        rce::Pitstop ** pitstop;
        ppl::Person** pitcrew;
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
        Tyres ** tyre;
        SetOfTyres ** set;


    public:
        ~RaceWeekend();

        RaceWeekend(eng::Car** cars, ppl::Driver** drivers, lg::Race* r,CreateStrategy* s, ppl::Person** p, Tyres** t, Leaderboard ** l);

        int * RacingWeekend();

        eng::Car* getCar(int i);

        void setCar(eng::Car* car, int i);

        ppl::Driver* getDriver(int i);

        void setDriver(ppl::Driver* driver, int i);

        ppl::Person** getPitcrew();

        void setPitcrew(ppl::Person** pitcrew);

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

        bool* getBrokenCar();


//    void hireEmployees(int);

    };
}
#endif
