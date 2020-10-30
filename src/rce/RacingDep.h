#ifndef RACINGDEP_H
#define RACINGDEP_H


#include <rce/strategy/CreateStrategy.h>
#include <rce/leaderboard/Leaderboard.h>
#include <log/Colleague.h>
#include "PitCrew.h"

namespace rce {
    class RacingDep : public log::Colleague {

    private:
        int risklevel;
        int budget;
        log::Race *race;
        int results;
        CreateStrategy *strategy;
        log::Container *CarContainer;
        std::string TeamName;
        //std::list<ppl::Strategist *> Stategist;
        std::list<PitCrew *> pitcrew;
        eng::Car *car;

// / ppl::Driver array of size 2?
// / car array of size 2? 
// / different strategies for each ppl::Driver and car?
    public:

        RacingDep();

        void hireEmployees(int budget) override;

        rce::CreateStrategy *PlanSeasonStrategy(int budget);
        //NB NB weather is log::WeatherConditions
        //CreateStrategy *PlanSeasonStrategy(int budget, std::string weather, int riskLevel);//weather

        ppl::Driver *trainDriver(ppl::Driver *, int time, log::WeatherConditions);
        //void trainDriver(std::string weather, ppl::Driver *driver, int trackDifficulty, int time);//weather and time

        ppl::Driver *trainDriver(ppl::Driver *, int time, log::TrackComplexity);

        ppl::Driver *trainDriver(ppl::Driver *, int time, log::WeatherConditions, log::TrackComplexity);

        void preRaceArrival(eng::Car *, ppl::Driver *, log::Race *, log::Container *);
        //void preRaceArrival(eng::Car *c, ppl::Driver *d, log::Race *r, log::Container *con);

        int* RacingWeekend(); //as een van die karre breek, moet hy dadelik mbv notify(Car*) teruggestuur word asb.
        //int* RacingWeekend();// why is it an int? Because we want an array of int[2] giving back the weekend's points

        log::Container *postRacePackUp();
        //void postRacePackUp();// return the container with tires in

        ~RacingDep() override;


    // TODO : Besluit dalk watter funksies eintlik protected en private moet wees

        Leaderboard *getResults();

        void setResult(int result);

        int getResult();// needed?

        log::Race *getRace();

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
