#ifndef RACING_PITCREW_H
#define RACING_PITCREW_H


#include <RaceDaysIterator.h>

namespace rce {
    class PitCrew {
    public:
        PitCrew();

        void setCar(RaceDaysIterator *c);

        virtual void changetyres() = 0;
    };
}
#endif
