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
#include "RacingDept.h"
#include "../eng/EngTeam.h"

/**
 * @author Berné
 */
namespace log {

    class Logistics : public Mediator {
    public:
        Logistics();

        void registerNotifier(Colleague *);

        void doYearPlanning();

        void preSeasonPreparation();

        void raceSeason();

        void postSeasonDebrief();

        void toggleTransparency();

    protected:
        void sendCarToFactory(eng::Car *) override;

        void containerHasBeenPacked(Container *) override;

        void requestContainerStateChange(bool isEuropeanRace) override;

        void informStrategyChanged(rce::Strategy *) override;

        Container *getEuropeanContainer();

        Container *getNextNonEuropean();

        void packContainers(int);

        Container* packSingleContainer(int);

        void simulateEvent(Race *);

        void putRacesIntoCalender();

    private:
        rce::RacingDept *callRacingDept();

        eng::EngTeam *callEngDept();

        std::map<char, Colleague *> departments;
        ppl::Driver *driver;
        TransportHandler *transportManager;
        //Won't be holding a handle to car as will always be passing directly from one place to another
        RaceIterator *raceIterator;
        RacesList *racingCalendar;
        std::vector<int> carsInSeasonIDs;
        std::vector<Container *> nonEuropeanContainers; //lots of containers for non-European
        Container *europeanContainer;   //1 container for European
        rce::Strategy *currentTeamStrategy;

        int seasonPointTally;
        int budget;
        bool verbose = false;

    };


}


#endif //PREMODELLING_LOGISTICSDEPT_H
