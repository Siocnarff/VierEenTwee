#ifndef DEV_ELECTRONICDEP_H
#define DEV_ELECTRONICDEP_H

#include "Department.h"

namespace dev {
	class ElectronicDep : Department {


	public:
		void build(eng::Car* car);

		void fix(eng::Car* car);

		void update(Component* component);
	};
}

#endif
