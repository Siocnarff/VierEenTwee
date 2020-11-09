//
// Created by jo-anne on 2020/10/22.
//

#include <iostream>
#include "RacesList.h"
#include "Doc.h"

namespace lg {
    // todolist : @jo find suitable spot for this function
    std::string convertComplexityToString(TrackComplexity t) {
        switch (t) {
            case Easy:
                return "Easy";
            case Average:
                return "Average";
            case Difficult:
                return "Difficult";
            case Extreme:
                return "Extreme";
        }
    }
}

using namespace lg;

RacesList::RacesList() {
    headRace = nullptr;
    numRaces = 0;
}

RacesList::~RacesList() {
    for (RaceIterator t = begin(); !(t == end()); ) {
        Race* temp = t.currentItem();
        ++t;
        delete temp;
    }

}

//IS DONE?
void RacesList::addRace(Race *race) {
    if (isEmpty()) {
        headRace = race;
    } else {
        Race *temp = headRace;
        while (temp->nextRace() != nullptr) {
            temp = temp->nextRace();
        }
        temp->setNextRace(race);
        //race->setPrevRace(temp);
    }
    numRaces++;
}

/*Race *RacesList::removeRace() {
    return nullptr;
}*/

bool RacesList::isEmpty() {
    return (headRace == nullptr);
}

RaceIterator RacesList::begin() {
    RaceIterator temp(*this, headRace);
    return temp;
}

RaceIterator RacesList::end() {
    Race *tail = headRace;
    while (tail != nullptr) {
        tail = tail->nextRace();
    }
    return RaceIterator(*this, tail);
}

Race *RacesList::getHeadRace() const {
    return headRace;
}

void RacesList::printList() {
    Race *temp = headRace;
    if (isEmpty()) {
        return;
    } else {
        while (temp != nullptr) {
            pr::Doc::midInfo("     " + temp->getLocation() + "\n");
            pr::Doc::detail("     Number of Laps: ");
            pr::Doc::detail(std::to_string(temp->getNumLaps()) + "\n");
            pr::Doc::detail("     Track Complexity: ");
            pr::Doc::detail( convertComplexityToString(temp->getTrackComplexity()) + "\n");
            pr::Doc::detail("\n");
           temp = temp->nextRace();
        }
    }
    pr::Doc::detail("\n");

}

int RacesList::getNumRaces() {
    return numRaces;
}



