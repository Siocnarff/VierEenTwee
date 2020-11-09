//
// Created by User on 31-Oct-2020.
//

#include <iostream>
#include "SetOfTyres.h"

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
//    std::cout << "     Ordered " << this->tyreCompoundString << std::endl;
}

SetOfTyres::~SetOfTyres() {}

int SetOfTyres::getThread() {
    return thread;
}

void SetOfTyres::reduceThread(int damage) {
    if (thread > damage && damage > 0) {
        thread = thread - damage;
    }
    else
   {

        std::string output = "Tyres worn out\n";
        pr::Doc::detail(output);
    }
}

std::string SetOfTyres::getTyreCompoundString() {
    return tyreCompoundString;
}

void SetOfTyres::printStats()
{
    std::string output = tyreCompoundString;
    output.append(" - Thread: ");
    output.append(std::to_string(getThread()));
    output.append("\n");
    pr::Doc::detail(output);
//    std::cout << tyreCompoundString << " - Thread: " << getThread() << std::endl;
}


