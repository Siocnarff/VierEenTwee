#ifndef DEV_COMPONENT_H
#define DEV_COMPONENT_H

#include "Blueprint.h"
#include <iostream>
#include <vector>

namespace eng {
	class Component {
	friend class Car;
	friend class Department;
	friend class ComponentSimulator;

	private:
		int quality = 0;
		int damage = 0;
		int qualityLabel = 0;

    protected:
        explicit Component(Component* component);

    public:
		int getQualityLabel();

		void setQualityLabel(int qualityLabel);

		virtual void print() = 0;

		Blueprint* createBlueprint();

		void rebuildComponent(Blueprint* plan);

        virtual Component *clone() = 0;
    };
}

#endif
