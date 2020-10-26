#ifndef DEV_BLUEPRINT_H
#define DEV_BLUEPRINT_H

#include <vector>

namespace dev {
    class Blueprint {

    private:
        std::vector<int> state;

    public:
        std::vector<int> getState();

        void setState(std::vector<int> state);
    };

}



#endif
