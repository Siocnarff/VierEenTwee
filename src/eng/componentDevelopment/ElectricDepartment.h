#ifndef DEV_ELECTRONICDEP_H
#define DEV_ELECTRONICDEP_H

#include "Department.h"

namespace eng {
	class ElectricDepartment : public Department {

	public:
        explicit ElectricDepartment(Department *next = nullptr);

        void build(Car* car) override;

		void fix(Car* car, bool transparent) override;

		void update(Component* component) final;
	};
}

#endif
