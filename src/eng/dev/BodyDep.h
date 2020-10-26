#ifndef DEV_BODYDEP_H
#define DEV_BODYDEP_H

#include "Department.h"
#include "../Car.h"
#include "Component.h"

namespace eng {
	class BodyDep : public Department {

	public:
		void build(Car* car);

		void fix(Car* car);

		void update(Component* component);
	};
}

#endif
