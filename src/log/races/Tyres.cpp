//
// Created by User on 28-Oct-2020.
//

#include <iostream>
#include "Tyres.h"


rce::Tyres::Tyres(int compound) {
    if (compound ==0) {
        this->tyreCompound = "Soft Tyres";
    }
    else if(compound == 1) {
        this->tyreCompound = "Medium Tyres";
    }
    else if (compound == 2) {
        this->tyreCompound = "Hard Tyres";
    }
    this->thread = 100;
    std::cout << "Ordered " << this->tyreCompound << std::endl;
}

rce::Tyres::~Tyres() {

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
