//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_RACESLIST_H
#define LOGISTICS_RACESLIST_H

#include "Aggregate.h"
#include "Race.h"
#include "RaceIterator.h"

namespace log {
//class RacesList : public Aggregate {
    class RacesList {
        friend class RaceIterator;

    public:
//    RaceIterator createIterator() override;
        RacesList();

        void addRace(Race *);

        //Race* removeRace();
        Race *getHeadRace() const;

        bool isEmpty();

        RaceIterator begin();

        RaceIterator end();

        int getNumRaces();

    private:
        Race *headRace; //ie. head
        int numRaces;
    };

}

#endif //LOGISTICS_RACESLIST_H
