#ifndef RACING_PITSTOP_H
#define RACING_PITSTOP_H
//#include "../eng/Car.h"
//#include "Pitcrew.h"
//#include "Tires.h"
#include "../people/Pitcrew.h"

namespace rce {
    class Pitstop {

    private:
        list<people::Pitcrew *> pitcrew;
        racing::Tires *tires;

    public:
        void addCrew(list<people::Pitcrew *> p);

        void detachCrew(list<people::Pitcrew *> p);

        void tyres(racing::Tires *t);

        void notify();

        void setCar(eng::Car *c);

        //void race();
    };
}
#endif
