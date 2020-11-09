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
    std::cout<<"@@@@@@@"<<" "<<OurDriver[0]<<" "<<OurDriver[1]<<std::endl;
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

int * Leaderboard::getFinalScore()
{
//    int resultarray[20];
    std::string interactionInput = "";
    pr::Doc::outputOverride=false;
    pr::Doc::summary("Do you want to see all drivers final leaderboard? Y/N\n"); //in julle gecal iets anders
    std::cin >> interactionInput;
    if (interactionInput == "Y" || interactionInput == "y") {
        pr::Doc::transparency = 2; //of watookal julle wil.
        interactionInput = "";
    }
    else
    {
        pr::Doc::transparency = 0;
        interactionInput = "";
    }
    bool array[20];
    int counter = 0;
    int * finalresult = new int[4];
    for(int i = 0; i < 20; i++)
    {
        array[i] = false;
    }
    int largepos = 0;
    int largest = 0;
    int position =1;
    if(getdisplayLeaderboard()== true){

        pr::Doc::midInfo("Final Leaderboard\n\n");
        for(int i = 0; i < 20; i ++)
        {
            for(int n = 0; n < 20; n++){
                if(largest <= finalScore[n] && array[n] != true)
                {
                    largest = finalScore[n];
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
//		std::cout << "#" << position << "	" << DriverName[largepos] << ":			"<< finalScore[largepos]<< std::endl;
            //pr::Doc::detail("#");
            //pr::Doc::detail(std::to_string(position));
            //pr::Doc::detail(" ");
            //pr::Doc::detail(DriverName[largepos]);
            //pr::Doc::detail( ":			");
            //pr::Doc::detail(std::to_string(finalScore[largepos]));
            //pr::Doc::detail( "\n");
            std::string output = "#";
            output.append(std::to_string(position));
            output.append(" ");
            output.append(DriverName[largepos]);
            output.append( ":			");
            output.append(std::to_string(finalScore[largepos]));
            output.append( "\n");
            pr::Doc::midInfo(output);
            output = "";
//            for(int m =0; m < 2; m++ )
//            {
                if(largepos==9 || largepos==19)
                {
                    finalresult[counter] = finalScore[largepos];
//                    std::cout << "#" << finalresult[counter]<< std::endl;
                    counter++;
                    finalresult[counter] = position;
//                    std::cout << "#" <<finalresult[counter]<< std::endl;
                    counter++;
                }
//                if(OurDriver[m] == DriverName[largepos] )
//                {
//                    finalresult[counter] = finalScore[largepos];
//                    std::cout << "#" << finalresult[counter]<< std::endl;
//                    counter++;
//                    finalresult[counter] = position;
//                    std::cout << "#" <<finalresult[counter]<< std::endl;
//                    counter++;
//
//                }
//            }

            array[largepos] = true;
            position++;
            largest = 0;
        }

    }
    return finalresult;
}
