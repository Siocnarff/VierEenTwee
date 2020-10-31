#include <pr/Doc.h>
#include "ElectricDepartment.h"
#include "ElectricHarness.h"

using namespace eng;

void ElectricDepartment::build(Car* car) {
    if (haveSpecialists()) {
        buildComponentIntoCar(car, new ElectricHarness(specialistsDesignComponent()));
    }
    Department::build(car);
}

void ElectricDepartment::fix(Car *car) {
	int damage = fixComponent(car, 2);
	if (damage == 0) {
		pr::Doc::detail("All the shocks came from the correct wires, sending car to next department.\n");
	} else {
		pr::Doc::detail(departmentName);
		pr::Doc::detail(" is rewiring the harness which took ");
		pr::Doc::detail(std::to_string(damage));
		pr::Doc::detail("% damage.\n");
	}
    Department::fix(car);
}

void ElectricDepartment::update(Component* component) {
	// TODO - implement ElectricDepartment::update
	throw "Not yet implemented";
}

ElectricDepartment::ElectricDepartment(Department *next) : Department(next) {
    departmentName = "Electric Department";
}
