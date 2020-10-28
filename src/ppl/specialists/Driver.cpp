#include "Driver.h"

using namespace ppl;

Driver::Driver(std::string n, bool d, int s) : Person(n, d, s) {
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
