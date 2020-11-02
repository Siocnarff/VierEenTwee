//
// Created by jo-anne on 2020/10/23.
//

#ifndef LOGISTICS_SUBSTATES_H
#define LOGISTICS_SUBSTATES_H

#include "Container.h"


namespace lg {

    class ArrivedState : public ContainerState {
    public:
        void nextState(Container *) override;

        std::string getState() override;

        ~ArrivedState();
    };

}



#endif //LOGISTICS_SUBSTATES_H
