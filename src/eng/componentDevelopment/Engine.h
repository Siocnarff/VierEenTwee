#ifndef DEV_ENGINE_H
#define DEV_ENGINE_H

#include "Component.h"

namespace eng {
	class Engine : public Component {
    private:
        explicit Engine(Component *toClone);

    public:
        explicit Engine(int quality);

        void print() final;

        Component *clone() final;

        int getId() final;
    };
}
#endif