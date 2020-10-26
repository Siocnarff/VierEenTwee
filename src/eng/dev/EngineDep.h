#ifndef DEV_ENGINEDEP_H
#define DEV_ENGINEDEP_H

#include "Department.h"

namespace dev {
	class EngineDep : Department {


	public:
		void build(eng::Car* car);

		void fix(eng::Car* car);

		void update(Component* component);
	};
}

#endif
