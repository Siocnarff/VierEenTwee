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
        lg::RiskLevel risklevel;
        int budget;
        lg::Race *race;
        rce::Leaderboard ** lead;
        CreateStrategy *strategy;
        lg::Container *CarContainer;
        std::string TeamName;
        std::list<ppl::Person*> Strategist;
        std::list<ppl::Person*> pitcrew;
        eng::Car *car;//needed?
        eng::Car ** cars;//todo: where to get and set?
        ppl::Driver **drivers;//todo: where to get and set?
        Tyres ** tyres;

// / ppl::Driver array of size 2?
// / car array of size 2? 
// / different strategies for each ppl::Driver and car?
    public:

        RacingDep();
        ~RacingDep();
        void hireEmployees(int b);
        CreateStrategy *PlanSeasonStrategy(int budget);
        void preRaceArrival(std::vector<eng::Car*> c, std::vector<ppl::Driver*> d, lg::Race* r, lg::Container* con , std::vector<Tyres *> t);
        lg::Container* postRacePackUp();// return the container with tires in
        CreateStrategy* changeStrat(lg::RiskLevel risk);//used to change strat during season

        ppl::Driver* trainDriver(ppl::Driver *, int time, lg::WeatherConditions);
        ppl::Driver* trainDriver(ppl::Driver *, int time, lg::TrackComplexity);
        ppl::Driver* trainDriver(ppl::Driver *, int time, lg::WeatherConditions weather, lg::TrackComplexity trackDifficulty);

        int * Race();


        lg::Race *getRace();

        std::string getTeamName();

        void setTeamName(std::string TeamName);

        void SetCarAfterRace(eng::Car* c);

        std::list<ppl::Person *> getStrategist();

        void setStrategist(std::list<ppl::Person*> Strategist);

        std::list<ppl::Person *> getPitcrew();

        void setPitcrew(std::list<ppl::Person *> pitcrew);

        int * getFinalScore();

    };
}
#endif
