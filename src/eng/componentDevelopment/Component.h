#ifndef DEV_COMPONENT_H
#define DEV_COMPONENT_H

#include "Blueprint.h"
#include <iostream>
#include <vector>
#include "../../pr/Doc.h"

namespace eng {
	class Component {
	friend class Car;
	friend class Department;
	friend class ComponentSimulator;
	friend class WindTunnel;

	private:
		int quality = 0;
		int damage = 0;
		int qualityLabel = 0;

    protected:
        explicit Component(Component* component);

        explicit Component(int quality);

    public:
	    virtual ~Component() = default;

		int getQualityLabel() const;

		void setQualityLabel(int label);

		virtual void print() = 0;

		Blueprint* createBlueprint();

		void rebuildComponent(Blueprint* plan);

        virtual Component *clone() = 0;

        virtual int getId() = 0;
    };
}

#endif
