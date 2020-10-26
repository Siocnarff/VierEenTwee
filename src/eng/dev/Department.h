#ifndef DEV_DEPARTMENT_H
#define DEV_DEPARTMENT_H

#include "../../people/Person.h"
#include "../../log/RiskLevel.h"
#include "Risk.h"
#include "../Car.h"
#include "Component.h"

namespace dev {
	class Department {

	private:
		Department* nextDepartment;
		Risk* riskLevel;
		people::Person** specialists;

	public:
		void setRiskLevel(eng::RiskLevel level);

		void build(eng::Car* car);

		void fix(eng::Car* car);

		virtual void update(Component* component) = 0;
	};
}

#endif
