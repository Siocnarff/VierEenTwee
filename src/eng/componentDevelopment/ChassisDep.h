#ifndef DEV_CHASSISDEP_H
#define DEV_CHASSISDEP_H

#include "Department.h"
#include "Component.h"
#include "../Car.h"

namespace eng {
	class ChassisDep : public Department {


	public:
        explicit ChassisDep(Department *next = nullptr);

        void build(Car* car) override;

		void fix(Car *car) override;

		void update(Component* component) final;
	};
}

#endif
