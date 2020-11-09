#include "TeamLeaderboard.h"
#include <iostream>
using namespace rce;
TeamLeaderboard::TeamLeaderboard():Leaderboard()
{

}

void TeamLeaderboard::createLeaderboard(std::string DriverName1,std::string DriverName2, int *score)
{
    setdisplayLeaderboard(false);
    std::string Team[10] = {"Alfa Romeo","AlphaTauri","Ferrari","Haasing","McLaren","Mercedes","Racing Point","Red Bull","Renault","Own Team"};
    std::string Drivers[18]= {"Carlo Abate","George Abecassis","Kenny Acheson","Andrea de Adamich","Philippe Adams","Walt Ader","Kurt Adolff","Fred Agabashian","Christijan Albers","Michele Alboreto","Jean Alesi","Jaime Alguersuari","Philippe Alliot","Cliff Allison","Giovanna Amati","George Amick","Red Amick","Chris Amon"};
    for(int i =0; i< 10;i++)
    {
        TeamName[0][i] = Team[i];
    }
    for(int i =0; i < 9;i++)
    {
        TeamName[1][i] = Drivers[i];
    }
    for(int i =0; i < 9;i++)
    {
        TeamName[2][i] = Drivers[i+9];
    }
    TeamName[1][9] = DriverName1;
    TeamName[2][9] = DriverName2;

    for(int i =0; i < 10;i++)
    {
        teamresult[1][i] = score[i];
    }
    for(int i =0; i < 10;i++)
    {
        teamresult[2][i] = score[i+10];
    }
    for(int i =0; i< 10;i++)
    {
        teamresult[0][i] = teamresult[1][i] +teamresult[2][i];
    }
    /*for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            std::cout << TeamName[i][j] <<"    "<<teamresult[i][j] << std::endl;
        }
    }*/
}
void TeamLeaderboard::UpdateLeaderBoard(std::string TN,std::string DriverName, int Score) {
    int i;
    for( i =0; i< 10;i++)
    {
        if(TeamName[0][i] == TN)
        {
            //std::cout <<"  found team  "<<std::endl;
            if(TeamName[1][i] == DriverName)
            {
                //std::cout <<"  found driver  "<<std::endl;
                teamresult[1][i] = Score;
                teamresult[0][i] = teamresult[1][i] + teamresult[2][i];
            }
            else
            {
                if(TeamName[2][i] == DriverName)
                {
                    //std::cout <<"  found driver  "<<std::endl;
                    teamresult[2][i] = Score;
                    teamresult[0][i] = teamresult[1][i] + teamresult[2][i];
                }
            }
            return;
        }
    }

}

int TeamLeaderboard::GetTeamScore(std::string TN)
{
    int i;
    for( i = 0; i < 10; i++)
    {
        if(TeamName[0][i]==TN)
        {
            return teamresult[0][i];
        }
    }
    return -1;
}


void TeamLeaderboard::display()
{
    pr::Doc::outputOverride=false;
//    int resultarray[20];
//    std::string interactionInput = "";
//    pr::Doc::summary("Do you want to see the race's Team leaderboard? Y/N"); //in julle gecal iets anders
//    std::cin >> interactionInput;
//    if (interactionInput == "Y" || interactionInput == "y") {
//        pr::Doc::transparency = 2; //of watookal julle wil.
//        interactionInput = "";
//    }
//    else
//    {
//        pr::Doc::transparency = 0;
//        interactionInput = "";
//    }
    bool array[10];
    for(int i = 0; i < 10; i++)
    {
        array[i] = false;
    }
    int largepos = 0;
    int largest = 0;
    int position =1;
    if(getdisplayLeaderboard()== true){
        pr::Doc::midInfo("Team Leaderboard\n\n");
        for(int i = 0; i < 10; i ++)
        {
            for(int n = 0; n < 10; n++){
                if(largest <= teamresult[0][n] && array[n] != true)
                {
                    largest = teamresult[0][n];
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
            //std::cout << "largest: " << largest<< std::endl;
//		std::cout << "#" << position << "	" << TeamName[0][largepos] << ":			"<< teamresult[0][largepos]<< std::endl;
            std::string output = "#";
            output.append(std::to_string(position));
            output.append(" ");
            output.append(TeamName[0][largepos]);
            output.append( ":			");
            output.append(std::to_string(teamresult[0][largepos]));
            output.append( "\n");
            pr::Doc::midInfo(output);
            output = "";
            //pr::Doc::detail("#");
            //pr::Doc::detail(std::to_string(position));
            //pr::Doc::detail(" ");
            //pr::Doc::detail(TeamName[0][largepos]);
            //pr::Doc::detail( ":			");
            //pr::Doc::detail(std::to_string(teamresult[0][largepos]));
            //pr::Doc::detail( "\n");
            array[largepos] = true;
            position++;
            largest = 0;
        }

    }


}

TeamLeaderboard::~TeamLeaderboard()
{

}