#ifndef ENG_GARAGE_H
#define ENG_GARAGE_H

#include <vector>
#include "Car.h"

namespace eng {
	class Garage {

	private:
		std::vector<int> lookup;
        Car* car[];

	public:
		void storeCar(Car* car);

		Car* retrieveCar(int id);
	};
}

#endif
