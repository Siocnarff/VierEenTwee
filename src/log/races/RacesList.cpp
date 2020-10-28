//
// Created by jo-anne on 2020/10/22.
//

#include "RacesList.h"

using namespace log;

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
    return (headRace== nullptr);
}

RaceIterator RacesList::begin() {
    RaceIterator temp(*this, headRace);
    return temp;
}

RaceIterator RacesList::end() {
    Race* tail = headRace;
    while (tail!= nullptr) {
        tail = tail->nextRace();
    }
    return RaceIterator(*this, tail);
}

Race *RacesList::getHeadRace() const {
    return headRace;
}



