#include "ComponentSimulator.h"

using namespace eng;

void ComponentSimulator::testComponent(Component* component, bool transparent) {
	int label = component->quality;
	label += (rand()%11)-5;
	if (label > 100) {
		label = 100;
	} else if (label < 0) {
		label = 0;
	}
	if (transparent) {
		std::cout << "Component was run through the extremely advanced simulator and seen to have a quality of " << label << " plus or minus 5 units." << std::endl;
	}
	component->qualityLabel = label;
}

void ComponentSimulator::testComponents(Car* car, bool transparent) {
	for (Component* component : car->components) {
		testComponent(component, transparent);
	}
	if (transparent) {
		std::cout << "Components of car " << car->getId() << " were run through our extremely advanced simulator." << std::endl;
	}
}
