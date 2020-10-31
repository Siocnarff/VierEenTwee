#include "ComponentSimulator.h"

using namespace eng;

void ComponentSimulator::testComponent(Component* component, bool transparent) {
	int label = component->quality;
	label += (rand()%10)-4;
	if (label > 100) {
		label = 100;
	}
	if (transparent) {
		std::cout << "Component was run through the extremely advanced simulator and seen to have a quality of " << label << " plus or minus 5 units." << std::endl;
	}
	component->qualityLabel =
}

void ComponentSimulator::testComponents(Car* car, bool transparent) {
	// TODO - implement ComponentSimulator::testComponents
	throw "Not yet implemented";
}
