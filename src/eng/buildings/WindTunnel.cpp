#include "WindTunnel.h"

using namespace eng;

void WindTunnel::testCar(Car* car) {
	// TODO - implement WindTunnel::testCar
	throw "Not yet implemented";
}

bool WindTunnel::sufficientTickets() {
    if(tickets > 0) {
        tickets--;
        return true;
    }
    return false;
}

WindTunnel::WindTunnel() {
    tickets = 400;
}

WindTunnel *WindTunnel::instance() {
    return new WindTunnel();
}

void WindTunnel::resetTickets() {
    tickets = 400;
}
