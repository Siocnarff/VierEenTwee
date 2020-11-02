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

    e->hireEmployees(50);

    e->setRiskLevel(lg::Aggressive);


    int id = e->buildCar(50);

    //pr::Doc::setTransparency(1);

    eng::Car* car = e->checkCarOutOfFactory(id);

    car->print();



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