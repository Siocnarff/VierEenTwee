//
// Created by User on 31-Oct-2020.
//

#ifndef VIEREENTWEE_SETOFTYRES_H
#define VIEREENTWEE_SETOFTYRES_H


namespace rce {

    class SetOfTyres {
    public:
        SetOfTyres(int);

        ~SetOfTyres();

        int getThread();

        std::string getTyreCompoundString();

        void reduceThread(int);

        void printStats();

    private:
        int thread;

        int tyreCompoundInt;

        std::string tyreCompoundString;

    };
}


#endif //VIEREENTWEE_SETOFTYRES_H
