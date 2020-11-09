//
// Created by josuabotha on 2020/10/28.
//

#include <thread>
#include "pr/Doc.h"
#include "log/Logistics.h"
#include "eng/EngTeam.h"
#include "rce/RacingDep.h"


int pr::Doc::transparency = 0;
bool pr::Doc::outputOverride = false;

void demoVersion1();
void seasonRun(lg::Logistics*);
void plainSeasonRun();

int main() {

   demoVersion1();  //First draft of interactive demo
//    plainSeasonRun();

}


void plainSeasonRun() {
    auto* racingDept = new rce::RacingDep();
    auto* engDept = new eng::EngTeam;
    auto* logDept = new lg::Logistics;

    logDept->registerNotifier(racingDept);
    logDept->registerNotifier(engDept);

    logDept->interactiveDemo = false;
    seasonRun(logDept);

    delete racingDept;
    delete engDept;
    delete logDept;

}

void demoVersion1(){
    auto* racingDept = new rce::RacingDep();
    auto* engDept = new eng::EngTeam;
    auto* logDept = new lg::Logistics;

    srand(time(0));

    logDept->registerNotifier(racingDept);
    logDept->registerNotifier(engDept);

    pr::Doc::summary("\nBEFORE WE BEGIN, PLEASE NOTE \n");
    pr::Doc::summary("This interactive demo makes use of differing levels of detailed output. \n");
    pr::Doc::summary("Whenever prompted to provide an input, the user may preface their input \n");
    pr::Doc::summary("with a * to indicate the desire to change levels of transparency (ie. *Y, *s)\n");

//    std::this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(5));

    pr::Doc::summary("\nPlease do so now by choosing a desired level of transparency: \n");
    pr::Doc::summary("0: Only Summaries\n1: More detailed information\n2:All possible detail\n ");
    std::string input;
    std::cin >> input;
    pr::Doc::transparency = stoi(input);

    logDept->interactiveDemo = true;

    std::string continueSeasons = "y";
    while (continueSeasons=="y" || continueSeasons == "Y") {
        seasonRun(logDept);
        std::cout << "\nDo you want run another season? Y/N \n";
        std::cin >> continueSeasons;
    }
    std::cout << "That's all folks!" << std::endl;

    delete racingDept;
    delete engDept;
    delete logDept;

}

void seasonRun(lg::Logistics* a) {

    pr::Doc::summary("\t   _   _   _   _     _   _   _   _   _   _\n");
    pr::Doc::summary("\t  / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\ / \\ / \\\n");
    pr::Doc::summary("\t ( R | a | c | e ) ( S | e | a | s | o | n )\n");
    pr::Doc::summary("\t  \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \\_/ \\_/\n");
    pr::Doc::summary("\n");

//    std::this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(2));

    pr::Doc::summary("       ____           ___________\n");
    pr::Doc::summary("    .   |````>..-- ``             |_..--.._______\n");
    pr::Doc::summary("   :.'. \\_ /```\\. . . . . .      - -     ``````````/```\\- - ...\n");
    pr::Doc::summary(" :;';>._   \\.../--__________________. . . . . ...~ \\.../--  ~ ~ /\n");

//    std::this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(2));

    a->doYearPlanning();
    a->preSeasonPreparation();
    a->raceSeason();
    a->postSeasonDebrief();

}
