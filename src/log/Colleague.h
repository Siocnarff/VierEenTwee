//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_SUBJECT_H
#define PREMODELLING_SUBJECT_H

#include <races/Race.h>
#include "Car.h"
#include "containers/Container.h"
//#include <iostream> //both eng- and racing- need it
namespace lg {
    class Mediator;

    class Colleague {
    public:
        virtual ~Colleague();

        void addObserver(Mediator *obs);

        void notify(std::vector<eng::Car *>cars, Race*);

        void notify(eng::Car* brokenCar, Race*);

        /*void notify(Container *container);*/

        void notify(bool isEuropeanRace);

        void notify(int* tyreOrder);

        virtual void hireEmployees(int) = 0;

    protected:
        Mediator *logisticsDept;
    };

}

#endif //PREMODELLING_SUBJECT_H
