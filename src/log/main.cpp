#include <iostream>

#include "Logistics.h"

void testBasicIntegration() {
    RacingDept* racingDept = new RacingDept();
    EngDept* engDept = new EngDept();
    Logistics* a = new Logistics;

    a->registerNotifier(racingDept);
    a->registerNotifier(engDept);

    a->doYearPlanning();
    a->preSeasonPreparation();
    a->raceSeason();
    a->postSeasonDebrief();

    delete a;
    delete engDept;
    delete racingDept;
}

void testIterator(){
    string names[5] = {"malibu", "florence", "florida", "vermont","venice"};
    TrackComplexity complexity[5] = {Difficult, Easy, Extreme, Average, Easy};
    bool european[5] = {1,0,1,1,0};
    RacesList* raceList = new RacesList;
    for (int i = 0; i < 5; ++i) {
        raceList->addRace(new Race(names[i], complexity[i], european[i]));
    }

    Race* temp = raceList->getHeadRace();
    while (temp!= NULL) {
        cout << temp->getLocation() << endl;
        temp = temp->nextRace();
    }
    cout << endl;

    for (RaceIterator t = raceList->begin(); !(t==raceList->end()) ; ++t) {
        cout << t.currentItem()->getLocation() << endl;
    }
    cout << endl;

    raceList->addRace(new Race("vantance", Easy, 0));
    for (RaceIterator t = raceList->begin(); !(t==raceList->end()) ; ++t) {
        cout << t.currentItem()->getLocation() << endl;
    }

}

void testContainerState() {
    Container* container = new Container();
    cout << endl;

    for (int i = 0; i < 4; ++i) {
        cout << container->getState() << endl;
        container->advanceState();
    }

    cout << "\nWacky Containers!" << endl;
}



int main() {


    //testBasicIntegration();

    //testIterator();

    //testContainerState();

    return 0;
}
