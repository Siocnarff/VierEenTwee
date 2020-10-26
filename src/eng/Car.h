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
		ppl::Driver* driver;
		int id;
        dev::Component** components;

	public:
		int getSpeed();

		int getHandling();

		int getDamage();

		void setDamage(int damage);

		ppl::Driver* getDriver();

		void removeDriver(ppl::Driver* driver);

		void print();

		int getDriverXP();

		bool driverInCar();

		int getId();

		void clone();
	};
}

#endif
