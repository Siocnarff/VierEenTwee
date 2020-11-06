//
// Created by jo-anne on 2020/10/28.
//

#ifndef SRC_TYRES_H
#define SRC_TYRES_H

#include <list>
#include <string>
#include <vector>
#include "SetOfTyres.h"

namespace rce {
    class Tyres {
    private:
        std::vector<std::list<SetOfTyres*>> tyreSets;

        std::list<SetOfTyres*> softTyres;

        std::list<SetOfTyres*> mediumTyres;

        std::list<SetOfTyres*> hardTyres;

        int tyreOrder[3];


    public:

        Tyres(int[]);

        Tyres(Tyres*);

        Tyres();

        ~Tyres();

        SetOfTyres* getTyres(int);

        void setOrder(int[]);

        void printStats();

        int* getTyreOrder();
    };
}

#endif //SRC_TYRES_H
