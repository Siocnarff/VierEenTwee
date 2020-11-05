#ifndef RACINGDEP_H
#define RACINGDEP_H

#include "../rce/simulator/Simulator.h"
#include "../rce/simulator/SimulatorHotCondition.h"
#include "../rce/simulator/SimulatorNormalCondition.h"
#include "../rce/simulator/SimulatorWetCondition.h"

#include "../log/races/Race.h"
#include "../rce/RaceWeekend.h"

#include "../ppl/specialists/Driver.h"
#include "../ppl/specialists/PitCrew.h"
#include "../ppl/specialists/Strategist.h"

#include "../eng/Car.h"

#include "../rce/leaderboard/Leaderboard.h"
#include "../rce/pitstop/Tyres.h"

#include "../rce/strategy/CreateStrategy.h"
#include "../rce/strategy/SafeStrategy.h"
#include "../rce/strategy/ModerateStrategy.h"
#include "../rce/strategy/AggressiveStrategy.h"

#include "../log/enums/RiskLevel.h"
#include "../log/enums/WeatherConditions.h"
#include "../log/enums/TrackComplexity.h"

#include "HirePitCrew.h"
#include "HireStrategist.h"

#include "../log/Colleague.h"
#include <string>
#include <list>
namespace rce
{
    class RacingDep:public lg::Colleague
    {

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

    public:
        RacingDep();
        ~RacingDep();
        void HireEmployees(int b);
        CreateStrategy *PlanSeasonStrategy(int budget);
        void preRaceArrival(std::vector<eng::Car*> c, std::vector<ppl::Driver*> d, lg::Race* r, lg::Container* con , std::vector<Tyres *> t);
        lg::Container* postRacePackUp();// return the container with tires in
        CreateStrategy* changeStrat(lg::RiskLevel risk);//used to change strat during season

        ppl::Driver* trainDriver(ppl::Driver *, int time, lg::WeatherConditions);
        ppl::Driver* trainDriver(ppl::Driver *, int time, lg::TrackComplexity);
        ppl::Driver* trainDriver(ppl::Driver *, int time, lg::WeatherConditions weather, lg::TrackComplexity trackDifficulty);

        int * Race();

        void setResult(int result);

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
