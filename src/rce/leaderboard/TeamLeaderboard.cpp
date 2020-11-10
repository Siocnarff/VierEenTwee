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


void TeamLeaderboard::display() {
     bool array[10];
    for(int i = 0; i < 10; i++)
    {
        array[i] = false;
    }
    int largepos = 0;
    int largest = 0;
    int position =1;
    if(getdisplayLeaderboard()== true){
        pr::Doc::midInfo("\n\tTeam Leaderboard\n");
        for(int i = 0; i < 10; i ++)
        {
            for(int n = 0; n < 10; n++){
                if(largest <= teamresult[0][n] && array[n] != true)
                {
                    largest = teamresult[0][n];
                    largepos = n;
                }
            }
            std::string output = "#";
            output.append(std::to_string(position));
            output.append(" ");
            output.append(TeamName[0][largepos]);
            output.append( ":			");
            output.append(std::to_string(teamresult[0][largepos]));
            output.append( "\n");
            pr::Doc::midInfo(output);
            output = "";
              array[largepos] = true;
            position++;
            largest = 0;
        }

    }


}

TeamLeaderboard::~TeamLeaderboard()
{

}