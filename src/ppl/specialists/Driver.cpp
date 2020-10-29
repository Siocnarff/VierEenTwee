#include "Driver.h"

using namespace ppl;

Driver::Driver(std::string name, bool hasDegree, int skillLevel) : Person(name, hasDegree, skillLevel) {
    this->xp = 0;
    setJobDescription("Drives cars at an above average speed.");
}

bool Driver::isHomeTrack(int trackId) {
	for (int id : homeTracks) {
        if(id == trackId) {
            return true;
        }
	}
    return false;
}

int Driver::getXp() const {
	return this->xp;
}

void Driver::setXp(int xp) {
	this->xp = xp;
}

void Driver::addHomeTrack(int trackId) {
    homeTracks.push_back(trackId);
}
