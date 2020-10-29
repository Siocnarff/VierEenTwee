#include <iostream>
#include <races/RacesList.h>

#include "Logistics.h"

void testBasicIntegration() {
    RacingDept* racingDept = new RacingDept();
    eng::EngTeam* engDept = new eng::EngTeam();
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
    std::string names[5] = {"malibu", "florence", "florida", "vermont","venice"};
    TrackComplexity complexity[5] = {Difficult, Easy, Extreme, Average, Easy};
    bool european[5] = {1,0,1,1,0};
    RacesList* raceList = new RacesList;
    for (int i = 0; i < 5; ++i) {
        raceList->addRace(new Race(names[i], complexity[i], european[i]));
    }

    Race* temp = raceList->getHeadRace();
    while (temp!= NULL) {
        std::cout << temp->getLocation() << std::endl;
        temp = temp->nextRace();
    }
    std::cout << std::endl;

    for (RaceIterator t = raceList->begin(); !(t==raceList->end()) ; ++t) {
        std::cout << t.currentItem()->getLocation() << std::endl;
    }
    std::cout << std::endl;

    raceList->addRace(new Race("vantance", Easy, 0));
    for (RaceIterator t = raceList->begin(); !(t==raceList->end()) ; ++t) {
        std::cout << t.currentItem()->getLocation() << std::endl;
    }

}

void testContainerState() {
    Container* container = new Container();
    std::cout << std::endl;

    for (int i = 0; i < 4; ++i) {
        std::cout << container->getState() << std::endl;
        container->advanceState();
    }

    std::cout << "\nWacky Containers!" << std::endl;
}


int ppl::Person::idCounter = 0;

int main() {

    srand((unsigned) time(0)); // for good randomness;

    //testBasicIntegration();

    //testIterator();

    testContainerState();

    return 0;
}
