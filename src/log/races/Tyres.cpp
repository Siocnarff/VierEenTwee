//
// Created by User on 28-Oct-2020.
//

#include <iostream>
#include "Tyres.h"


rce::Tyres::Tyres(int compound) {
    this->tyreCompoundInt = compound;
    if (compound ==0) {
        this->tyreCompoundString = "Soft Tyres";
    }
    else if(compound == 1) {
        this->tyreCompoundString = "Medium Tyres";
    }
    else if (compound == 2) {
        this->tyreCompoundString = "Hard Tyres";
    }
    this->thread = 100;
    std::cout << "Ordered " << this->tyreCompoundString << std::endl;
}

rce::Tyres::~Tyres() {
    if (!tyreSetList.empty()) {
        for (std::list<Tyres*>::iterator it = tyreSetList.begin(); it != tyreSetList.end(); ++it) {
            delete *it;
        }
    }
    if (tyreSetList.empty()) {
        std::cout << "Cleared List" << std::endl;
    }
}

std::string rce::Tyres::getCompound() {
    return tyreCompoundString;
}

rce::Tyres *rce::Tyres::getTyres(int) {
    return nullptr;
}

int rce::Tyres::getThread() {
    return this->thread;
}

void rce::Tyres::reduceThread() {
    if (thread > 0) {
        thread = thread-5;
    }
}

void rce::Tyres::print() {
    if (!tyreSetList.empty()) {
        int setNum = 1;
        for (std::list<Tyres*>::iterator it = tyreSetList.begin(); it != tyreSetList.end(); ++it) {
            std::cout << "Tyre set #" << setNum++ << std::endl;
            (*it)->print();
        }
    }
    else {
        std::cout << "Tyre compound: " << tyreCompoundString << std::endl;
        std::cout << "Tyre thread: " << std::endl << std::endl;

    }
}
