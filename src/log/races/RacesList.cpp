//
// Created by jo-anne on 2020/10/22.
//

#include <iostream>
#include "RacesList.h"
#include "Doc.h"

using namespace lg;

/*RaceIterator RacesList::createIterator() {
    return RaceIterator(*this, headRace);
}*/

RacesList::RacesList() {
    headRace = nullptr;
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
        race->setPrevRace(temp);
    }
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
            pr::Doc::detail("\nNumLaps: ");
            pr::Doc::detail(std::to_string(temp->getNumLaps()));
            pr::Doc::detail("\nWeather:");
            pr::Doc::detail(temp->getRaceDayWeather());
            pr::Doc::detail("\n");
            std::cout << temp->getLocation() << "\nNumLaps: " << temp->getNumLaps() << "\nWeather:"
                      << temp->getRaceDayWeather() << std::endl;
            temp = temp->nextRace();
        }
    }

}

int RacesList::getNumRaces() {
    return numRaces;
}



