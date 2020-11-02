#ifndef RACINGDEP_H
#define RACINGDEP_H


#include <Colleague.h>
#include <strategy/CreateStrategy.h>
#include <races/Race.h>
#include <leaderboard/Leaderboard.h>
#include "PitCrew.h"

namespace rce {
    class RacingDep : public lg::Colleague {

    private:
        int risklevel;
        int budget;
        lg::Race *race;
        int results;
        CreateStrategy *strategy;
        lg::Container *CarContainer;
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
        //NB NB weather is lg::WeatherConditions
        //CreateStrategy *PlanSeasonStrategy(int budget, std::string weather, int riskLevel);//weather

        ppl::Driver *trainDriver(ppl::Driver *, int time, lg::WeatherConditions);
        //void trainDriver(std::string weather, ppl::Driver *driver, int trackDifficulty, int time);//weather and time

        ppl::Driver *trainDriver(ppl::Driver *, int time, lg::TrackComplexity);

        ppl::Driver *trainDriver(ppl::Driver *, int time, lg::WeatherConditions, lg::TrackComplexity);

        void preRaceArrival(std::vector<eng::Car*>, std::vector<ppl::Driver*>, lg::Race*, lg::Container*, Tyres*);
        //void preRaceArrival(eng::Car *c, ppl::Driver *d, lg::Race *r, lg::Container *con);

        int* RacingWeekend(); //as een van die karre breek, moet hy dadelik mbv notify(Car*) teruggestuur word asb.
        //int* RacingWeekend();// why is it an int? Because we want an array of int[2] giving back the weekend's points

        lg::Container *postRacePackUp();
        //void postRacePackUp();// return the container with tires in

        ~RacingDep() override;

        int* getFinalResults();


    // TODO : Besluit dalk watter funksies eintlik protected en private moet wees

        Leaderboard *getResults();

        void setResult(int result);

        int getResult();// needed?

        lg::Race *getRace();

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
