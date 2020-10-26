#ifndef DEV_CHASSISDEP_H
#define DEV_CHASSISDEP_H

#include "Department.h"
#include "Component.h"
#include "../Car.h"

namespace eng {
	class ChassisDep : public Department {


	public:
		void build(Car* car);

		void fix(Car* car);

		void update(Component* component);
	};
}

#endif
