#ifndef ENG_CAR_H
#define ENG_CAR_H

#include <componentDevelopment/Component.h>

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
        Component** components;

	public:
		int getSpeed() const;

		int getHandling() const;

		static int getDamage();

		void setDamage(int damage);

		ppl::Driver* getDriver();

		void removeDriver(ppl::Driver* driver);

		void print();

		int getDriverXP();

		bool driverInCar();

		int getId() const;

		void clone();
	};
}

#endif
