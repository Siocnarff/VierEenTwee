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
//            switch(position)
//            {
//                case 1:
//                {
//                    resultarray[largepos] = 25;
//                    break;
//                }
//                case 2:
//                {
//                    resultarray[largepos] = 18;
//                    break;
//                }
//                case 3:
//                {
//                    resultarray[largepos] = 15;
//                    break;
//                }
//                case 4:
//                {
//                    resultarray[largepos] = 12;
//                    break;
//                }
//                case 5:
//                {
//                    resultarray[largepos] = 10;
//                    break;
//                }
//                case 6:
//                {
//                    resultarray[largepos] = 8;
//                    break;
//                }
//                case 7:
//                {
//                    resultarray[largepos] = 6;
//                    break;
//                }
//                case 8:
//                {
//                    resultarray[largepos] = 4;
//                    break;
//                }
//                case 9:
//                {
//                    resultarray[largepos] = 2;
//                    break;
//                }
//                case 10:
//                {
//                    resultarray[largepos] = 1;
//                    break;
//                }
//                default:
//                {
//                    resultarray[largepos] = 0;
//                    break;
//                }
//            }

//            Message #racing-strategy-simulation
//		std::cout << "#" << position << "	" << ydriverName[largepos] << ":			"<< driverResult[largepos]<< std::endl;
            //pr::Doc::detail("#");
            //pr::Doc::detail(std::to_string(position));
            //pr::Doc::detail(" ");
            //pr::Doc::detail(driverName[largepos]);
            //pr::Doc::detail( ":			");
            //pr::Doc::detail(std::to_string(driverResult[largepos]));
            //pr::Doc::detail( "\n");
            std::string output = "#";
            output.append(std::to_string(position));
            output.append(" ");
            output.append(driverName[largepos]);
            output.append( ":			");
            output.append(std::to_string(driverResult[largepos]));
            output.append( "\n");
            pr::Doc::midInfo(output);
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
