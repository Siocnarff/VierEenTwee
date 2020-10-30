//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_SUBJECT_H
#define PREMODELLING_SUBJECT_H

#include "Car.h"
#include "races/Container.h"
#include "Strategy.h"
//#include <iostream> //both eng- and racing- need it
namespace log {
    class Mediator;

    class Colleague {
    public:
        explicit Colleague(Mediator* mediator);

        Colleague();

        virtual ~Colleague();

        void addObserver(Mediator *obs);

        void notify(eng::Car *car);

        void notify(Container *container);

        void notify(bool isEuropeanRace);

        void notify(rce::Strategy*);

        void notify(int* tyreCompoundOrder); // list of 3

        virtual void hireEmployees(int) = 0;

        void notify(log::RiskLevel*);

    private:
        Mediator *logisticsDep;
    };

}

#endif //PREMODELLING_SUBJECT_H
