#ifndef ENG_CAR_H
#define ENG_CAR_H

#include <componentDevelopment/Component.h>
#include "../../ppl/specialists/Driver.h"

namespace eng {
	class Car {

	private:
        /**
         * ranges between 0 - 100
         */
        int damage;
        ppl::Driver* driver;
        int id;
        Component** components;

	public:
	    explicit Car(int identification);

		int getSpeed() const;

		int getHandling() const;

		int getDamage() const;

		void setDamage(int carDamage);

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
