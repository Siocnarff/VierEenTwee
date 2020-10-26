#ifndef DEV_ELECTRICHARNESS_H
#define DEV_ELECTRICHARNESS_H

#include "Component.h"

namespace eng {
	class ElectricHarness : public Component {

	public:
		void print() final;
	};
}

#endif
