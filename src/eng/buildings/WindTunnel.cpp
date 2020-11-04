#include "WindTunnel.h"

using namespace eng;

void WindTunnel::testCar(Car *car) {
    if(tickets + 16 >= 0) {
        tickets -= 16;
        for (Component *c: car->components) {
            if (c != nullptr) {
                c->setQualityLabel(c->quality - 3 + (rand() % 6));
            }
        }
    }
}

bool WindTunnel::sufficientTickets() {
    return tickets > 0;
}

WindTunnel::WindTunnel() {
    tickets = 400;
}

WindTunnel &WindTunnel::instance() {
    static WindTunnel t;
    return t;
}

void WindTunnel::resetTickets() {
    tickets = 400;
}
