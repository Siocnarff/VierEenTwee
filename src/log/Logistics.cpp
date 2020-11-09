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
#include <random>
#include <containers/Box.h>
#include <containers/GarageEquipment.h>
#include <containers/CateringEquipment.h>
#include <factories/HireDriver.h>
#include <algorithm>
#include "enums/randomisation.h"
#include <string>

using namespace lg;

// DONE : @jo Implement and check accuracy of pop and push for cars
// IDEA : approach budget people in the middle to ask for raise?
// IDEA : use up the budget
// DONE : @jo delete cars in season
// DONE : change "This is race x to be fancier"
// DONE : change "preseason" to be fancier
// todolist : @both fix memleaks

// TODO : @marike couts
// TODO : @marike standardise
// TODO : remove/change doxygen commentaries (or we can leave them in so that others laugh)

/**
 * @author Jo
 * @status Done and dusted!
 */
Logistics::Logistics(int numDriverCarPairs) {
    numPairs = numDriverCarPairs;
    drivers.reserve(numDriverCarPairs);
    carsInSeasonIDs.reserve(numDriverCarPairs);
    seasonPointTally.reserve(numDriverCarPairs);
    transportManager = nullptr;
    racingCalendar = nullptr;
    europeanContainer = nullptr;
    currentTeamStrategy = nullptr;
    budget = -1;
    interactiveDemo = false;
}


Logistics::~Logistics() {
    if (racingCalendar != nullptr) {
        // TODO : @jo finish destructor racingCalendar
        //delete accordingly
        delete racingCalendar;
    }
    if (europeanContainer != nullptr) delete europeanContainer;
    if (currentTeamStrategy != nullptr) delete currentTeamStrategy;
};

/**
 * @status completed
 * @param colleague
 */
void Logistics::registerNotifier(Colleague *colleague) {
    auto *temp = new eng::EngTeam;
    if (typeid(*temp) == typeid(*colleague)) {
        departments.insert(pair<char, Colleague *>('e', colleague));
    } else {
        //colleague->notify(true);
        departments.insert(pair<char, Colleague *>('r', colleague));
    }
    colleague->addObserver(this);

}

/**
 * @author Jo
 * @status really finished
 */
void Logistics::doYearPlanning() {
    //pr::Doc::summary("\n>>Plan Racing Year\n--------------------\n");
    pr::Doc::summary("\n   _   _   _   _     _   _   _   _   _   _     _   _   _   _  \n");
    pr::Doc::summary("  / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\\n");
    pr::Doc::summary(" ( P | l | a | n ) ( R | a | c | i | n | g ) ( Y | e | a | r )\n");
    pr::Doc::summary("  \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/\n");


    //1. getBudget from "Sponsors"
    pr::Doc::summary("\n  ~Set team budget~\n");
    sponsoredBudget();


    //2. Hire emplpoyees: each department
    pr::Doc::summary("\n  ~Hire employees for each department~\n");

    if (interactiveDemo) {
        pr::Doc::summary("\nDo you want to see full resume's? Y/N\n");
        std::cin >> interactionInput;
        if (interactionInput[0] == '*') {
            changeTransparency();
            interactionInput = interactionInput[1];
        }
        if (interactionInput == "Y" || interactionInput == "y") {
            pr::Doc::transparency = 2;
        } else {
            pr::Doc::transparency = 0;
        }
    }
    for (auto const&[key, val] : departments) {
        val->hireEmployees(budget);
    }

    //3. Set tickets of racingDept;
    pr::Doc::summary("\n  ~Assign training tickets to racing department as per regulations~\n");
    callEngDept()->resetTickets();

    //4. putRacesIntoCalender();
    pr::Doc::summary("\n  ~Find out which tracks will be used this season~\n");
    putRacesIntoCalender();

    //5. Hire drivers
    pr::Doc::summary("\n  ~Hire drivers~\n");
    ppl::HireDriver driverCurator;
    for (int i = 0; i < numPairs; ++i) {
        drivers.push_back(dynamic_cast<ppl::Driver *>(driverCurator.hire("Driver")));
    }

    //6. Set drivers' home tracks
    for (ppl::Driver *d : drivers) {        //for each driver
        int rand_hom_tracks = abs(rand() % 5) + 1; //# home tracks in [1,5]
        for (int i = 0; i < rand_hom_tracks; ++i) {
            d->addHomeTrack(abs(rand() % racingCalendar->getNumRaces())); //pick one of number of races
        }
    }

    //7. hire transportManager
    pr::Doc::summary("\n  ~Hire a transport manager~\n");
    transportManager = new Road;
    transportManager->addAMethod(new Ship);
    transportManager->addAMethod(new Fly);

}

/**
 * @status Theoretically this one's done as well
 * @author Jo
 */
void Logistics::preSeasonPreparation() {
    //pr::Doc::summary("\n>>Pre Season Planning\n------------------------\n");
    pr::Doc::summary("\n\n   _   _   _   _   _   _   _   _   _   _     _   _   _   _   _   _   _   _\n");
    pr::Doc::summary("  / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\\n");
    pr::Doc::summary(" ( P | r | e | - | S | e | a | s | o | n ) ( P | l | a | n | n | i | n | g )\n");
    pr::Doc::summary("  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/\n");
    pr::Doc::summary("\n");
    // 1. Get strategy

    int gotStrat = 0;
    if (interactiveDemo) {
        pr::Doc::summary("\nDo you want to help decide on a strategy? Y/N\n");
        std::cin >> interactionInput;
        if (interactionInput[0] == '*') {
            changeTransparency();
            interactionInput = interactionInput[1];
        }
        if (interactionInput == "Y" || interactionInput == "y") {
            pr::Doc::summary(
                    "\nWould you suggest a strategy with an Aggressive(A), Moderate(M) or Safe(S) level of risk?\n");
            std::cin >> interactionInput;
            if (interactionInput[0] == '*') {
                changeTransparency();
                interactionInput = interactionInput[1];
            }
            currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget);
            gotStrat = 1;
            //tyre order in the meantime
            switch (interactionInput[0]) {
                case 'a':
                case 'A':
                    currentTeamStrategy->SetRiskLevel(Aggressive);
                    break;
                case 'm':
                case 'M':
                    currentTeamStrategy->SetRiskLevel(Moderate);
                    break;
                case 's':
                case 'S':
                    currentTeamStrategy->SetRiskLevel(Safe);
                    break;
            }
            interactionInput = "";
        }

        if (gotStrat == 0) {
            pr::Doc::summary("  ~Consult professional strategists on best strategy for this racing season~\n");
            currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget);
            pr::Doc::detail(
                    "    The strategists have advised on a " + currentTeamStrategy->getStratName() + " stragegy.\n");
        }

        // 1.1 Notified about tyres (in the meanwhile)
        // 1.2 Receive Order
        pr::Doc::summary("  ~Tyre orders arrive a month later\n");
        //tyreSpecs->printStats(); //hierdie moet seker wel geimplimenteer word om op verskillende vlakke te print?

        //2. Pack containers
        pr::Doc::summary("  ~Pack containers with necessities needed for each race, according to allowed budget~\n");
        pr::Doc::detail("     Ordering the necessary tooleries and garage equipment thingamabobs\n");
        packContainers();

        //3. Train drivers
        pr::Doc::summary("  ~Send drivers that were hired to go train under supervision~\n");
        driverBootCamp();

        //4.Inform engDept of riskLevel
        pr::Doc::summary("\n  ~Inform the engineering team how daring the sponsors are.~\n");
        callEngDept()->setRiskLevel(currentTeamStrategy->getRiskLevel());

        //5. Build the cars if not already developed cars from previous season
        if (carsInSeasonIDs.empty()) {
            pr::Doc::summary("\n  ~It's the first season - cars are constructed from scratch.~\n");
            if (interactiveDemo) {
                pr::Doc::summary("\nDo you want to visit the factory to see how the cars are built? Y/N\n");
                std::cin >> interactionInput;
                if (interactionInput[0] == '*') {
                    changeTransparency();
                    interactionInput = interactionInput[1];
                }
                if (interactionInput == "Y" || interactionInput == "y") {
                    pr::Doc::transparency = 2;
                }
                interactionInput = "";
            }
            for (int i = 0; i < numPairs; ++i) {
                carsInSeasonIDs.push_back(callEngDept()->buildCar(budget));
            }
            pr::Doc::transparency = 0;
        } else {
            pr::Doc::summary(
                    "\nWe won't be using the wind tunnel this week, but you're welcome to observe the improve-Car-process? Y/N\n");
            std::cin >> interactionInput;
            if (interactionInput[0] == '*') {
                changeTransparency();
                interactionInput = interactionInput[1];
            }
            if (interactionInput == "Y" || interactionInput == "y") {
                pr::Doc::transparency = 2;
            }
            for (int id : carsInSeasonIDs) {
                pr::Doc::summary(
                        "  ~Build cars for the season using data and experience built up from previous season(s).~\n");
                callEngDept()->improveCar(id, false);
            }
            interactionInput = "";
            pr::Doc::transparency = 0;
        }
    }
}

/**
 * @status finito
 * @author Jo
 */
void Logistics::packContainers() {
    //european container
    europeanContainer = packSingleContainer();

    //non-european containers
    for (RaceIterator t = racingCalendar->begin(); !(t == racingCalendar->end()); ++t) {
        if (!t.currentItem()->isRaceEuropean()) {   //not european
            nonEuropeanContainers.push_back(packSingleContainer());
        }
    }
    pr::Doc::midInfo("     Packed all containers\n");

    if (interactiveDemo) {
        pr::Doc::summary("\nDo you want to inspect what is in a typical container? Y/N\n");

        std::cin >> interactionInput;
        if (interactionInput[0] == '*') {
            changeTransparency();
            interactionInput = interactionInput[1];
        }
        if (interactionInput == "Y" || interactionInput == "y") {
            pr::Doc::transparency = 2;
            getEuropeanContainer()->print();
        }
        pr::Doc::transparency = 0;
        interactionInput = "";
    }
}

/**
 * @author Marike
 * @status She be done
 * @return Packed Container
 */
Container *Logistics::packSingleContainer() const {
    Box *box = new Box();
    auto *garageEquip = new GarageEquipment(budget);
    auto *cateringEquip = new CateringEquipment(budget);

    box->addElement(garageEquip);
    box->addElement(cateringEquip);

    /*pr::Doc::summary("Packed a container\n");
    pr::Doc::detail("\n");
    box->print();
    pr::Doc::detail("\n");
*/
    return box;

}

void Logistics::simulateEvent(Race *r) {
    //0. Determine if a new strategy is necessary
    currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget);
    pr::Doc::summary("  ~Confirm strategy to be used for the race~\n");
    callEngDept()->setRiskLevel(currentTeamStrategy->getRiskLevel());

    //1. Transport car (from factory to race location)
    //1.1 Fill up clipboard
    pr::Doc::summary("  ~Transport cars for race from factory to track~\n");
    vector<eng::Car *> carClipboard;
    for (int id : carsInSeasonIDs) {
        eng::Car *temp = callEngDept()->checkCarOutOfFactory(id);
        transportManager->transport(nullptr, r, temp);
        carClipboard.push_back(temp);
    }

    //2. Transport Drivers
    //IDEA : add fly functionality for drivers
    // pr::Doc::summary("The two drivers are transported in a luxury mode of transport to " + r->getLocation() + "\n");

    //3. get correct container, transport and fly    //transport all the drivers and cars to where they should go
    pr::Doc::summary("  ~Make sure containers are where they are supposed to be~\n");
    transportManager->transport(r->prevRace(), r);
    if (r->isRaceEuropean()) {
        callRacingDept()->preRaceArrival(carClipboard, drivers, r, getEuropeanContainer(), tyreSpecs);
    } else {
        callRacingDept()->preRaceArrival(carClipboard, drivers, r, getNextNonEuropean(), tyreSpecs);
    }

    //4. racing weekend finishes and get points for each pair

    int *temp = callRacingDept()->Race();
    for (int i = 0; i < numPairs; ++i) {
        seasonPointTally[i] += temp[i];
    }

    //5. finish the packup
    Container *tCont = callRacingDept()->postRacePackUp();
    //5.1 Notified that drivers are ready to be picked and then flown accordingly


    //6. If season done - transport container back
    if (r->nextRace() == nullptr) {
        transportManager->transport(r, nullptr);
        if (r->isRaceEuropean()) {
            delete tCont;   //we need to get rid of it.
        }
    } else {
        transportManager->transport(r, r->nextRace());
    }
    if (!r->isRaceEuropean()) {
        //DONE : @jo check possible double-delete here
        delete tCont; //nonEuropeanContainer won't be used again
    } //else stay with the container

}

/**
 * @author Jo
 * @status I wash my hands off this one (Marike appreciates your humor ^_^)
 */
void Logistics::putRacesIntoCalender() {
    if (racingCalendar == nullptr) {
        racingCalendar = new RacesList;

        std::ifstream infileRace;
        infileRace.open("../src/log/races/raceData.txt");
        std::ifstream infileASCII;
        infileASCII.open("../src/log/races/asciiRace.txt");

        if (infileRace.is_open() && infileASCII.is_open()) {
            int numRaces;
            infileRace >> numRaces;

            std::string name;
            int complexity;
            bool inEurope;
            int laps;
            getline(infileRace, name); //to remove first random /n
            for (int i = 0; i < numRaces; ++i) {
                std::getline(infileRace, name);
                infileRace >> complexity;
                infileRace >> inEurope;
                infileRace >> laps;

                std::string* prettyOutput = new std::string[3];
                for (int j = 0; j < 3; ++j) {
                    std::string temp;
                    std::getline(infileASCII, temp);
                    prettyOutput[j] = temp;
                }


                Race *newRace = new Race(name, complexity, inEurope, laps, prettyOutput);
                racingCalendar->addRace(newRace);
                getline(infileRace, name); //to remove first random /n
            }
            infileRace.close();
        } else { //exception e
            std::cout << "There was a file-reading error !\n"; //die bly 'n cout aangesien dit 'n ernstige probleem is
            throw "Error";
        }
    }

    if (interactiveDemo) {
        pr::Doc::summary("\nDo you want to see a list of all the races? Y/N\n");
        std::cin >> interactionInput;
        if (interactionInput[0] == '*') {
            changeTransparency();
            interactionInput = interactionInput[1];
        }
        if (interactionInput == "Y" || interactionInput == "y") {
            pr::Doc::transparency = 2;
        } else {
            pr::Doc::transparency = 0;
        }
        racingCalendar->printList();
        interactionInput = "";
    }

}

void Logistics::raceSeason() {
    if (interactiveDemo) {
        pr::Doc::summary("\nPress any key for the season to start:\n");

        cin >> interactionInput;
        if (interactionInput[0] == '*') {
            changeTransparency();
            interactionInput = interactionInput[1];
        }
        interactionInput = "";
    }

    //And the season starts
    //pr::Doc::summary("\n>>Let the racing begin!\n-------------------------\n");
    pr::Doc::summary("\n   _   _   _     _   _   _     _   _   _   _   _   _     _   _   _   _   _     _\n");
    pr::Doc::summary("  / \\ / \\ / \\   / \\ / \\ / \\   / \\ / \\ / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\ / \\   / \\\n");
    pr::Doc::summary(" ( L | e | t ) ( t | h | e ) ( R | a | c | i | n | g ) ( B | e | g | i | n ) ( ! )\n");
    pr::Doc::summary("  \\_/ \\_/ \\_/   \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/   \\_/\n");
    pr::Doc::summary("\n");
    int developTracker = 0;
    for (RaceIterator t = racingCalendar->begin(); !(t == racingCalendar->end()); ++t) {
        if (!pr::Doc::outputOverride) {
            pr::Doc::summary("\n");
            t.currentItem()->printLoc();
            if (interactiveDemo) {
                pr::Doc::summary("\n Do you want to observe the details? Yes[Y], Some all of it[S], No[N]\n");
                pr::Doc::summary("Optionally, press [C] to run the entire season\n");
                std::cin >> interactionInput;
                if (interactionInput[0] == '*') {
                    changeTransparency();
                    interactionInput = interactionInput[1];
                }
                switch (interactionInput[0]) {
                    case 'y':
                    case 'Y':
                        pr::Doc::transparency = 2;
                        break;
                    case 'S':
                    case 's':
                        pr::Doc::transparency = 1;
                        break;
                    case 'N':
                    case 'n':
                        pr::Doc::transparency = 0;
                        break;
                    case 'c':
                    case 'C':
                        pr::Doc::outputOverride = true;
                        break;
                }
                interactionInput = "";
            }
        }

        simulateEvent(t.currentItem());
        developTracker++;
        if (developTracker == 7 || developTracker == 14) { //third of the way through
            pr::Doc::midInfo("Start work on a new prototype");
            carsInDevIDs.push_back(callEngDept()->buildCar(budget));
        }
    }
}

void Logistics::postSeasonDebrief() {
    pr::Doc::outputOverride = false;
    pr::Doc::transparency = 2;
    //pr::Doc::summary("\n>>The racing season is over for this year! Debrief.\n--------------------\n");
    pr::Doc::summary("\n   _   _   _     _   _   _   _   _   _     _   _     _   _   _   _     _\n");
    pr::Doc::summary("  / \\ / \\ / \\   / \\ / \\ / \\ / \\ / \\ / \\   / \\ / \\   / \\ / \\ / \\ / \\   / \\\n");
    pr::Doc::summary(" ( T | h | e ) ( S | e | a | s | o | n ) ( i | s ) ( D | o | n | e ) ( ! )\n");
    pr::Doc::summary("  \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/ \\_/   \\_/ \\_/   \\_/ \\_/ \\_/ \\_/   \\_/\n");
    pr::Doc::summary("\n");


    if (interactiveDemo) {
        pr::Doc::summary("Press any key to view the final results\n");
        cin >> interactionInput;
        if (interactionInput[0] == '*') {
            changeTransparency();
            interactionInput = interactionInput[1];
        }
        interactionInput = "";
    }


    //1. Get results
    int *tumTumTum = callRacingDept()->getFinalScore(); //structure: {points_d1, final_pos_d1, points_d2, final_pos_d2
    int zero = tumTumTum[0];
    int one = tumTumTum[1];
    int two = tumTumTum[2];
    int three = tumTumTum[3];
    //std::cout << zero << one << two << three << std::endl;

    //2. Flashy results
    // TODO: @marike Analysis of results based on leaderboard (maybe racing is doing that? I'll check with them during merging)


    if (interactiveDemo) {
        pr::Doc::summary("Press any key commence the final team debriefing\n");
        cin >> interactionInput;
        if (interactionInput[0] == '*') {
            changeTransparency();
            interactionInput = interactionInput[1];
        }
        interactionInput = "";
    }

    //3. Debriefing
    pr::Doc::summary("\n   _   _   _   _   _   _   _   _   _   _\n");
    pr::Doc::summary("  / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\\n");
    pr::Doc::summary(" ( D | e | b | r | i | e | f | i | n | g )\n");
    pr::Doc::summary("  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/\n");
    pr::Doc::summary("\n");

    //4. let transportManager take a holiday
    pr::Doc::summary("~ Transport Manager puts in leave. Sufering from overwork\n");
    delete transportManager;

    //5. Let driver take a holiday
    pr::Doc::summary("~ Driver go on holiday\n");
    int sumPositions = 0;
    for (int i = 0; i < numPairs; ++i) {
        ppl::Driver *d = drivers.back();
        drivers.pop_back();
        if (tumTumTum[2 * i + 1] >= 3) {
            pr::Doc::detail(d->getName() + " loses all his winning money while on a holiday in Vegas\n");
        } else {
            pr::Doc::detail(d->getName() + " is tactfully offered a retirement package\n");
        }
        sumPositions += tumTumTum[2 * i + 1];
        // IDEA : keep good drivers for next season
    }

    //6. Get some sponsors again.
    sponsoredBudget(sumPositions);

    //7. Break down old cars
    for (int id: carsInSeasonIDs) {
        eng::Car *c = callEngDept()->checkCarOutOfFactory(id);
        delete c;
    }
    carsInSeasonIDs.clear();

    //8. keep building new cars
    pr::Doc::summary("\nThroughout the season we've been working on cars.\n We now start work on additional cars\n");

    if (interactiveDemo) {
        pr::Doc::summary("\nDo you want to observe the process? Y/S/N\n");
        std::cin >> interactionInput;
        if (interactionInput[0] == '*') {
            changeTransparency();
            interactionInput = interactionInput[1];
        }
    }

    switch (interactionInput[0]) {
        case 'y':
        case 'Y':
            pr::Doc::transparency = 2;
            break;
        case 'S':
        case 's':
            pr::Doc::transparency = 1;
            break;
        case 'N':
        case 'n':
            pr::Doc::transparency = 0;
            break;
    }
    interactionInput = "";

    for (int i = 0; i < numPairs; ++i) {
        carsInDevIDs.push_back(callEngDept()->buildCar(budget));
    }
    for (int i : carsInDevIDs) {
        callEngDept()->improveCar(i, false);
        callEngDept()->improveCar(i, false);
    }

    //9. Choose cars for season (randomly)
    pr::Doc::midInfo("Choosing cars from the set of prototypes to be used in the next season\n");
    std::random_shuffle(carsInDevIDs.begin(), carsInDevIDs.end());
    while (carsInDevIDs.size() > numPairs) {
        int id = carsInSeasonIDs.back();
        eng::Car *c = callEngDept()->checkCarOutOfFactory(id);
        delete c;
        carsInDevIDs.pop_back();
    }
    for (int i: carsInDevIDs) {
        carsInSeasonIDs.push_back(i);
    }
    carsInDevIDs.clear();

    //TODO: @jo decide if in or not (waiting for Gianni)
    if (pr::Doc::transparency == 2) {
        for (int i: carsInSeasonIDs) {
            callEngDept()->checkCarOutOfFactory(i)->print();
        }
    }

    //10. clear out remaining containers
    europeanContainer = nullptr;
    nonEuropeanContainers.clear();


}



//===================== HELPER FUNCTIONS==================================

/**
 * @status done
 */
Container *Logistics::getEuropeanContainer() {
    return europeanContainer;
}

/**
 * @status fini
 * @return
 */
Container *Logistics::getNextNonEuropean() {
    Container *back = nonEuropeanContainers.back();
    nonEuropeanContainers.pop_back();
    return back;
}

/**
 * @author Jo
 * @return RacingDept Instance
 * @status definitely done
 */
rce::RacingDep *Logistics::callRacingDept() {
    return dynamic_cast<rce::RacingDep *>(departments['r']);
}

/**
 * @author Jo
 * @return EngTeam Instance
 * @status absolutely done
 */
eng::EngTeam *Logistics::callEngDept() {
    return dynamic_cast<eng::EngTeam *>(departments['e']);
}


//IDEA: Change to command?
void Logistics::driverBootCamp() {
    //todolist : Check runtime accuracy of regime

    if (interactiveDemo) {
        pr::Doc::summary("\nDo you want to observe the training regime? Y/N\n");
        std::cin >> interactionInput;
        if (interactionInput[0] == '*') {
            changeTransparency();
            interactionInput = interactionInput[1];
        }
        if (interactionInput == "Y" || interactionInput == "y") {
            pr::Doc::transparency = 2;
            interactionInput = "";
        }
    }

    switch (currentTeamStrategy->getRiskLevel()) {
        case Safe:
            for (ppl::Driver *d: drivers) {
                callRacingDept()->trainDriver(d, abs(rand() % 50 + 51), Hot, Difficult); //interval [50,100]
                callRacingDept()->trainDriver(d, abs(rand() % 50 + 51), Rainy, Extreme);
                callRacingDept()->trainDriver(d, abs(rand() % 50 + 51), Hot, Extreme);
                callRacingDept()->trainDriver(d, abs(rand() % 50 + 51), Rainy, Difficult);
            }
            //time higher, more weather conditions, higher track complexity, worse weather condtions
            break;
        case Moderate:
            for (ppl::Driver *d: drivers) {
                callRacingDept()->trainDriver(d, abs(rand() % 30 + 51), Normal, Difficult); //interval [30,80]
                callRacingDept()->trainDriver(d, abs(rand() % 30 + 51), Rainy, Average);
                callRacingDept()->trainDriver(d, abs(rand() % 30 + 51), Hot, Easy);
            }
            //medium time, range of weather conditions, middling track complexity
            break;
        case Aggressive:
            for (ppl::Driver *d: drivers) {
                callRacingDept()->trainDriver(d, abs(rand() % 100 + 1), randomWC(), randomTL()); //interval [1,100]
                callRacingDept()->trainDriver(d, abs(rand() % 100 + 1), randomWC(), randomTL());
                callRacingDept()->trainDriver(d, abs(rand() % 100 + 1), randomWC(), randomTL());
            }
            //any time,any weather, any track
            break;
    }
    pr::Doc::transparency = 0;
    interactionInput = "";
}

void Logistics::sponsoredBudget(int sumPositions) { //default is 0
    int willingToSponser = 0;
    if (interactiveDemo) {
        interactionInput = "";

        if (sumPositions == 0) {
            pr::Doc::summary("Are you willing to sponsor our team? Y/N\n");
            std::cin >> interactionInput;
        }
        if (interactionInput[0] == '*') {
            changeTransparency();
            interactionInput = interactionInput[1];
        }
        if (interactionInput == "Y" || interactionInput == "y") {
            pr::Doc::summary("\nHow much are you willing to sponsor us for? [0,100]\n");
            std::cin >> interactionInput;
            if (interactionInput[0] == '*') {
                changeTransparency();
                interactionInput = interactionInput[1];
            }
            budget = stoi(interactionInput);
            interactionInput = "";
            willingToSponser = 1;
        }
    }

        if (willingToSponser == 0) {
            pr::Doc::midInfo("\n  ~Approach sponsors to negotiate budget~\n");

            if (budget == -1) {  //default argument in constructor
                budget = abs(rand() % 100 + 1);
            } else {
                //todolist : check accuracy at runtime
                if (sumPositions >= 3) {
                    pr::Doc::detail("     Rolex is the team's next sponsor! Budget increases wildly\n");
                    budget = max((int) ((double) budget * 1.5), (100 - (int) ((double) budget * 0.5)));
                } else if (sumPositions <= 6) {
                    pr::Doc::detail("     Emirates is the team's next sponsor! Budget increases wildly\n");
                    budget = max((int) ((double) budget * 0.2), (80 - (int) ((double) budget * 0.2)));
                } else if (sumPositions <= 10) {
                    pr::Doc::detail("     The sponsor is satisfied with the performance");
                } else {
                    pr::Doc::detail("     This team performed horribly. Sponsor is dissatisfied. \nBudget decreases");
                    budget -= (int) ((double) budget * 0.1);
                }
                if (budget > 100) budget = 100;
                if (budget < 0) budget = 10;
            }
            pr::Doc::midInfo(
                    "     After much negotiation, team has been allocated a budget of " + to_string(budget) + ".\n");
        }
}



// =========================== MEDIATOR ===========================

void Logistics::sendCarToFactory(std::vector<eng::Car *> cars, Race *r, bool isBroken) {
    if (isBroken) {
        for (int i = 0; i < cars.size(); ++i) {
            pr::Doc::midInfo("Car " + to_string(cars[i]->getId()) + " is BROKEN! Fly to factory ASAP\n");
            transportManager->transport(r, nullptr, cars[0]);
            callEngDept()->carArrivesAtFactory(cars[0]);
            pr::Doc::midInfo("Car " + to_string(cars[i]->getId()) + " is broken, so fix it as soon as possible!\n");
            callEngDept()->fixCar(cars[0]->getId());
            callEngDept()->improveCar(cars[0]->getId(), true);
        }
    } else {
        for (int i = 0; i < cars.size(); ++i) {
            transportManager->transport(r, nullptr, cars[i]);
            callEngDept()->carArrivesAtFactory(cars[i]);
            int performance = cars[i]->getSpeed() + cars[i]->getHandling();
            // todolist : Check parameter at runtime ( & Improve strategy for using windTunnel)
            if (performance > 10) {
                callEngDept()->improveCar(cars[i]->getId(), false);
            } else {
                callEngDept()->improveCar(cars[i]->getId(), true);
            }
        }
    }
}

/**
 * @status Should be done (is done)
 * @param tyreOrder
 */
void Logistics::orderTyres(int *tyreOrder) {
    pr::Doc::summary("\n  ~Tyres ordered according to strategy chosen.~\n");
    pr::Doc::midInfo("     Ordering tyres as informed by Racing Department\n");
    pr::Doc::detail("        Tedious paperwork to complete tyre order\n");


    for (int i = 0; i < 3; ++i) {
        if (tyreOrder[i] != 0) {
            pr::Doc::detail("        Ordering " + to_string(tyreOrder[i]) + " pair(s) of ");
            switch (i) {
                case 0:
                    pr::Doc::detail("Soft Compound Tyres\n");
                    break;
                case 1:
                    pr::Doc::detail("Medium Compound Tyres\n");
                    break;
                case 2:
                    pr::Doc::detail("Hard Compound Tyres\n");
                    break;
            }
        }
    }

    //instantiate first set of tyres
    tyreSpecs.push_back(new rce::Tyres(tyreOrder));
    //from there on copy constructor <- could later be changed to prototype clone method if object becomes expensive
    for (int i = 1; i < numPairs; ++i) {
        tyreSpecs.push_back(new rce::Tyres(tyreSpecs.back()));
    }

}

void Logistics::moveDrivers(std::vector<ppl::Driver *> drivers) {
    pr::Doc::summary("Drivers picked up in a limousine and flown in a private jet");
    if (pr::Doc::transparency >= 1) {
        for (ppl::Driver *d : drivers) {
            pr::Doc::detail(d->getName() + " currently has " + to_string(d->getXp()) + "XP\n");
        }
    }

}

void Logistics::changeTransparency() {
    std::cout << "Enter the desired level of detail in output: \n0: Only Summaries\n1: More detailed information\n2:All possible detail\n ";
    std::string input;
    std::cin >> input;
    pr::Doc::transparency = stoi(input);

}





