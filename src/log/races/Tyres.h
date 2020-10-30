//
// Created by jo-anne on 2020/10/28.
//

#ifndef SRC_TYRES_H
#define SRC_TYRES_H

#include <list>
#include <string>

namespace rce {
    class Tyres {
    private:
        std::list<Tyres*> tyres;

        int thread;

        std::string tyreCompound;
    public:

        Tyres(int);

        Tyres();

        ~Tyres();

        Tyres* getTyres(int);

        int getThread();

        void reduceThread();
    };
}

#endif //SRC_TYRES_H
