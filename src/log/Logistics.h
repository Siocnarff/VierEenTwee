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

        void toggleVerbose();

    protected:
        void sendCarToFactory(eng::Car *) override;

        void containerHasBeenPacked(Container *) override;

        void requestContainerStateChange(bool isEuropeanRace) override;

        Container *getEuropeanContainer();

        Container *getNextNonEuropean();

        void packContainers();

        void SimulateEvent(Race *);

        void putRacesIntoCalender();

    private:
        RacingDept *callRacingDept();

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
        Strategy *currentTeamStrategy;

        int seasonPointTally;
        int budget;

        bool verbose = true;

    };


}


#endif //PREMODELLING_LOGISTICSDEPT_H
