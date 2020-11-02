//
// Created by josuabotha on 2020/10/31.
//

#include <iostream>
#include "Doc.h"

using namespace pr;

void Doc::setTransparency(int outOf2) {
    transparency = outOf2;
}

void Doc::summary(const std::string& message) {
    if (Doc::transparency > 0) {
        std::cout << message;
    }
}

void Doc::detail(const std::string &message) {
    if (Doc::transparency >= 1) {
        std::cout << message;
    }
}
