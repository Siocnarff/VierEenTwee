//
// Created by jo-anne on 2020/10/22.
//

#include "RaceIterator.h"
#include "Race.h"
#include "RacesList.h"
using namespace log;

RaceIterator::RaceIterator() {
    head = nullptr;
    current = nullptr;
}

RaceIterator::RaceIterator(const RacesList &source, Race *pRace) {
    head = source.getHeadRace();
    current = pRace;
}

void RaceIterator::first() {
    current = head;
}

//RaceIterator RaceIterator::operator++() {
void RaceIterator::operator++() {
    if (this != nullptr) {
        this->current = this->current->nextRace();
    }
    //return (*this);
}

//Iterator RaceIterator::operator--() {
void RaceIterator::operator--() {
    if (this != nullptr) {
        this->current = this->current->prevRace();
    }
    //return (*this);
//    problem Problem slicing here. how to stop?
}


bool RaceIterator::operator==(const RaceIterator &rhs) const {
    return current == rhs.current;
}

bool RaceIterator::isLast() {
    return current->nextRace()== nullptr;
}

Race* RaceIterator::currentItem() {
    return current;
}









