#include "DriversLeaderboard.h"
#include <iostream>

using namespace rce;
DriversLeaderboard::DriversLeaderboard():Leaderboard()
{

}

int DriversLeaderboard::GetTeamScore(std::string TN)
{
    return -1;
}

void DriversLeaderboard::createLeaderboard(std::string DriverName1,std::string DriverName2 , int *score )
{
    setdisplayLeaderboard(false);
    std::string Drivers[20]= {"Carlo Abate","George Abecassis","Kenny Acheson","Andrea de Adamich","Philippe Adams","Walt Ader","Kurt Adolff","Fred Agabashian","Christijan Albers","Michele Alboreto","Jean Alesi","Jaime Alguersuari","Philippe Alliot","Cliff Allison","Giovanna Amati","George Amick","Red Amick","Chris Amon", "Neel degras", "Suan Pearson"};
    for(int i =0; i< 20;i++)
    {
        driverName[i] = Drivers[i];
    }
    driverName[9] = DriverName1;
    driverName[19] = DriverName2;
    for(int i =0; i < 20;i++)
    {
        driverResult[i] = score[i];

    }




}
void DriversLeaderboard::UpdateLeaderBoard(std::string TN,std::string DriverName, int Score) {
    int i;
    for(i=0; i< 20;i++)
    {
        if(driverName[i] ==DriverName)
        {
            driverResult[i] = Score;
        }
        //std::cout << "============================================================" 	<< std::endl;
    }
}


void DriversLeaderboard::display()
{
//    int resultarray[20];
    bool array[20];
    for(int i = 0; i < 20; i++)
    {
        array[i] = false;
    }
    int largepos = 0;
    int largest = 0;
    int position =1;
    if(getdisplayLeaderboard()== true){
        //std::cout << "Driver Leaderboard"<< std::endl<<std::endl;
        pr::Doc::midInfo("\n\tDriver Leaderboard\n");
        for(int i = 0; i < 20; i ++)
        {
            for(int n = 0; n < 20; n++){
                if(largest <= driverResult[n] && array[n] != true)
                {
                    largest = driverResult[n];
                    largepos = n;
                }
            }
            std::string output = "#";
            output.append(std::to_string(position));
            output.append(" ");
            output.append(driverName[largepos]);
            output.append( ":			");
            output.append(std::to_string(driverResult[largepos]));
            output.append( "\n");
            pr::Doc::detail(output);
            output = "";

            array[largepos] = true;
            position++;
            largest = 0;
        }

    }
}

DriversLeaderboard::~DriversLeaderboard()
{

}
