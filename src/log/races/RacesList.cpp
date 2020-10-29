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
        temp->setNextRace(race); //temp.next = race and race.prev = temp
        //race->setPrevRace(temp); //race.prev = temp and temp.next = race
    }
    ++numRaces;
}

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

/**
 * @return numRaces
 * @author Berné
 */
int RacesList::getNumRaces() {
    return numRaces;
}

void RacesList::printList() {
    Race* temp = headRace;
    if (isEmpty()) {
        return;
    }
    else {
        while (temp != nullptr) {
            //std::cout << temp;
            std::cout << temp->getLocation() << "\nNumLaps: " << temp->getNumLaps() << "\nWeather:" << temp->getRaceDayWeather() << std::endl;
            temp = temp->nextRace();
        }
    }

}

/*Race *RacesList::removeRace() {
    return nullptr;
}*/

