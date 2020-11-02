#include "WindTunnel.h"

using namespace eng;

void WindTunnel::testCar(Car *car) {
    for (Component *c: car->components) {
        c->setQualityLabel(c->quality - 3 + (rand() % 6));
    }
}

bool WindTunnel::sufficientTickets() {
    if (tickets > 0) {
        tickets--;
        return true;
    }
    return false;
}

WindTunnel::WindTunnel() {
    tickets = 400;
}

WindTunnel *WindTunnel::instance() {
    if (tunnel) {
        return tunnel;
    }
    return new WindTunnel();
}

void WindTunnel::resetTickets() {
    tickets = 400;
}
