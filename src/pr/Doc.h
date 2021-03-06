//
// Created by josuabotha on 2020/10/31.
//

#ifndef VIEREENTWEE_DOC_H
#define VIEREENTWEE_DOC_H


#include <string>

namespace pr {
    class Doc {
    private:
        Doc();

    public:
        static int transparency;
        static bool outputOverride;

        static void setTransparency(int outOf2);

        static void summary(const std::string& message);

        static void detail(const std::string& message);

        static void midInfo(const std::string& message);

        static Doc & instance();
    };
}



#endif //VIEREENTWEE_DOC_H
