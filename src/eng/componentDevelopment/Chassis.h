#ifndef DEV_CHASSIS_H
#define DEV_CHASSIS_H

#include "Component.h"

namespace eng {
	class Chassis : public Component {
    private:
        explicit Chassis(Component * toClone);

    public:
        void print() final;

        Component* clone() final;;
	};
}

#endif
