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
        Logistics(int numDriverCarPairs = 2);

        virtual ~Logistics();

        void registerNotifier(Colleague *);

        void doYearPlanning();

        void preSeasonPreparation();

        void raceSeason();

        void postSeasonDebrief();

    protected:
        void sendCarToFactory(std::vector<eng::Car *>, Race*, bool isBroken) override;

        //void containerHasBeenPacked(Container *) override;

        Container *getEuropeanContainer();

        Container *getNextNonEuropean();

        void packContainers();

        Container* packSingleContainer() const;

        void simulateEvent(Race *);

        void putRacesIntoCalender();

        void orderTyres(int* tyreOrder) override;

        void driverBootCamp();

        void sponsoredBudget(int sumPositions = 0);

    private:
        rce::RacingDep *callRacingDept();
        eng::EngTeam *callEngDept();

        map<char, Colleague *> departments;
        std::vector<ppl::Driver *> drivers;
        TransportHandler *transportManager;
        //Won't be holding a handle to car as will always be passing directly from one place to another
        RacesList *racingCalendar;
        std::vector<int> carsInSeasonIDs;
        std::vector<int> carsInDevIDs;
        std::vector<Container *> nonEuropeanContainers; //lots of containers for non-European
        Container *europeanContainer;   //1 container for European
        rce::CreateStrategy *currentTeamStrategy;

        std::vector<rce::Tyres*> tyreSpecs; //possibly unnecessary? No

        std::vector<int> seasonPointTally;
        int budget;
        int numPairs = 2;

    };


}


#endif //PREMODELLING_LOGISTICSDEPT_H
