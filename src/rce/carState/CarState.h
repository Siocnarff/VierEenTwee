#ifndef RACING_CARSTATE_H
#define RACING_CARSTATE_H

#include <rce/RaceWeekend.h>
#include "../eng/Car.h"

namespace rce {
    class CarState {

    private:
        int damage;
        int car;

    public:
        RaceWeekend *race;

        CarState(RaceWeekend *r);

        virtual void handleChange(int i, int d) = 0;

        virtual std::string getCarState() = 0;

        int getDamage();

        void setDamage(int damage);

        void Deal_damage(int d);
    };
}
#endif
