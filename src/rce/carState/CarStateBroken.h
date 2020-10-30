#ifndef RACING_CARSTATEBROKEN_H
#define RACING_CARSTATEBROKEN_H

#include "../eng/Car.h"
#include "CarState.h"

namespace rce {
class CarStateBroken : public CarState {


public:
    void handleChange(int i, int d);

    std::string getCarState();
};
}
#endif
