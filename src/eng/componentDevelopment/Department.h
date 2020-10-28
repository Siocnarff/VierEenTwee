#ifndef DEV_DEPARTMENT_H
#define DEV_DEPARTMENT_H

#include "../../ppl/Person.h"
#include "../../log/enums/RiskLevel.h"
#include "Risk.h"
#include "../Car.h"
#include "Component.h"

namespace eng {
	class Department {

	private:
		Department* nextDepartment;
		Risk* riskLevel;
		std::vector<ppl::Person*> specialists;

	public:
	    explicit Department(Department* next);

	    void addSpecialist(ppl::Person* specialist);

		void setRiskLevel(log::RiskLevel level);

		void build(Car* car);

		void fix(Car* car);

		virtual void update(Component* component) = 0;
	};
}

#endif
