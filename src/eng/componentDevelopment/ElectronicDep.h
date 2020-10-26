#ifndef DEV_ELECTRONICDEP_H
#define DEV_ELECTRONICDEP_H

#include "Department.h"

namespace eng {
	class ElectronicDep : public Department {

	public:
		void build(Car* car);

		void fix(Car* car);

		void update(Component* component);
	};
}

#endif
