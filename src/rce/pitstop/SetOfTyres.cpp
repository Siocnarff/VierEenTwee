//
// Created by User on 31-Oct-2020.
//

#include <iostream>
#include <Doc.h>
#include "SetOfTyres.h"

using namespace rce;

SetOfTyres::SetOfTyres(int compound) {
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
}

SetOfTyres::~SetOfTyres() {}

int SetOfTyres::getThread() {
    return thread;
}

void SetOfTyres::reduceThread(int damage) {
    if (thread > damage && damage > 0) {
        thread = thread - damage;
    }
    else {
        pr::Doc::detail("Tyres worn out\n");
    }
}

std::string SetOfTyres::getTyreCompoundString() {
    return tyreCompoundString;
}

std::string SetOfTyres::printStats() {
    return tyreCompoundString + " - Thread: " + std::to_string(getThread());
}


