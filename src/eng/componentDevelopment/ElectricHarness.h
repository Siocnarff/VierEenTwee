#ifndef DEV_ELECTRICHARNESS_H
#define DEV_ELECTRICHARNESS_H

#include "Component.h"

namespace eng {
	class ElectricHarness : public Component {
    private:
        explicit ElectricHarness(Component * toClone);

    public:
        void print() final;

        Component* clone() final;
	};
}

#endif
