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
		int budget = 0;
		std::vector<ppl::Person*> specialists;

    protected:
        std::string departmentName;

	public:
	    explicit Department(Department* next);

	    void addSpecialist(ppl::Person *specialist, bool printResults = false);

		void setRiskLevel(log::RiskLevel level);

		virtual void build(Car* car) = 0;

		virtual void fix(Car* car) = 0;

		virtual void update(Component* component) = 0;

        void topUpBudget(int cash);
    };
}

#endif
