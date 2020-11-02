//
// Created by josuabotha on 2020/10/28.
//

#include <iostream>
#include "factories/HireProfessional.h"
#include <factories/HireAmateur.h>
#include "ppl/factories/KidnapStudent.h"
#include "eng/EngTeam.h"
#include "rce/RacingDep.h"
#include "pr/Doc.h"

int pr::Doc::transparency = 1;

int main() {

    auto* e = new eng::EngTeam();

    e->hireEmployees(10);

    e->setRiskLevel(lg::Aggressive);


    int id = e->buildCar(10);

    //pr::Doc::setTransparency(1);
    int id2 = e->buildCar(10);
    eng::Car* car2 = e->checkCarOutOfFactory(id2);

    eng::Car* car = e->checkCarOutOfFactory(id);

    car->print();

    car2->print();



//    auto* racingDept = new rce::RacingDep();
/*
    a->registerNotifier(racingDept);
    a->registerNotifier(engDept);
    a->doYearPlanning();
    a->preSeasonPreparation();
    a->raceSeason();
    a->postSeasonDebrief();
*/
    delete e;
//    delete racingDept;
}