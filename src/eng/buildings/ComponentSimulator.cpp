#include "ComponentSimulator.h"

using namespace eng;

void ComponentSimulator::testComponent(Component* component) {
	int label = component->quality;
	label += (rand()%11)-5;
	if (label > 100) {
		label = 100;
	} else if (label < 0) {
		label = 0;
	}
    component->qualityLabel = label;
	pr::Doc::detail("       Component was run through the extremely advanced simulator and seen to have a quality of ");
	pr::Doc::detail(std::to_string(label));
	pr::Doc::detail(" plus or minus 5 units.\n");
	pr::Doc::detail("\n");
}

void ComponentSimulator::testComponents(Car* car) {
	for (Component* component : car->components) {
		if (component) {
		    testComponent(component);
		}
	}
	pr::Doc::midInfo("\t\tComponents of car ");
	pr::Doc::midInfo(std::to_string(car->getId()));
	pr::Doc::midInfo("  were run through our extremely advanced simulator.\n\n");
}
