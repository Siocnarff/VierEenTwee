#ifndef DEV_MICROTIMETRAVELDEP_H
#define DEV_MICROTIMETRAVELDEP_H

#include "Department.h"

namespace eng {
	class MicroTimeTravelDep : public Department {

	public:
        explicit MicroTimeTravelDep(Department *next = nullptr);

        void build(Car* car) override;

		void fix(Car *car) override;

		void update(Component* component) final;
	};
}

#endif
