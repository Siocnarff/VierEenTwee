#include "DriversLeaderboard.h"
#include <iostream>

using namespace rce;

/*void DriversLeaderboard::UpdateDriverLeaderBoard(String driverName, int Score) {
	// - implement DriversLeaderboard::UpdateDriverLeaderBoard
	throw "Not yet implemented";
}*/

DriversLeaderboard::DriversLeaderboard():Leaderboard()
{

}

int DriversLeaderboard::GetTeamScore(std::string TN)
{
	return -1;
}

void DriversLeaderboard::createLeaderboard(std::string DriverName1,std::string DriverName2)
{
	setdisplayLeaderboard(false);
	std::string Drivers[18]= {"Carlo Abate","George Abecassis","Kenny Acheson","Andrea de Adamich","Philippe Adams","Walt Ader","Kurt Adolff","Fred Agabashian","Christijan Albers","Michele Alboreto","Jean Alesi","Jaime Alguersuari","Philippe Alliot","Cliff Allison","Giovanna Amati","George Amick","Red Amick","Chris Amon"};
	for(int i =0; i< 18;i++)
	{
		driverName[i] = Drivers[i];
	}
	driverName[18] = DriverName1;
	driverName[19] = DriverName2;
	for(int i =0; i < 20;i++)
	{
		driverResult[i] = i;
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
	}
}

	
void DriversLeaderboard::display()
{
	int array[10];
	int largest = 0;
	int big = 101;
	int count = 0;
	int position =1;
	if(getdisplayLeaderboard()== true){
	std::cout << "Driver Leaderboard"<< std::endl<<std::endl;
	for(int j = 0; j < 20 ; j++){
		for(int i =0;i< 20;i++)
		{
			if(largest < driverResult[i] && driverResult[i] < big)
			{
				largest = driverResult[i];
			}
		
		}
		for(int i =0;i< 20;i++)
		{
			if(largest == driverResult[i])
			{
				array[count] =i; 
				count++;
			}
		}
		for(int i =0;i< count;i++)
		{
			std::cout << "#" << position << "	" << driverName[array[i]] << ":			"<< largest<< std::endl;
		}
		big = largest;
		largest = 0;
		count= 0;
		position++;
		}
	}
}
