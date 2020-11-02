//
// Created by User on 28-Oct-2020.
//

#include <iostream>
#include "Tyres.h"

using namespace rce;

rce::Tyres::Tyres(int tyreOrder[2]) {
    for (int x = 0; x < 3; x++) {
        if (tyreOrder[x] > 0) {
//            std::cout << "no.: " << tyreOrder[x] << std::endl;
            for (int comp = 0; comp < tyreOrder[x]; comp++) {
                switch (x) {
                    case 0:
                        softTyres.push_back(new SetOfTyres(x));
                        break;
                    case 1:
                        mediumTyres.push_back(new SetOfTyres(x));
                        break;
                    case 2:
                        hardTyres.push_back(new SetOfTyres(x));
                        break;
                }
            }
        }
    }
}

rce::Tyres::~Tyres() {
    if (!softTyres.empty()) {
        for (std::_List_iterator<SetOfTyres *> it = softTyres.begin(); it != softTyres.end(); ++it) {
            delete *it;
        }
    }
    if (!mediumTyres.empty()) {
        for (std::_List_iterator<SetOfTyres *> it = mediumTyres.begin(); it != mediumTyres.end(); ++it) {
            delete *it;
        }
    }
    if (!hardTyres.empty()) {
        for (std::_List_iterator<SetOfTyres *> it = hardTyres.begin(); it != hardTyres.end(); ++it) {
            delete *it;
        }
    }
    std::cout << "Tyres recycled" << std::endl;

}

SetOfTyres *rce::Tyres::getTyres(int) {

}

void rce::Tyres::printStats() {
    std::cout << "---------------------------" << std::endl;
    std::cout << "Tyres condition: " << std::endl;

    if (!softTyres.empty()) {
        std::cout << "   Soft Tyres:" << std::endl;
        int setNum = 1;
        for (std::_List_iterator<SetOfTyres *> it = softTyres.begin(); it != softTyres.end(); ++it) {
            std::cout << "     Tyre set #" << setNum++ << " thread: "<< (*it)->getThread() << std::endl;
        }
    }
    if (!mediumTyres.empty()) {
        std::cout << "   Medium Tyres:" << std::endl;
        int setNum = 1;
        for (std::_List_iterator<SetOfTyres *> it = mediumTyres.begin(); it != mediumTyres.end(); ++it) {
            std::cout << "     Tyre set #" << setNum++ << " thread: " << (*it)->getThread() << std::endl;
        }
    }
    if (!hardTyres.empty()) {
        std::cout << "   Hard Tyres:" << std::endl;
        int setNum = 1;
        for (std::_List_iterator<SetOfTyres *> it = hardTyres.begin(); it != hardTyres.end(); ++it) {
            std::cout << "     Tyre set #" << setNum++ << " thread: "<< (*it)->getThread() << std::endl;
        }
    }

    std::cout << std::endl << "--------------------------" << std::endl;
}
