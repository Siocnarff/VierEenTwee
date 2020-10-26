#ifndef DEV_CHASSISDEP_H
#define DEV_CHASSISDEP_H

#include "Department.h"
#include "Component.h"
#include "../Car.h"

namespace dev {
	class ChassisDep : Department {


	public:
		void build(eng::Car* car);

		void fix(eng::Car* car);

		void update(Component* component);
	};
}

#endif
