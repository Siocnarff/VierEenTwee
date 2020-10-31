#include "MicroInitiationPlutoniumHammer.h"

using namespace eng;
void MicroInitiationPlutoniumHammer::print() {
    std::cout   << "        MicroInitiationPlutoniumHammer Quality: " << getQualityLabel() << std::endl;
}

MicroInitiationPlutoniumHammer::MicroInitiationPlutoniumHammer(Component *toClone) : Component(toClone) {}

Component *MicroInitiationPlutoniumHammer::clone() {
    return new MicroInitiationPlutoniumHammer(this);
}

int MicroInitiationPlutoniumHammer::getId() {
    return 4;
}

MicroInitiationPlutoniumHammer::MicroInitiationPlutoniumHammer(int quality) : Component(quality) {

}
