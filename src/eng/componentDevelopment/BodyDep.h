#ifndef DEV_BODYDEP_H
#define DEV_BODYDEP_H

#include "Department.h"
#include "../Car.h"
#include "Component.h"

namespace eng {
	class BodyDep : public Department {

	public:
        explicit BodyDep(Department* next = nullptr);

		void build(Car* car) override;

		void fix(Car *car) override;

		void update(Component* component) final;
	};
}

#endif
