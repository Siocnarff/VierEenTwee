//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_RACESLIST_H
#define LOGISTICS_RACESLIST_H

#include "Race.h"
#include "RaceIterator.h"

namespace lg {
    class RacesList {
        friend class RaceIterator;

    public:
        RacesList();

        ~RacesList();

        void addRace(Race *);

        Race *getHeadRace() const;

        bool isEmpty();

        RaceIterator begin();

        RaceIterator end();

        int getNumRaces();

        void printList();

    private:
        Race *headRace; //ie. head
        int numRaces;
    };

}

#endif //LOGISTICS_RACESLIST_H
