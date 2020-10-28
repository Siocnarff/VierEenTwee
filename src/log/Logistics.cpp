//
// Created by jo on 2020/10/09.
//

#include <log/transportation/Fly.h>
#include <log/transportation/Ship.h>
#include <log/transportation/Road.h>
#include "Logistics.h"

using namespace log;

void Logistics::registerNotifier(Colleague *colleague) {
    RacingDept* temp = new RacingDept;
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
        val->HireEmployees(budget);
    }
    //3. putRacesIntoCalender();
    //4. hire driver
    //5. hire transportManager


}

void Logistics::preSeasonPreparation() {
    currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget /*+ something else? */ );
    /*depts[0] -> planSeasonStrategy(); //of wil ons chain gebruik hierso
    as genotify word, sal ons binne notify() die bande bestel;
    print: tyres arrived*/

    callRacingDept()->trainDriver(new ppl::Driver("s",0,0), 15, Rainy, Average );
    //order
    carsInSeasonIDs.push_back(callEngDept()->buildCar(budget,currentTeamStrategy->getRiskLevel())); //tyres
    /*carsInSeason.push(buildCar()); //ons gaan bou die kar
    testCar();
    getRaceIterator();
    packContainers();*/

}

void Logistics::raceSeason() {
    /* while (iter.hasNext()) {
         * simulateEvent(iter.current); <- this could be a command
         * //we could have raceHandlers(one for European and one for non-European?)
         * iter++;
         */
    //2 cars
    callRacingDept()->preRaceArrival(new eng::Car, driver, new Race, new Container);
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

void Logistics::packContainers() {
    cout << "pack containers" << endl;
}

void Logistics::SimulateEvent(Race *) {
    //callRacingDept;
}

void Logistics::putRacesIntoCalender() {
    cout << "put races into calender" << endl;
}

RacingDept *Logistics::callRacingDept() {
    return static_cast<RacingDept*>(departments['r']);
}

EngDept *Logistics::callEngDept() {
    return static_cast<EngDept*>(departments['e']);
}

/**
 * @author Berné
 */
Logistics::Logistics() {
    transportManager = new Fly();
    transportManager->addAMethod(new Ship);
    transportManager->addAMethod(new Road);
}

