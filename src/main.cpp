//
// Created by josuabotha on 2020/10/28.
//

#include <iostream>
#include "factories/HireProfessional.h"
#include <factories/HireAmateur.h>
#include "ppl/factories/KidnapStudent.h"
#include <log/Logistics.h>
#include "eng/EngTeam.h"
#include "rce/RacingDep.h"
#include "pr/Doc.h"

int ppl::Person::idCounter = 0;
int pr::Doc::transparency = 0;

void testBasicIntegration() {
    pr::Doc::setTransparency(1);
    auto* a = new lg::Logistics();
    auto* engDept = new eng::EngTeam();
    auto* racingDept = new rce::RacingDep();
    a->registerNotifier(racingDept);
    a->registerNotifier(engDept);
    a->doYearPlanning();
    a->preSeasonPreparation();
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
    auto* a = new lg::Logistics();

    a->preSeasonPreparation();

    std::cout << "PreSeasonPrep done" << std::endl;

    delete a;

}


void testTyres() {
    int arr1[3] = {2,1,2};
    int arr2[3] = {0,1,4};
    int arr3[3] = {0,0,5};


    auto* tyres1 = new rce::Tyres(arr1);
    auto* tyres2 = new rce::Tyres(arr2);
    auto* tyres3 = new rce::Tyres(arr3);

    tyres1->printStats();
//    tyres2->printStats();
//    tyres3->printStats();

    SetOfTyres* tyreSet1 = tyres1->getTyres(0);
    SetOfTyres* tyreSet2 = tyres1->getTyres(0);
    SetOfTyres* tyreSet3 = tyres1->getTyres(0);


    if (tyreSet1 != nullptr) {
        tyreSet1->printStats();

        tyreSet1->reduceThread();
        tyreSet1->printStats();

        for (int x = 0; x < 20; x++) {
            tyreSet1->reduceThread();
        }

        tyreSet1->printStats();

    }

    if(tyreSet3 == nullptr) {
        std::cout << "No more tyres of that type" << std::endl;
    }

    tyres1->printStats();
    delete tyres1;
    delete tyres2;
    delete tyres3;

}


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
  //  testBasicIntegration();

    /*auto *racingDept = new rce::RacingDep();
    auto *engTeam = new eng::EngTeam();
    auto *lg = new lg::Logistics;

    lg->registerNotifier(racingDept);
    lg->registerNotifier(engTeam);

    engTeam->toggleTransparency();
    lg->toggleVerbose();
    lg->doYearPlanning();

    lg->toggleVerbose();*/
// ERROR : STORE CAR NOT IMPLEMENTED
    //lg->raceSeason();

   /* auto *racingDept = new lg::RacingDept();
    auto *engTeam = new eng::EngTeam();
    auto *lg = new lg::Logistics;

    lg->registerNotifier(racingDept);
    lg->registerNotifier(engTeam);

    engTeam->toggleTransparency();
    lg->toggleVerbose();
    lg->doYearPlanning();

    lg->toggleVerbose();
    lg->raceSeason();
    */

  //  testContainerPacking();

    testTyres();

//    testIterator();

//    testContainerState();

}
