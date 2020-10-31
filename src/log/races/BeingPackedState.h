//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_BEINGPACKEDSTATE_H
#define SRC_BEINGPACKEDSTATE_H

#include "ContainerState.h"

namespace lg {

    class BeingPackedState : public ContainerState {
    public:
        void nextState(Container *) override;

        std::string getState() override;

        ~BeingPackedState();
    };

}

#endif //SRC_BEINGPACKEDSTATE_H
