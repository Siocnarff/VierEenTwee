//
// Created by jo-anne on 2020/10/22.
//

#include <enums/TrackComplexity.h>
#include <enums/WeatherConditions.h>
#include "Race.h"
using namespace lg;

Race::Race() {
    static int trackID = 0;
    location = "outer space";
    complexity = Difficult;
    isInEurope = false;
    next = nullptr;
    prev = nullptr;
    id = trackID++;
}

Race::Race(std::string loc, int comp, bool eur, int laps, Race *nextR, Race* prevR) {
    static int trackID = 0;
    location = loc;
    complexity = computeTrackComplexity(comp);
    isInEurope = eur;
    numLaps = laps;
    next = nextR;
    prev = prevR;
    id = trackID ++;
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

bool Race::isRaceEuropean() {
    return isInEurope;
}

std::string Race::getLocation() {
    return location;
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
    race->prev = this;
}

/*void Race::setPrevRace(Race *race) {
    this->prev = race;
    race->next = this;
}*/

Race *Race::nextRace() {
    return next;
}

Race *Race::prevRace() {
    return prev;
}
int Race::getNumLaps() {
    return numLaps;
}

int Race::getTrackID() {
    return id;
}

/*std::ostream &lg::operator<<(std::ostream &os, const Race &rc) {
    os << rc.location << '/nEurope: ' << rc.isInEurope << '/nNumLaps: ' << rc.numLaps << std::endl;
    return os;
}*/

/*std::ostream& operator<<(std::ostream& stream, lg::Race rc) {
    stream << rc.getLocation() << "/nEurope: " << rc.isRaceEuropean() << "/nNumLaps: " << rc.getNumLaps() << std::endl;
    return stream;
}*/






