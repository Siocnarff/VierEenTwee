#ifndef DEV_MICROTIMETRAVELDEP_H
#define DEV_MICROTIMETRAVELDEP_H

#include "Department.h"

namespace dev {
	class MicroTimeTravelDep : Department {


	public:
		void build(eng::Car* car);

		void fix(eng::Car* car);

		void update(dev::Component* component) final;
	};
}

#endif
