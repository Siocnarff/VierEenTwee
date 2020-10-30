#ifndef ENG_GARAGE_H
#define ENG_GARAGE_H

#include <vector>
#include "../Car.h"

namespace eng {
	class Garage {

	private:
		std::vector<int> lookup;
        Car* car[20];

	public:
		void storeCar(Car* car);

		Car* retrieveCar(int id);

        Car *getPrototype();
    };
}

#endif
