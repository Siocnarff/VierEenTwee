#ifndef DEV_MICROTIMETRAVELDEP_H
#define DEV_MICROTIMETRAVELDEP_H

#include "Department.h"

namespace eng {
	class MicroTimeTravelDep : public Department {

	public:
		void build(Car* car);

		void fix(Car* car);

		void update(Component* component) final;
	};
}

#endif
