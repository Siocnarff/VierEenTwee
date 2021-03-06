#ifndef ENG_COMPONENTSIMULATOR_H
#define ENG_COMPONENTSIMULATOR_H

#include "../componentDevelopment/Component.h"
#include "../Car.h"

namespace eng {
	class ComponentSimulator {

	public:
		void testComponent(Component* component);

		void testComponents(Car* car);
	};
}

#endif
