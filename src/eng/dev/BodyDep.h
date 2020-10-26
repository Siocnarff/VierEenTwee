#ifndef DEV_BODYDEP_H
#define DEV_BODYDEP_H

#include "Department.h"
#include "../Car.h"
#include "Component.h"

namespace dev {
	class BodyDep : Department {

	public:
		void build(eng::Car* car);

		void fix(eng::Car* car);

		void update(Component* component);
	};
}

#endif
