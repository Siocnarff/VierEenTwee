//
// Created by User on 30-Oct-2020.
//

#include "TyreBox.h"

using namespace log;

TyreBox::TyreBox(int tyreCompound) {
    tyres = new rce::Tyres(tyreCompound);
}

TyreBox::~TyreBox() throw() {
    delete tyres;
}

rce::Tyres* TyreBox::getTyres() {
    return tyres;
}