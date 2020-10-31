//
// Created by User on 31-Oct-2020.
//

#ifndef VIEREENTWEE_SETOFTYRES_H
#define VIEREENTWEE_SETOFTYRES_H


class SetOfTyres {
public:
    SetOfTyres(int);

    ~SetOfTyres();

    int getThread();

    void reduceThread();

    void printStats();

private:
    int thread;

    int tyreCompoundInt;

    std::string tyreCompoundString;

};


#endif //VIEREENTWEE_SETOFTYRES_H
