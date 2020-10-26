#ifndef DEV_CHASSIS_H
#define DEV_CHASSIS_H

#include "Component.h"

namespace eng {
	class Chassis : public Component {

	public:
		void print() final;
	};
}

#endif
