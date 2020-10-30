#include "CarStateBroken.h"

using namespace rce;

void CarStateBroken::handleChange(int i, int d) {
    setDamage(getDamage + d);
    if (getDamage() >= 90) {
        race->NotifyCar();
    }
}

std::string CarStateBroken::getCarState() {
    return "Broken";
}
