//
// Created by jo on 2020/10/09.
//

#include "transportation/Fly.h"
#include "transportation/Ship.h"
#include "transportation/Road.h"
#include "Logistics.h"
#include "RacesList.h"

#include <fstream>
#include <sstream>
#include <log/races/Box.h>
#include <log/races/GarageEquipment.h>
#include <log/races/CateringEquipment.h>
#include <log/races/TyreBox.h>


using namespace log;

void Logistics::registerNotifier(Colleague *colleague) {
    auto* temp = new rce::RacingDept;
    if (typeid(*temp) == typeid(*colleague)){
        departments.insert(pair<char,Colleague*>('r',colleague));
    } else {
        departments.insert(pair<char,Colleague*>('e',colleague));
    }
    colleague->addObserver(this);

}

void Logistics::doYearPlanning() {
    //1. getBudget from "Sponsors"
    //2. Hire for all departments
    for( auto const& [key, val] : departments )
    {
        val->hireEmployees(budget);
    }
    //3. putRacesIntoCalender();
    //4. hire driver
    //5. hire transportManager


}

void Logistics::preSeasonPreparation() {
//    currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget /*+ something else? */ );
    /*depts[0] -> planSeasonStrategy(); //of wil ons chain gebruik hierso
    as genotify word, sal ons binne notify() die bande bestel;
    print: tyres arrived*/

    //Pack containers right after tyre compound received

    int tyrecompound = 2;

    packContainers(tyrecompound);

    //moet meer spesifiek wees hierso.
    //gaan ons van hulle verwag of gaan ons self check dat die driver genoeg xp het?
    //Dalk kan ons dit volgens riskLevel doen
//    callRacingDept()->trainDriver(new ppl::Driver("s",0,0), 15, Rainy, Average );

    //order stuff

    //build cars x2
//    carsInSeasonIDs.push_back(callEngDept()->buildCar(budget,currentTeamStrategy->getRiskLevel())); //tyres

    /*carsInSeason.push(buildCar()); //ons gaan bou die kar
    testCar();
    getRaceIterator();
   */

}


void Logistics::raceSeason() {
    /* while (iter.hasNext()) {
         * simulateEvent(iter.current); <- this could be a command
         * //we could have raceHandlers(one for European and one for non-European?)
         * iter++;
         */
    //2 cars
    callRacingDept()->preRaceArrival(new eng::Car(3), driver, new Race, new Container);
    //
    seasonPointTally += callRacingDept()->RacingWeekend();
    callRacingDept()->postRacePackUp(); //execute

}

void Logistics::postSeasonDebrief() {
//maybe do some analysis?
    //start building a new car
    //let driver take holiday
    //let transportHandler take holiday

}

void Logistics::sendCarToFactory(eng::Car *car) {
    cout << "send car to factory" << endl;
    transportManager->transport(new Race, new Race, car);
    callEngDept()->carArrivesAtFactory(car);
    callEngDept()->improveCar(car->getId());
}

void Logistics::containerHasBeenPacked(Container *) {
    cout << "fly container" << endl;
}

void Logistics::requestContainerStateChange(bool isEuropeanRace) {

}

Container *Logistics::getEuropeanContainer() {
    return europeanContainer;
}

Container *Logistics::getNextNonEuropean() {
    Container* back = nonEuropeanContainers.back();
    nonEuropeanContainers.pop_back();
    return back;
}

void Logistics::packContainers(int tyreCompound) {

    //Need to create container objects to match to races
    //Test by packing a single container:

    Container *container = packSingleContainer(tyreCompound);

    cout << "Packed all containers" << endl;

}

Container* Logistics::packSingleContainer(int tyreCompound) {
    Box* box = new Box();
    GarageEquipment* garageEquip = new GarageEquipment();
    CateringEquipment* cateringEquip = new CateringEquipment();
    TyreBox* tyreBox = new TyreBox(tyreCompound);

    box->addElement(garageEquip);
    box->addElement(cateringEquip);
    box->addElement(tyreBox);

    cout << "Packed a container" << endl;

    return box;

}

void Logistics::SimulateEvent(Race *) {
    //callRacingDept;
}

void Logistics::putRacesIntoCalender() {
    cout << "put races into calender" << endl;
}

rce::RacingDept *Logistics::callRacingDept() {
    return dynamic_cast<rce::RacingDept*>(departments['r']);
}

eng::EngTeam *Logistics::callEngDept() {
    return dynamic_cast<eng::EngTeam*>(departments['e']);
}

/**
 * @author Berné
 */
Logistics::Logistics() {
    transportManager = new Fly();
    transportManager->addAMethod(new Ship);
    transportManager->addAMethod(new Road);
}


/**
 * @author Jo
 */
void Logistics::toggleVerbose() {
    verbose = !verbose;
}

