//
// Created by jo-anne on 2020/10/28.
//

#ifndef SRC_TYRES_H
#define SRC_TYRES_H

#include <list>
#include <string>
#include "SetOfTyres.h"

namespace rce {
    class Tyres {
    private:
        std::list<SetOfTyres*> softTyres;

        std::list<SetOfTyres*> mediumTyres;

        std::list<SetOfTyres*> hardTyres;


    public:

        Tyres(int[]);

        Tyres();

        ~Tyres();

        SetOfTyres* getTyres(int);

        std::string getCompound();

        void printStats();
    };
}

#endif //SRC_TYRES_H
