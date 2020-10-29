#include "CarState.h"

CarState::CarState(RaceWeekend * r) {
	this->race = r;
}

int racing::CarState::getDamage() {
	return this->damage;
}

void racing::CarState::setDamage(int damage) {
	this->damage = damage;
}

void CarState::Deal_damage(int d) {
	// TODO - implement carState::Deal damage

	throw "Not yet implemented";
}


