#ifndef ENG_GARAGE_H
#define ENG_GARAGE_H

#include <vector>
#include "../Car.h"

namespace eng {
	class Garage {

	private:
	    int lookup[20] = {-1};
		Car* car[20] = {nullptr};

	public:
	    ~Garage();

		void storeCar(Car* car);

		Car* retrieveCar(int id);

        Car *getPrototype();
    };
}

#endif
