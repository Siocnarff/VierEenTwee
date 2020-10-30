//
// Created by jo on 2020/10/17.
//

#include "Container.h"
#include <iostream>
using namespace log;

Container::Container() {
}

Container::~Container() {

}

rce::Tyres * Container::unpack() {


    std::cout << "CONTAINER UNPACK BY printing out contents and returning the tyres in the container" << std::endl;
    return nullptr;

}

void Container::pack() {
    //nodig om dit te roep? ek dink nie meer so nie



    std::cout << "print out contents" << std::endl;
    //some other stuff

}

void Container::addElement(Container * newContainer) {
    std::cout << "Pack box into main container" << std::endl;
}

