#ifndef DEV_RISK_H
#define DEV_RISK_H

#include <random>
#include <chrono>

namespace eng {
	class Risk {

	public:
	    virtual ~Risk() = default;

        virtual int trySomethingNew() = 0;
	};
}

#endif
