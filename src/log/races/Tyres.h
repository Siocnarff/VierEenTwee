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
        std::list<Tyres*> tyreSetList;

        int thread;

        int tyreCompoundInt;

        std::string tyreCompoundString;
    public:

        Tyres(int);

        Tyres();

        ~Tyres();

        Tyres* getTyres(int);

        int getThread();

        void reduceThread();

        std::string getCompound();

        void print();
    };
}

#endif //SRC_TYRES_H
