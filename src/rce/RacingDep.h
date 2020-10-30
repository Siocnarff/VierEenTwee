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

#include <string>
#include <list>

namespace rce {
    class RacingDep {

    private:
        int risklevel;
        int budget;
        Race *race;
        int results;
        CreateStrategy *strategy;
        log::Container *CarContainer;
        std::string TeamName;
        list<ppl::Strategist *> Stategist;
        list<ppl::Pitcrew *> pitcrew;
        eng::Car *car;

// / ppl::Driver array of size 2?
// / car array of size 2? 
// / different strategies for each ppl::Driver and car?
    public:
        void HireEmployees(int b);

        CreateStrategy *PlanSeasonStrategy(int budget, string weather, int riskLevel);//weather
        void trainDriver(string weather, ppl::Driver *driver, int trackDifficulty, int time);//weather and time
        void preRaceArrival(eng::Car *c, ppl::Driver *d, Race *r, Container *con);

        int RacingWeekend();// why is it an int?
        void postRacePackUp();// return the container with tires in

        void registerForSeason(Observer *logisticsDept);// is it needed?

        Leaderboard *getResults();

        void setResult(int result);

        int getResult();// needed?

        Race *getRace();

        string getTeamName();

        void setTeamName(string TeamName);

        void SetCarAfterRace();

        list<ppl::Person *> getStategist();

        void setStategist(list<ppl::Person *> Stategist);

        list<ppl::Person *> getPitcrew();

        void setPitcrew(list<ppl::Person *> pitcrew);
    };
}
#endif
