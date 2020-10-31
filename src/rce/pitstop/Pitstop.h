#ifndef RACING_PITSTOP_H
#define RACING_PITSTOP_H
//#include "../eng/Car.h"
//#include "Pitcrew.h"
//#include "Tires.h"

#include "PitCrew.h"
#include "Tyres.h"
#include <eng/Car.h>
#include <list>

namespace rce {
    class Pitstop {

    private:
        std::list<PitCrew *> pitcrew;
        Tyres *tires;

    public:
        void addCrew(std::list<PitCrew *> p);

        void detachCrew(std::list<PitCrew *> p);

        void tyres(Tyres *t);

        void notify();

        void setCar(eng::Car *c);

        //void race();
    };
}
#endif
