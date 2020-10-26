//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_SUBJECT_H
#define PREMODELLING_SUBJECT_H

#include "Car.h"
#include "Container.h"
#include <iostream> //both eng- and racing- need it

namespace log {
    class Mediator;

    class Colleague {
    public:
        ~Colleague();

        void addObserver(Mediator *obs);

        void notify(Car *car);

        void notify(Container *container);

        void notify(bool isEuropeanRace);

        virtual void HireEmployees(int) = 0;

    private:
        Mediator *observer;
    };

}

#endif //PREMODELLING_SUBJECT_H
