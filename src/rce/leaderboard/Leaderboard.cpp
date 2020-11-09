#include "Leaderboard.h"
#include <iostream>
using namespace rce;
Leaderboard::Leaderboard()
{
    for(int i = 0;i < 20; i++)
    {
        finalScore[i] = 0;
    }
    RaceCounter = 0;
}

bool Leaderboard::getdisplayLeaderboard()
{
    return displayLeaderboards;
}
void Leaderboard::setdisplayLeaderboard(bool b)
{
    this->displayLeaderboards = b;
}

void Leaderboard::setDriver(std::string Driver1, std::string Driver2)
{
    std::string Drivers[20]= {"Carlo Abate","George Abecassis","Kenny Acheson","Andrea de Adamich","Philippe Adams","Walt Ader","Kurt Adolff","Fred Agabashian","Christijan Albers","Michele Alboreto","Jean Alesi","Jaime Alguersuari","Philippe Alliot","Cliff Allison","Giovanna Amati","George Amick","Red Amick","Chris Amon", "Neel degras", "Suan Pearson"};

    for(int i = 0 ; i < 20; i++)
    {
        DriverName[i] = Drivers[i];
    }
    DriverName[9] = Driver1;
    DriverName[19] = Driver2;
    OurDriver[0] = Driver1;
    OurDriver[1] = Driver2;
//    std::cout<<"@@@@@@@"<<" "<<OurDriver[0]<<" "<<OurDriver[1]<<std::endl;
}

void Leaderboard::setFinalScore(int * score)
{
    for(int i = 0;i < 20; i++)
    {
        finalScore[i] += score[i];
    }
//    for (int i = 0; i <20 ; ++i)
//    {
//        std::cout<<DriverName[i]<<" "<<finalScore[i]<<std::endl;
//    }
}

int * Leaderboard::getFinalScore() {
    bool array[20];
    int counter = 0;
    finalresult = new int[4];
    //pr::Doc::outputOverride=false;
    for(int i = 0; i < 20; i++)
    {
        array[i] = false;
    }
    int largepos = 0;
    int largest = 0;
    int position =1;

    if(getdisplayLeaderboard()== true){

        pr::Doc::summary("  ~Final Leaderboard\n\n");
        for(int i = 0; i < 20; i ++)
        {
            for(int n = 0; n < 20; n++){
                if(largest <= finalScore[n] && array[n] != true)
                {
                    largest = finalScore[n];
                    largepos = n;
                }
            }
            std::string output = "#";
            output.append(std::to_string(position));
            output.append(" ");
            output.append(DriverName[largepos]);
            output.append( ":			");
            output.append(std::to_string(finalScore[largepos]));
            output.append( "\n");
            pr::Doc::summary(output);
            output = "";
                if(largepos==9 || largepos==19)
                {
                    finalresult[counter] = finalScore[largepos];
                    counter++;
                    finalresult[counter] = position;
                    counter++;
                }
            array[largepos] = true;
            position++;
            largest = 0;
        }

    }
    return finalresult;
}

Leaderboard::~Leaderboard()
{
    delete finalresult;
}
