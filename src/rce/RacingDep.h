#ifndef RACINGDEP_H
#define RACINGDEP_H

#include "../rce/simulator/Simulator.h"
#include "../rce/simulator/SimulatorHotCondition.h"
#include "../rce/simulator/SimulatorNormalCondition.h"
#include "../rce/simulator/SimulatorWetCondition.h"

#include "../log/RacingDept.h"

#include "../rce/RaceWeekend.h"

#include "../ppl/specialists/Driver.h"

#include "../eng/Car.h"

//#include "../rce/leaderboard/Leaderboard.h"

#include "../rce/strategy/CreateStrategy.h"
#include "../rce/strategy/SafeStrategy.h"
#include "../rce/strategy/ModerateStrategy.h"
#include "../rce/strategy/AggressiveStrategy.h"

#include "../log/enums/RiskLevel.h"
#include "../log/enums/WeatherConditions.h"
#include "../log/enums/TrackComplexity.h"

#include "../log/Colleague.h"
#include <string>
#include <list>
namespace rce
{
    class RacingDep:public log::Colleague
    {

    private:
        log::RiskLevel risklevel;
        int budget;
        Race *race;
        int results;
        CreateStrategy *strategy;
        log::Container *CarContainer;
        std::string TeamName;
        std::list<ppl::Strategist *> Stategist;
        std::list<ppl::Pitcrew *> pitcrew;
        eng::Car *car;

// / ppl::Driver array of size 2?
// / car array of size 2? 
// / different strategies for each ppl::Driver and car?
    public:
        void HireEmployees(int b);
        CreateStrategy *PlanSeasonStrategy(int budget);//weather
        void preRaceArrival(eng::Car *c, ppl::Driver *d, Race *r, Container *con);
        int RacingWeekend();// why is it an int?
        Container* postRacePackUp();// return the container with tires in

        CreateStrategy* changeStrat(log::RiskLevel risk);//used to change strat during season
        void registerForSeason(Observer *logisticsDept);// is it needed?

        ppl::Driver* trainDriver(ppl::Driver *, int time, log::WeatherConditions);
        ppl::Driver* trainDriver(ppl::Driver *, int time, log::TrackComplexity);
        ppl::Driver* trainDriver(ppl::Driver *, int time, log::WeatherConditions weather, log::TrackComplexity trackDifficulty);

        Leaderboard *getResults();

        void setResult(int result);

        int getResult();// needed?

        Race *getRace();

        std::string getTeamName();

        void setTeamName(std::string TeamName);

        void SetCarAfterRace();

        std::list<ppl::Person *> getStategist();

        void setStategist(std::list<ppl::Person *> Stategist);

        std::list<ppl::Person *> getPitcrew();

        void setPitcrew(std::list<ppl::Person *> pitcrew);
    };
}
#endif
