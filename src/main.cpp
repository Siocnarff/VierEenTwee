//
// Created by josuabotha on 2020/10/28.
//

#include <iostream>
#include "factories/HireProfessional.h"
#include <factories/HireAmateur.h>
#include <transportation/Road.h>
#include <transportation/Fly.h>
#include <transportation/Ship.h>
#include <races/RacesList.h>
#include "ppl/factories/KidnapStudent.h"
#include "eng/EngTeam.h"
#include "rce/RacingDep.h"
#include "pr/Doc.h"
#include "log/Logistics.h"

int pr::Doc::transparency = 1;

void logDeptTesting();
void engTeamTesting();
void seasonRun(lg::Logistics*);
void testTyres();
void proto_FinalMain();

int main() {

    logDeptTesting();
    engTeamTesting();
    //seasonRun();
//    proto_FinalMain();
//   testTyres();




}

void proto_FinalMain() {
    auto* racingDept = new rce::RacingDep();
    auto* engDept = new eng::EngTeam;
    auto* logDept = new lg::Logistics;

    srand(time(0));
    logDept->registerNotifier(racingDept);
    logDept->registerNotifier(engDept);

    for (int i = 0; i < 3; ++i) {
        seasonRun(logDept);
    }
    //breaks at 4, not at 3


    delete racingDept;
    delete engDept;
    delete logDept;

}


void seasonRun(lg::Logistics* a) {
    a->doYearPlanning();
    a->preSeasonPreparation();
    a->raceSeason();
    a->postSeasonDebrief();
}

void logDeptTesting() {
    //Testing containers
    /*    auto* racingDept = new rce::RacingDep();
    auto* engDept = new eng::EngTeam;
    auto* a = new lg::Logistics;

    lg::TransportHandler* curator = new lg::Road;
    curator->addAMethod(new lg::Ship);
    curator->addAMethod(new lg::Fly);

    auto* race1 = new lg::Race("Aussies",0,1,58);
    auto* race2 = new lg::Race("Mozzies", 2, 1, 26);
    auto* car = new eng::Car(50);

    //transport container between non-european races
    curator->transport(race1, race2); //between races
    curator->transport(nullptr, race2); //from factory
    curator->transport(race1, nullptr); //to factory


    delete racingDept;
    delete engDept;
    delete a;*/
    //Testing racingCalender destructor
    lg::RacesList* r = new lg::RacesList;
    r->addRace(new lg::Race("Australia", 0, 0,12));
    r->addRace(new lg::Race("Benoni", 1, 1,21));
    r->addRace(new lg::Race("Cambridge", 2, 0,112));
    r->addRace(new lg::Race("Dallas", 0, 1,212));
    r->printList();
    delete r;
}


void engTeamTesting() {
    auto *e = new eng::EngTeam();

    e->hireEmployees(100);

    e->setRiskLevel(lg::Moderate);


    int id = e->buildCar(50);

    pr::Doc::setTransparency(1);
    int id2 = e->buildCar(80);
    eng::Car *car = e->checkCarOutOfFactory(id);
    car->print();

    eng::Car *car2 = e->checkCarOutOfFactory(id2);
    car2->print();

    car2->setDamage(50);

    car2->print();

    e->carArrivesAtFactory(car2);
    e->carArrivesAtFactory(car);

    e->fixCar(id2);

    eng::Car *fixedCar = e->checkCarOutOfFactory(id2);

    fixedCar->print();

    delete fixedCar;

    delete e;
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

            tyreSet1->reduceThread(49);
            tyreSet1->printStats();

            for (int x = 0; x < 20; x++) {
                tyreSet1->reduceThread(2);
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
