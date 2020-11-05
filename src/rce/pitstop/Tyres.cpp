//
// Created by User on 28-Oct-2020.
//

#include <iostream>
#include <Doc.h>
#include "Tyres.h"


//TODO: Change couts to DOC prints
using namespace rce;

/**
 * @author: Marike
 * @status: in process
 */


Tyres::Tyres() {
    pr::Doc::detail("Order for tyres is on its way! \n");
}



//changed a bit to incorporate the possibility of default constructor and then later instantiation;
Tyres::Tyres(int tyreOrder[3]) {       //changed from 2 to 3
    for (int x = 0; x < 3; x++) {
        this->tyreOrder[x] = tyreOrder[x];
    }

    setOrder(tyreOrder);
}


Tyres::~Tyres() {
    for (int x = 0; x < 3; x++) {
        if (!tyreSets[x].empty()) {
            for (std::_List_iterator<SetOfTyres *> it = tyreSets[x].begin(); it != tyreSets[x].end(); ++it) {
                delete *it;
            }
        }

    }
    pr::Doc::detail("Tyres recycled\n");
}

SetOfTyres *Tyres::getTyres(int compound) {
    SetOfTyres *tyreSet = nullptr;
    if (!tyreSets[compound].empty()) {
        tyreSet = *tyreSets[compound].begin();
        tyreSets[compound].pop_front();
    }
    return tyreSet;
}

void Tyres::printStats() {
    pr::Doc::detail("---------------------------\n");
    pr::Doc::detail("Tyres condition: \n");

    std::string temp = "";

    for (int x = 0; x < 3; x++) {
        if (!tyreSets[x].empty()) {
            int setNum = 1;
            for (std::_List_iterator<SetOfTyres *> it = tyreSets[x].begin(); it != tyreSets[x].end(); ++it) {
                temp = "  "+ (*it)->getTyreCompoundString() + ":\n";
                temp = temp + "     Tyre set #" + std::to_string(setNum++) + " thread: " + std::to_string((*it)->getThread()) + "\n";
            }
        }
        temp = temp + "\n";
        pr::Doc::detail(temp);
    }
    pr::Doc::detail("--------------------------\n");
}

void Tyres::setOrder(int tyreOrder[3]) {
    for (int x = 0; x < 3; x++) {
        if (tyreOrder[x] > 0) {
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
    tyreSets.push_back(softTyres);
    tyreSets.push_back(mediumTyres);
    tyreSets.push_back(hardTyres);
}


int* Tyres::getTyreOrder() {
    return this->tyreOrder;
}
