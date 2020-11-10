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
    if (transparency >= 0 && !outputOverride) {
        std::cout << message << std::flush;
    }
}

void Doc::midInfo(const std::string &message) {
    if (transparency >= 1  && !outputOverride) {
        std::cout << message << std::flush;
    }
}

void Doc::detail(const std::string &message) {
    if (transparency >= 2  && !outputOverride ) {
        std::cout << message << std::flush;
    }
}

Doc &Doc::instance() {
    static Doc d;
    return d;
}

Doc::Doc() = default;

