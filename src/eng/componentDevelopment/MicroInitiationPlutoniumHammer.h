#ifndef DEV_MICROINITIATIONPLUTONIUMHAMMER_H
#define DEV_MICROINITIATIONPLUTONIUMHAMMER_H

#include "Component.h"

namespace eng {
	class MicroInitiationPlutoniumHammer : public Component {
    private:
        explicit MicroInitiationPlutoniumHammer(Component * toClone);

    public:
        void print() final;

        Component* clone() final;
	};
}

#endif
