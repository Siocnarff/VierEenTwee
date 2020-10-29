#include <specialists/Driver.h>
#include "Car.h"

using namespace eng;

int Car::getSpeed() const {
	return this->speed;
}

int Car::getHandling() const {
	return this->handling;
}

int Car::getDamage() {
	// TODO - implement Car::getDamage
	throw "Not yet implemented";
}

void Car::setDamage(int damage) {
	// TODO - implement Car::setDamage
	throw "Not yet implemented";
}

ppl::Driver* Car::getDriver() {
	return this->driver;
}

void Car::removeDriver(ppl::Driver* driver) {
	// TODO - implement Car::removeDriver
	throw "Not yet implemented";
}

void Car::print() {
	// TODO - implement Car::print
	throw "Not yet implemented";
}

int Car::getDriverXP() {
	// TODO - implement Car::getDriverXP
	throw "Not yet implemented";
}

bool Car::driverInCar() {
	// TODO - implement Car::driverInCar
	throw "Not yet implemented";
}

int Car::getId() const {
	return this->id;
}

void Car::clone() {
	// TODO - implement Car::clone
	throw "Not yet implemented";
}