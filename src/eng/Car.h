#ifndef ENG_CAR_H
#define ENG_CAR_H

#include "../people/Driver.h"
#include "../dev/Component.h"

namespace eng {
	class Car {

	private:
		/**
		 * ranges between 0 - 100
		 */
		int speed;
		int handling;
		people::Driver* driver;
		int id;
        dev::Component** components;

	public:
		int getSpeed();

		int getHandling();

		int getDamage();

		void setDamage(int damage);

		people::Driver* getDriver();

		void removeDriver(people::Driver* driver);

		void print();

		int getDriverXP();

		bool driverInCar();

		int getId();

		void clone();
	};
}

#endif
