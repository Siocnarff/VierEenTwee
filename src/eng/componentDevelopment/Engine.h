#ifndef DEV_ENGINE_H
#define DEV_ENGINE_H

#include "Component.h"

namespace eng {
	class Engine : public Component {

	public:
		void print() final;
	};
}

#endif
