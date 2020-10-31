#include "CarStateFullHP.h"

using namespace rce;

void CarStateFullHP::handleChange(int i, int d) {
    /*if (d > 0 && d < 90) {
        setDamage(d);
        race->setCState(new)

    } else {
        if (d >= 90)
            race->setCState(new)

    }*/
}

std::string CarStateFullHP::getCarState() {
    return "FullHP";
}
