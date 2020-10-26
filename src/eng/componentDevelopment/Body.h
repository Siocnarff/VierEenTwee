#ifndef DEV_BODY_H
#define DEV_BODY_H

#include "Component.h"

namespace eng {
	class Body : public Component {

	public:
		void print() final;
	};
}

#endif
