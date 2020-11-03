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
}

void Leaderboard::setFinalScore(int * score)
{
	for(int i = 0;i < 20; i++)
	{
		finalScore[i] += score[i];
	}
	RaceCounter++;
}

int * Leaderboard::getFinalScore()
{
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
	std::cout << "Final Leaderboard"<< std::endl<<std::endl;
	for(int i = 0; i < 20; i ++)
	{
		for(int n = 0; n < 20; n++){
			if(largest <= finalScore[n] && array[n] != true)
			{
					largest = finalScore[n];
					largepos = n;
			}
		}
		std::cout << "#" << position << "	" << DriverName[largepos] << ":			"<< finalScore[largepos]<< std::endl;
		for(int m =0; m < 2; m++ )
		{
			if(OurDriver[m] == DriverName[largepos] )
			{
				finalresult[counter] = finalScore[largepos];
				//std::cout << "#" << finalresult[counter]<< std::endl;
				counter++;
				finalresult[counter] = position;
				//std::cout << "#" <<finalresult[counter]<< std::endl;
				counter++;
				
			}
		}
		
		array[largepos] = true;
		position++;
		largest = 0;
		}
		
	}
	return finalresult;
}
