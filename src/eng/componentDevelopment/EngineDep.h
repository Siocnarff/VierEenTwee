#ifndef DEV_ENGINEDEP_H
#define DEV_ENGINEDEP_H

#include "Department.h"

namespace eng {
	class EngineDep : public Department {


	public:
        explicit EngineDep(Department *next = nullptr);

        void build(Car* car);

		void fix(Car* car, bool transparent) override;

		void update(Component* component) final;
	};
}

#endif
