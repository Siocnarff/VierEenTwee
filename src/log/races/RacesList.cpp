//
// Created by jo-anne on 2020/10/22.
//

#include <iostream>
#include "RacesList.h"
#include "Doc.h"

namespace lg {
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
            pr::Doc::detail(temp->getLocation());
            pr::Doc::detail("\nNumber of Laps: ");
            pr::Doc::detail(std::to_string(temp->getNumLaps()));
            pr::Doc::detail("\nTrack Complexity: ");
            pr::Doc::detail(convertComplexityToString(temp->getTrackComplexity()));
            pr::Doc::detail("\n");
            /*std::cout << temp->getLocation() << "\nNumLaps: " << temp->getNumLaps() << "\nWeather:"
                      << temp->getRaceDayWeather() << std::endl;*/
            temp = temp->nextRace();
        }
    }

}

int RacesList::getNumRaces() {
    return numRaces;
}



