#ifndef ENG_CAR_H
#define ENG_CAR_H

#include <componentDevelopment/Component.h>
#include "../../ppl/specialists/Driver.h"
#include "Department.h"


namespace eng {
	class Car {
	friend class Department;
	friend class EngTeam;
	friend class ComponentSimulator;
	friend class WindTunnel;

	private:
        /**
         * ranges between 0 - 100
         */
        int damage = 0;
        ppl::Driver* driver = nullptr;
        int id = 0;
        Component* components[5];

	public:
	    ~Car();

	    explicit Car(int identification);

	    explicit Car(Car *car);

		int getSpeed() const;

		int getHandling() const;

		int getDamage() const;

		void setDamage(int carDamage);

		ppl::Driver* getDriver();

		static void removeDriver(ppl::Driver* driver);

		void print();

		int getDriverXP();

		bool driverInCar();

		int getId() const;

		Car * clone();

        Car *clone(int idOfNew);
    };
}

#endif
