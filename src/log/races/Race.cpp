//
// Created by jo-anne on 2020/10/22.
//

#include <enums/TrackComplexity.h>
#include <enums/WeatherConditions.h>

#include <utility>
#include "Race.h"
#include "Doc.h"
using namespace lg;

Race::Race() : location("outer space") {
    numLaps = 0;
    static int trackID = 0;
    complexity = Difficult;
    isInEurope = false;
    next = nullptr;
    previous = nullptr;
    id = trackID++;
}

Race::Race(std::string loc, int comp, bool eur, int laps, std::string* prettyOutput, Race *nextR, Race* prevR) : location(std::move(loc)) {
    static int trackID = 0;
    complexity = computeTrackComplexity(comp);
    isInEurope = eur;
    numLaps = laps;
    next = nextR;
    previous = prevR;
    id = trackID ++;
    for (int i = 0; i < 3; ++i) {
        output[i] = prettyOutput[i];
    }
}

/**
 * @author Berné
 * @param comp: trackComplexity
 * @return enum type
 */
TrackComplexity Race::computeTrackComplexity(int comp) {
    switch (comp) {
        case 0:
            return Easy;
        case 1:
            return Average;
        case 2:
            return Difficult;
        case 3:
            return Extreme;
        default:                //net sodat Clion nie die heeltyd kla nie.
            return Easy;
    }
}

bool Race::isRaceEuropean() const {
    return isInEurope;
}

std::string Race::getLocation() const {
    return this->location;
}

TrackComplexity Race::getTrackComplexity() {
    return complexity;
}

WeatherConditions Race::getRaceDayWeather() {
    int r = rand() % 3;
    switch (r) {
        case 0:
            return Hot;
            break;
        case 1:
            return Normal;
            break;
        case 2:
            return Rainy;
            break;
        default:
            break;
    }
}

void Race::setNextRace(Race *race) {
    this->next = race;
    race->previous = this;
}

void Race::setPrevRace(Race *race) {
    this->previous = race;
    race->next = this;
}

Race *Race::nextRace() {
    return next;
}

Race *Race::prevRace() {
    return previous;
}
int Race::getNumLaps() const {
    return numLaps;
}

int Race::getTrackID() const {
    return id;
}

void Race::printLoc() {
    for (int i = 0; i < 3; ++i) {
        pr::Doc::summary(output[i] + "\n");
    }

}

Race::~Race() = default;







