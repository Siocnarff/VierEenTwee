//
// Created by josuabotha on 2020/10/28.
//

#include <iostream>
#include "factories/HireProfessional.h"
#include <factories/HireAmateur.h>
#include <transportation/Road.h>
#include <transportation/Fly.h>
#include <transportation/Ship.h>
#include "ppl/factories/KidnapStudent.h"
#include "eng/EngTeam.h"
#include "rce/RacingDep.h"
#include "pr/Doc.h"
#include "log/Logistics.h"

int pr::Doc::transparency = 1;

void logDeptTesting();
void engTeamTesting();
void seasonRun();

int main() {

    logDeptTesting();
    //    engTeamTesting();
    //seasonRun();

}

void logDeptTesting() {
    auto* racingDept = new rce::RacingDep();
    auto* engDept = new eng::EngTeam;
    auto* a = new lg::Logistics;

    lg::TransportHandler* curator = new lg::Road;
    curator->addAMethod(new lg::Ship);
    curator->addAMethod(new lg::Fly);

    lg::Race* race1 = new lg::Race("Aussies",0,1,58);
    lg::Race* race2 = new lg::Race("Mozzies", 2, 1, 26);
    eng::Car* car = new eng::Car(50);

    //transport container between non-european races
    curator->transport(race1, race2); //between races
    curator->transport(nullptr, race2); //from factory
    curator->transport(race1, nullptr); //to factory


    delete racingDept;
    delete engDept;
    delete a;
}

void seasonRun() {
    auto* racingDept = new rce::RacingDep();
    auto* engDept = new eng::EngTeam;
    auto* a = new lg::Logistics;
     a->registerNotifier(racingDept);
     a->registerNotifier(engDept);
     a->doYearPlanning();
     a->preSeasonPreparation();
     a->raceSeason();
     a->postSeasonDebrief();
    delete racingDept;
    delete engDept;
    delete a;
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