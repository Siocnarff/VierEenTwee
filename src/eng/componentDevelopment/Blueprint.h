#ifndef DEV_BLUEPRINT_H
#define DEV_BLUEPRINT_H

#include <vector>

namespace eng {
    class Blueprint {
    	friend class Component;

    private:
        std::vector<int> state;

        std::vector<int> getState();

        void setState(std::vector<int> state);
    };
}



#endif
