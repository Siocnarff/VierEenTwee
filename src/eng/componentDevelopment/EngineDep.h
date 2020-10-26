#ifndef DEV_ENGINEDEP_H
#define DEV_ENGINEDEP_H

#include "Department.h"

namespace eng {
	class EngineDep : public Department {


	public:
		void build(Car* car);

		void fix(Car* car);

		void update(Component* component) final;
	};
}

#endif
