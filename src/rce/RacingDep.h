#ifndef RACINGDEP_H
#define RACINGDEP_H


#include <Colleague.h>
#include <strategy/CreateStrategy.h>
#include <races/Race.h>
#include <leaderboard/Leaderboard.h>
#include "PitCrew.h"
#include "../ppl/factories/HireRacingDep.h"
#include "../ppl/factories/HireStrategist.h"
#include "../ppl/factories/HirePitCrew.h"

#include "../log/containers/Container.h"
#include "../log/Colleague.h"

#include "../rce/strategy/CreateStrategy.h"
#include "../rce/strategy/SafeStrategy.h"
#include "../rce/strategy/ModerateStrategy.h"
#include "../rce/strategy/AggressiveStrategy.h"

#include "../rce/pitstop/Pitstop.h"
#include "../ppl/specialists/PitCrew.h"
#include "../ppl/specialists/Driver.h"

#include "../eng/Car.h"

#include "../log/races/Race.h"

#include "../rce/leaderboard/Leaderboard.h"
#include "../pr/Doc.h"
#include "../rce/pitstop/SetOfTyres.h"

#include "../rce/RaceWeekend.h"
#include <string>
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
        ppl::Person** Strategist;
        ppl::Person** pitcrew;
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

        ppl::Person** getStrategist();

        void setStrategist(ppl::Person** Strategist);

        ppl::Person** getPitcrew();

        void setPitcrew(ppl::Person** pitcrew);

        int * getFinalScore();

        void getCarnotify(int i,lg::Race* r);

        void notifybackCar(std::vector<eng::Car*> c, lg::Race *r);

    };
}
#endif
