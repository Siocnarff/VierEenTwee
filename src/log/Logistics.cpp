//
// Created by jo on 2020/10/09.
//

#include "transportation/Fly.h"
#include "transportation/Ship.h"
#include "transportation/Road.h"
#include "Logistics.h"

using namespace log;


/**
 * @author Berné
 */
void Logistics::registerNotifier(Colleague *colleague) {
    auto* temp = new RacingDept;
    if (typeid(*temp) == typeid(*colleague)){
        departments.insert(pair<char,Colleague*>('r',colleague));
    } else {
        departments.insert(pair<char,Colleague*>('e',colleague));
    }
    colleague->addObserver(this);

}
/**
 * @author Berné
 */
void Logistics::doYearPlanning() {

    //1. getBudget from "Sponsors"
    budget = abs(rand()%100+1);
    //2. Hire for all departments
    for( auto const& [key, val] : departments )
    {
        val->hireEmployees(budget);
    }
    //3. putRacesIntoCalender();
    putRacesIntoCalender();
    //4. hire driver
    driver = new ppl::Driver("Fluffy McAllen", 0, 0);
    //5. Set home tracks

    //6. hire transportManager
    transportManager = new Road();
    transportManager->addAMethod(new Ship);
    transportManager->addAMethod(new Fly);

}

void Logistics::preSeasonPreparation() {
    currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget /*+ something else? */ );
    /*depts[0] -> planSeasonStrategy(); //of wil ons chain gebruik hierso
    as genotify word, sal ons binne notify() die bande bestel;
    print: tyres arrived*/

    callRacingDept()->trainDriver(new ppl::Driver("s",0,0), 15, Rainy, Average );
    //order

//    cout <<"Debugging" << endl;
//    cout << "-------------------" << endl;

    carsInSeasonIDs.push_back(callEngDept()->buildCar(budget,currentTeamStrategy->getRiskLevel())); //tyres   -> iets fout met hierdie funksie?
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

/**
 * @author Berné
 */
RacingDept *Logistics::callRacingDept() {
    return dynamic_cast<RacingDept*>(departments['r']);
}

/**
 * @author Berné
 */
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

