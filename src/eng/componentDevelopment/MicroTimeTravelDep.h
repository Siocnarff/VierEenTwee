#ifndef DEV_MICROTIMETRAVELDEP_H
#define DEV_MICROTIMETRAVELDEP_H

#include "Department.h"

namespace eng {
	class MicroTimeTravelDep : public Department {

	public:
        explicit MicroTimeTravelDep(Department *next = nullptr);

        void build(Car* car);

		void fix(Car* car, bool transparent) override;

		void update(Component* component) final;
	};
}

#endif
