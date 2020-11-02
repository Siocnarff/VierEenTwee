//
// Created by jo on 2020/10/09.
//

#ifndef PREMODELLING_LOGISTICSDEPT_H
#define PREMODELLING_LOGISTICSDEPT_H

#include <map>
#include <vector>
#include <races/RaceIterator.h>
#include <strategy/CreateStrategy.h>
#include <RacingDep.h>

#include "Mediator.h"
#include "../eng/EngTeam.h"
#include "transportation/TransportHandler.h"

namespace lg {

    class Logistics : public Mediator {
    public:
        Logistics();

        virtual ~Logistics();

        void registerNotifier(Colleague *);

        void doYearPlanning();

        void preSeasonPreparation();

        void raceSeason();

        void postSeasonDebrief();

        void toggleVerbose();

    protected:
        void sendCarToFactory(eng::Car *) override;

        void containerHasBeenPacked(Container *) override;

        //void requestContainerStateChange(bool isEuropeanRace) override;

        Container *getEuropeanContainer();

        Container *getNextNonEuropean();

        void packContainers();

        Container* packSingleContainer();

        void simulateEvent(Race *);

        void putRacesIntoCalender();

        void orderTyres(int *tyreOrder) override;

        void driverBootCamp();

    private:
        rce::RacingDep *callRacingDept();
        eng::EngTeam *callEngDept();

        map<char, Colleague *> departments;
        std::vector<ppl::Driver *> drivers;
        TransportHandler *transportManager;
        //Won't be holding a handle to car as will always be passing directly from one place to another
        RaceIterator *raceIterator;
        RacesList *racingCalendar;
        std::vector<int> carsInSeasonIDs;
        std::vector<Container *> nonEuropeanContainers; //lots of containers for non-European
        Container *europeanContainer;   //1 container for European
        rce::CreateStrategy *currentTeamStrategy;
        rce::Tyres* tyreSpecs;


        int seasonPointTally[2];
        int budget;
        bool verbose = true;

    };


}


#endif //PREMODELLING_LOGISTICSDEPT_H
