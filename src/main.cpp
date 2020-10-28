//
// Created by josuabotha on 2020/10/28.
//

#include <iostream>
#include <factories/HireProfessional.h>
#include <factories/HireAmateur.h>
#include "ppl/factories/KidnapStudent.h"
#include "eng/EngTeam.h"

int ppl::Person::idCounter = 0;

using namespace eng;

int main () {
    EngTeam engTeam;
    engTeam.hireEmployees(49);

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
}