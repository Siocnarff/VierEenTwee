#include "TeamLeaderboard.h"
#include <iostream>
TeamLeaderboard::TeamLeaderboard():Leaderboard()
{

}

void TeamLeaderboard::createLeaderboard(std::string DriverName1,std::string DriverName2)
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
	for(int i = 0; i< 3;i++)
	{
		for(int j = 0; j < 10; j++)
		{
			teamresult[i][j] = j;
		}
	}
}
void TeamLeaderboard::UpdateLeaderBoard(std::string TN,std::string DriverName, int Score) {
	int i;
	for( i =0; i< 15;i++)
	{
		if(TeamName[0][i] == TN)
		{
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
	int array[10];
	int largest = 0;
	int big = 200;
	int count = 0;
	int position =1;
	if(getdisplayLeaderboard()== true){
	std::cout << "Team Leaderboard"<< std::endl<<std::endl;
	for(int j = 0; j < 10 ; j++){
		for(int i =0;i< 10;i++)
		{
			if(largest < teamresult[0][i] && teamresult[0][i] < big)
			{
				largest = teamresult[0][i];
			}
		
		}
		for(int i =0;i< 15;i++)
		{
			if(largest == teamresult[0][i])
			{
				array[count] =i; 
				count++;
			}
		}
		for(int i =0;i< count;i++)
		{
			std::cout << "#" << position << "	" << TeamName[0][array[i]] << ":			"<< largest<< std::endl;
		}
		big = largest;
		largest = 0;
		count= 0;
		position++;
		}
	}
}
