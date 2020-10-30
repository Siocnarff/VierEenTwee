//
// Created by josuabotha on 2020/10/28.
//

#include <iostream>
#include <factories/HireProfessional.h>
#include "eng/EngTeam.h"
#include "log/races/RacesList.h"
#include "log/Logistics.h"

int ppl::Person::idCounter = 0;

using namespace log;

void testBasicIntegration() {
    auto* a = new Logistics();
    auto* engDept = new eng::EngTeam;
    auto* racingDept = new rce::RacingDept;

//    cout << "Created departments" << endl;
//    cout << "-------------------" << endl;
    a->registerNotifier(racingDept);
//    cout << "Regestered RacingTeam" << endl;
//    cout << "---------------------" << endl;

    a->registerNotifier(engDept);

    a->doYearPlanning();
//    cout << "Year planning done" << endl;
//    cout << "--------------------" << endl;
    a->preSeasonPreparation();

//    cout << "PreSeason prep done" << endl;
//    cout << "--------------------" << endl;
    a->raceSeason();
    a->postSeasonDebrief();

    delete a;
    delete engDept;
    delete racingDept;
}

void testIterator(){
//    std::string names[5] = {"malibu", "florence", "florida", "vermont","venice"};
//    int complexity[5] = {2, 0, 3, 1, 0};
//    bool european[5] = {true,false,true,true,false};
//    int laps[5] = {32,14,56,67,20};
//    RacesList* raceList = new RacesList;
//    for (int i = 0; i < 5; ++i) {
//        raceList->addRace(new Race(names[i], complexity[i], laps[i], european[i]));
//    }
//
//    Race* temp = raceList->getHeadRace();
//    while (temp!= NULL) {
//        std::cout << temp->getLocation() << std::endl;
//        temp = temp->nextRace();
//    }
//    std::cout << std::endl;
//
//    for (RaceIterator t = raceList->begin(); !(t==raceList->end()) ; ++t) {
//        std::cout << t.currentItem()->getLocation() << std::endl;
//    }
//    std::cout << std::endl;
//
//    raceList->addRace(new Race("vantance", 0, 0, 16));
//    for (RaceIterator t = raceList->begin(); !(t==raceList->end()) ; ++t) {
//        std::cout << t.currentItem()->getLocation() << std::endl;
//    }

}

void testContainerPacking() {
    auto* a = new Logistics();

    a->preSeasonPreparation();

    std::cout << "PreSeasonPrep done" << std::endl;

    delete a;

}



int main () {
//    EngTeam engTeam;
//    engTeam.hireEmployees(49);

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

//    auto* a = new Logistics;
//    auto* racingDept = new rce::RacingDept(a);
//    auto* engDept = new eng::EngTeam(a);
//    //engDept->toggleTransparency();
//
//    a->registerNotifier(racingDept);
//
//    a->registerNotifier(engDept);
//
//    a->doYearPlanning();
//
//    a->toggleTransparency();
   // a->raceSeason();

//    testIterator();

    testContainerPacking();

}