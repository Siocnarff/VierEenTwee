#ifndef DEV_ELECTRONICDEP_H
#define DEV_ELECTRONICDEP_H

#include "Department.h"

namespace eng {
	class ElectricDepartment : public Department {

	public:
        explicit ElectricDepartment(Department *next = nullptr);

        void build(Car* car);

		void fix(Car* car);

		void update(Component* component) final;
	};
}

#endif
