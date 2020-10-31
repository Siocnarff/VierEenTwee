#include "ComponentSimulator.h"
#include <pr/Doc.h>

using namespace eng;

void ComponentSimulator::testComponent(Component* component) {
	int label = component->quality;
	label += (rand()%11)-5;
	if (label > 100) {
		label = 100;
	} else if (label < 0) {
		label = 0;
	}
	pr::Doc::detail("Component was run through the extremely advanced simulator and seen to have a quality of ");
	pr::Doc::detail(std::to_string(label));
	pr::Doc::detail(" plus or minus 5 units.\n");
	component->qualityLabel = label;
}

void ComponentSimulator::testComponents(Car* car) {
	for (Component* component : car->components) {
		testComponent(component);
	}
	pr::Doc::detail("Components of car ");
	pr::Doc::detail(std::to_string(car->getId()));
	pr::Doc::detail("  were run through our extremely advanced simulator.\n");
}
