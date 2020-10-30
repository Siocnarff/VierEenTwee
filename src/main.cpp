//
// Created by josuabotha on 2020/10/28.
//

#include <iostream>
#include "factories/HireProfessional.h"
#include <factories/HireAmateur.h>
#include <log/Logistics.h>
#include "ppl/factories/KidnapStudent.h"
#include "eng/EngTeam.h"

int ppl::Person::idCounter = 0;

using namespace eng;

int main () {
    /*EngTeam engTeam;
    engTeam.toggleTransparency();
    engTeam.hireEmployees(49);*/

    /*auto** factories = new ppl::HumanResources*[3];
    factories[0] = new ppl::KidnapStudent();
    factories[1] = new ppl::HireAmateur();
    factories[2] = new ppl::HireProfessional();

    std::string jobs[7]  =  {"Draw cars",
                             "Clean things",
                             "Make coffee",
                             "Weld parts together",
                             "Complain",
                             "Count bolts",
                             "Deep sea diver"};

    auto** people = new ppl::Person*[15];
    for (int i = 0; i < 5; ++i) {
        people[i] = factories[0]->hire(jobs[random() % 7]);
        people[i + 5] = factories[1]->hire(jobs[random() % 7]);
        people[i + 10] = factories[2]->hire(jobs[random() % 7]);
    }

    for (int i = 0; i < 15; ++i) {
        people[i]->printResume();
        std::cout << std::endl;
    }*/
//    testBasicIntegration();

    /*auto *racingDept = new rce::RacingDep();
    auto *engTeam = new eng::EngTeam();
    auto *log = new log::Logistics;

    log->registerNotifier(racingDept);
    log->registerNotifier(engTeam);

    engTeam->toggleTransparency();
    log->toggleVerbose();
    log->doYearPlanning();

    log->toggleVerbose();*/
// ERROR : STORE CAR NOT IMPLEMENTED
    //log->raceSeason();



//    testIterator();

//    testContainerState();

}

/*
.idea/
cmake-build-debug/
src/.idea/
*/
