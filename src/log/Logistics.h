//
// Created by jo on 2020/10/09.
//

#ifndef PREMODELLING_LOGISTICSDEPT_H
#define PREMODELLING_LOGISTICSDEPT_H

#include <map>
#include <vector>
#include <transportation/TransportHandler.h>
#include <races/RaceIterator.h>

#include "Mediator.h"
#include "../eng/EngTeam.h"
#include "rce/RacingDep.h"

namespace log {

    class Logistics : public Mediator {
    public:
        Logistics();

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

        void packContainers(int*);

        Container* packSingleContainer(int*);

        void simulateEvent(Race *);

        void putRacesIntoCalender();

        void orderTyres(int *tyreOrder) override;

    private:
        rce::RacingDep *callRacingDept();
        eng::EngTeam *callEngDept();

        map<char, Colleague *> departments;
        ppl::Driver *driver;
        TransportHandler *transportManager;
        //Won't be holding a handle to car as will always be passing directly from one place to another
        RaceIterator *raceIterator;
        RacesList *racingCalendar;
        vector<int> carsInSeasonIDs;
        vector<Container *> nonEuropeanContainers; //lots of containers for non-European
        Container *europeanContainer;   //1 container for European
        rce::CreateStrategy *currentTeamStrategy;

        int seasonPointTally[2];
        int budget;

        bool verbose = true;

    };


}


#endif //PREMODELLING_LOGISTICSDEPT_H
