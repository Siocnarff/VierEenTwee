#include "Car.h"
#include "../people/Driver.h"

int eng::Car::getSpeed() {
	return this->speed;
}

int eng::Car::getHandling() {
	return this->handling;
}

int eng::Car::getDamage() {
	// TODO - implement Car::getDamage
	throw "Not yet implemented";
}

void eng::Car::setDamage(int damage) {
	// TODO - implement Car::setDamage
	throw "Not yet implemented";
}

people::Driver* eng::Car::getDriver() {
	return this->driver;
}

void eng::Car::removeDriver(people::Driver* driver) {
	// TODO - implement Car::removeDriver
	throw "Not yet implemented";
}

void eng::Car::print() {
	// TODO - implement Car::print
	throw "Not yet implemented";
}

int eng::Car::getDriverXP() {
	// TODO - implement Car::getDriverXP
	throw "Not yet implemented";
}

bool eng::Car::driverInCar() {
	// TODO - implement Car::driverInCar
	throw "Not yet implemented";
}

int eng::Car::getId() {
	return this->id;
}

void eng::Car::clone() {
	// TODO - implement Car::clone
	throw "Not yet implemented";
}
