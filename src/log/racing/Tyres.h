//
// Created by jo-anne on 2020/10/28.
//

#ifndef SRC_TYRES_H
#define SRC_TYRES_H

#include <list>

namespace rce {
    class Tyres {
    private:
        std::list<Tyres*> tyres;

    public:
        Tyres();
        ~Tyres();
        Tyres* getTyres(int);

    };
}

#endif //SRC_TYRES_H
