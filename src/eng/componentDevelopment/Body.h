#ifndef DEV_BODY_H
#define DEV_BODY_H

#include "Component.h"

namespace eng {
	class Body : public Component {
    private:
	    explicit Body(Component * toClone);

	public:
		void print() final;

		Component* clone() final;

		int getId() final;
	};
}

#endif
