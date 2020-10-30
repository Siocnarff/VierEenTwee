#ifndef RACINGDEP_H
#define RACINGDEP_H

#include "Simulator.h"
#include "SimulatorHotCondition.h"
#include "SimulatorNormalCondition.h"
#include "SimulatorWetCondition.h"

#include "Driver.h"

#include <string>
#include <list>
#include <log/races/Race.h>
#include <log/Colleague.h>

namespace rce {
    class RacingDep : public log::Colleague {

    private:
        int riskLevel;
        int budget;
        log::Race *race;
        int results;
        CreateStrategy *strategy;
        log::Container *CarContainer;
        string TeamName;
        list<ppl::Person *> Stategist;
        list<ppl::Person *> pitcrew;
        eng::Car *car;

/// ppl::Driver array of size 2?
/// car array of size 2?
/// different strategies for each ppl::Driver and car?
    public:
        RacingDep(log::Mediator* mediator);

        void HireEmployees(int b);

        CreateStrategy *PlanSeasonStrategy(int budget);//weather
        void trainDriver(string weather, ppl::Driver *driver, int trackDifficulty, int time);//weather and time
        void preRaceArrival(eng::Car *c, ppl::Driver *d, log::Race *r, log::Container *con);

        int RacingWeekend();// why is it an int?
        log::Container *postRacePackUp();// return the container with tires in

        Leaderboard *getResults();

        void setResult(int result);

        int getResult();

        log::Race *getRace();

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
