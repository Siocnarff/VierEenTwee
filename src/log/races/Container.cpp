//
// Created by jo on 2020/10/17.
//

#include "Container.h"
#include <iostream>
using namespace lg;

Container::Container() {
}

Container::~Container() {

}

void Container::unpack() {
    //Unpack gaan net werk in die hoof container. Dit moenie geroep word later nie.

    //Print alles uit

    //Gaan soek die container wat 'n tyreBox is om dit te return . . . tyre variable to return? Ja. Okay.

    std::cout << "CONTAINER UNPACK BY printing out contents and returning the tyres in the container" << std::endl;

}

/**
 *@author Marike
 * @param usedTyres
 */
void Container::pack() {

    //Pack container up and put in the "used" tyres.

    std::cout << "print out contents" << std::endl;

}

void Container::addElement(Container * newContainer) {
    std::cout << "Pack box into main container" << std::endl;
}

void Container::print() {
    std::cout << "The container is currently empty" << std::endl;
}

