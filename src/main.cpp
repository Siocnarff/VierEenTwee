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

int pr::Doc::transparency = 0;

void testBasicIntegration() {
    pr::Doc::setTransparency(1);
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
    delete engDept;
//    delete racingDept;
}