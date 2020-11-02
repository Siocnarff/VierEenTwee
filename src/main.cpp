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

int ppl::Person::idCounter = 0;

void testBasicIntegration() {
    auto* a = new lg::Logistics();
    auto* engDept = new eng::EngTeam();
//    auto* racingDept = new rce::RacingDep();
/*
    a->registerNotifier(racingDept);
    a->registerNotifier(engDept);
    a->doYearPlanning();
    a->preSeasonPreparation();
    a->raceSeason();
    a->postSeasonDebrief();
*/

    delete a;
    delete engDept;
//    delete racingDept;
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
    auto* log = new lg::Logistics();
    auto* rce = new rce::RacingDep();

    log->registerNotifier(rce);

    log->preSeasonPreparation();

    std::cout << "PreSeasonPrep done" << std::endl;

    delete log;
    delete rce;

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
    testBasicIntegration();


    testContainerPacking();

//    testTyres();

//    testIterator();

//    testContainerState();

}

/*
.idea/
cmake-build-debug/
src/.idea/
*/

//src/rce/RacingDep.h src/rce/carState/CarStateFullHP.cpp src/rce/leaderboard/Score.cpp src/rce/pitstop/DriverPitStop.cpp src/rce/pitstop/DriverPitStop.h src/rce/pitstop/Tyres.cpp src/rce/pitstop/Tyres.h rc/rce/strategy/CreateStrategy.cpp src/rce/strategy/CreateStrategy.h src/rce/strategy/ModerateStrategy.cpp src/rce/strategy/ModerateStrategy.h src/rce/strategy/SafeStrategy.h
