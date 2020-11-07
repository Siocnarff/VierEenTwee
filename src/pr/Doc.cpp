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
    if (Doc::transparency >= 0 && !outputOverride) {
        std::cout << message << std::flush;
    }
}

void Doc::midInfo(const std::string &message) {
    if (Doc::transparency >= 1  && !outputOverride) {
        std::cout << message << std::flush;
    }
}

void Doc::detail(const std::string &message) {
    if (Doc::transparency >= 2  && !outputOverride ) {
        std::cout << message << std::flush;
    }
}

