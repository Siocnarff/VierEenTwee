#ifndef DEV_DEPARTMENT_H
#define DEV_DEPARTMENT_H

#include "../../people/Person.h"
#include "../../log/RiskLevel.h"
#include "Risk.h"
#include "../Car.h"
#include "Component.h"

namespace eng {
	class Department {

	private:
		Department* nextDepartment;
		Risk* riskLevel;
		ppl::Person** specialists;

	public:
		void setRiskLevel(RiskLevel level);

		void build(Car* car);

		void fix(Car* car);

		virtual void update(Component* component) = 0;
	};
}

#endif
