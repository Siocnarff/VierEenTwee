#ifndef RACING_CARSTATEDAMAGED_H
#define RACING_CARSTATEDAMAGED_H
#include "../eng/Car.h"
#include "CarState.h"
namespace rce {
    class CarStateDamaged : public CarState {


    public:
        void handleChange(int i, int d);

        std::string getCarState();
    };
}
#endif
