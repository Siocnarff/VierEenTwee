//
// Created by jo on 2020/10/09.
//

#include "transportation/Fly.h"
#include "transportation/Ship.h"
#include "transportation/Road.h"
#include "Logistics.h"

using namespace log;

void Logistics::registerNotifier(Colleague *colleague) {
    auto* temp = new RacingDept;
    if (typeid(*temp) == typeid(*colleague)){
        departments.insert(std::pair<char,Colleague*>('r',colleague));
    } else {
        departments.insert(std::pair<char,Colleague*>('e',colleague));
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
    currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget /*+ something else? */ );
    /*depts[0] -> planSeasonStrategy(); //of wil ons chain gebruik hierso
    as genotify word, sal ons binne notify() die bande bestel;
    print: tyres arrived*/

    callRacingDept()->trainDriver(new ppl::Driver("s",0,0), 15, Rainy, Average );
    //order
    carsInSeasonIDs.push_back(callEngDept()->buildCar(budget)); //tyres
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
    std::cout << "send car to factory" << std::endl;
    transportManager->transport(new Race, new Race, car);
    callEngDept()->carArrivesAtFactory(car);
    callEngDept()->improveCar(car->getId());
}

void Logistics::containerHasBeenPacked(Container *) {
    std::cout << "fly container" << std::endl;
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
    std::cout << "pack containers" << std::endl;
}

void Logistics::simulateEvent(Race *) {
    //callRacingDept;
}

void Logistics::putRacesIntoCalender() {
    std::cout << "put races into calender" << std::endl;
}

RacingDept *Logistics::callRacingDept() {
    return dynamic_cast<RacingDept*>(departments['r']);
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

void Logistics::informStrategyChanged(rce::Strategy *) {
//TODO: implement this
}

