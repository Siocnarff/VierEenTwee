//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_INSHIPPINGSTATE_H
#define SRC_INSHIPPINGSTATE_H

#include "ContainerState.h"

namespace lg{

    class InShippingState : public ContainerState {
    public:
        void nextState(Container *) override;

        std::string getState() override;

        ~InShippingState();
    };

}


#endif //SRC_INSHIPPINGSTATE_H
