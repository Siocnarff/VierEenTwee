#include "MicroInitiationPlutoniumHammer.h"

using namespace eng;
void MicroInitiationPlutoniumHammer::print() {
    pr::Doc::detail("\tMicroInitiationPlutoniumHammer Quality: " + std::to_string(getQualityLabel()));
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
