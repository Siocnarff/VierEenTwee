#ifndef ENG_WINDTUNNEL_H
#define ENG_WINDTUNNEL_H

#include "../Car.h"

namespace eng {
    class WindTunnel {
    private:
        int tickets;

        WindTunnel();

    public:
        static WindTunnel &instance();

        void testCar(Car *car);

        bool sufficientTickets();

        void resetTickets();
    };
}

#endif
