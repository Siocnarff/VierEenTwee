//
// Created by User on 30-Oct-2020.
//

#ifndef VIEREENTWEE_TYREBOX_H
#define VIEREENTWEE_TYREBOX_H

#include "Container.h"
#include "Tyres.h"

namespace lg {
    class TyreBox : public Container {
    public:
        TyreBox(int tyreCompound);

        ~TyreBox();

        rce::Tyres* getTyres();

    private:
        rce::Tyres* tyres;
    };
}


#endif //VIEREENTWEE_TYREBOX_H
