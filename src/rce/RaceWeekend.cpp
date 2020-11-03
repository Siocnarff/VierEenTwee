#include "RaceWeekend.h"
//#include "RiskLevel.h"
#include <iostream>
using namespace rce;
int * RaceWeekend::RacingWeekend() {
	int resultarray[20];
	TC = raceConditions->getTrackComplexity();
	for(int i = 0; i < 3; i++)
	{
		lg::RiskLevel rl = getRiskLevel();
		/*if(i >0)
		{
			int total =getScore(0) + getScore(1);
			if(total < 120 && total >= 80)
			{
				if(rl == log::Moderate)
				{
					rl = log::Aggressive;
					//notify
				}
				else
				{
					if(rl == log::Safe)
					{
						rl = log::Moderate;
					}
				}
			}
			else
			{
				if(total < 80)
				{
					if(rl == log::Moderate)
					{
						rl = log::Aggressive;
						//notify
					}
					else
					{
						if(rl == log::Safe)
						{
							rl = log::Aggressive;
							//Notify
						}
					}
				}
				else
				{
					if(total > 150)
				{
					if(rl == log::Moderate)
					{
						rl = log::Safe;
						//notify
					}
					else
					{
						if(rl == log::Aggressive)
						{
							rl = log::Moderate;
							//Notify
						}
					}
				}
				}
			}
		}*/
		std::cout <<std:: endl<<"Race #"<<i+1<< " is starting."<<std:: endl<<std:: endl;
		setDayWeather();
		for(int n = 0; n < 2; n++)
		{
			time[n] = 100;
			if(getState(n)!= "Broken" && tyresleft[n])
			{
			
			score[n] = 0;
			speed = car[n]->getSpeed();
			hometrack = driver[n]->isHomeTrack(trackID);
			xp = driver[n]->getXp();
			if(speed >= 90)
			{
				time[n] -= 33;
				std::cout <<"Car "<< n << " is fast and made up 33 units of time. "<< std:: endl;
			}
			else
			{
				if(speed>= 60 && speed <90)
				{
					time[n] -= 22;
					std::cout <<"Car "<< n << " is fast and made up 22 units of time. "<< std:: endl;
				}
				else
				{
					if(speed >=30 && speed <60)
					{
						time[n] -= 11;
						std::cout <<"Car "<< n << " is slow but made up 11 units of time. "<< std:: endl;
					}
					else
					{
						if(speed <30)
						{
							time[n] -= 5;
							std::cout <<"Car "<< n << " is slow but made up 5 units of time. "<< std:: endl;
						}
					}
				}
			}//end of speed if
			if(handling[n] >= 90)
			{
				time[n] -= 33;
				std::cout <<"Car "<< n << " handles great and made up 33 units of time. "<< std:: endl;
			}
			else
			{
				if(handling[n]>= 60 && handling[n] <90)
				{
					time[n] -= 22;
					std::cout <<"Car "<< n << " handles good and made up 22 units of time. "<< std:: endl;
				}
				else
				{
					if(handling[n] >=30 && handling[n] <60)
					{
						time[n] -= 11;
						std::cout <<"Car "<< n << " handles bad but made up 11 units of time. "<< std:: endl;
					}
					else
					{
						if(handling[n] <30)
						{
							time[n] -= 5;
							std::cout <<"Car "<< n << " handles bad but made up 5 units of time. "<< std:: endl;
						}
					}
				}
			}//end of handling if
			//srand(time(NULL));
			if(hometrack == true)
			{
				int t = rand()%15+1;
				time[n] -= t;
				std::cout <<"This is "<< driver[n]->getName() << "'s home track thus could make up "<<t << " units of time through prior knowledge."<< std:: endl;
			}
			if(xp >= 90)
			{
				time[n] -= 40;
				std::cout << driver[n]->getName() << " has a lot of experience and could make up 40 units of time."<< std:: endl;
			}
			else
			{
				if(xp>= 60 && xp <90)
				{
					time[n] -= 30;
					std::cout << driver[n]->getName() << " has a good amount of experience and could make up 30 units of time."<< std:: endl;
				}
				else
				{
					if(xp >=30 && xp <60)
					{
						time[n] -= 20;
						std::cout << driver[n]->getName() << " has some experience and could make up 20 units of time."<< std:: endl;
					}
					else
					{
						if(xp <30)
						{
							time[n] -= 10;
							std::cout << driver[n]->getName() << " has little experience and could make up 10 units of time."<< std:: endl;
						}
					}
				}
			}//end of xp if
			if(TC ==    lg::Easy)
			{
				time[n] -= 30;
				std::cout << "The track was easy and " <<driver[n]->getName()<<" has gained 30 unites of time."<< std:: endl;
			}
			else
			{
				if(TC==lg::Average)
				{
					time[n] -= 20;
					std::cout << "The track was good and " <<driver[n]->getName()<<" has gained 15 unites of time."<< std:: endl;
				}
				else
				{
					if( TC == lg::Difficult)
					{
						time[n] += 5;
						std::cout << "The track was difficult and " <<driver[n]->getName()<<" has lost 5 unites of time."<< std:: endl;
					}
					else
					{
						if(TC== lg::Extreme)
						{
							time[n] += 15;
							std::cout << "The track was extremely difficult and " <<driver[n]->getName()<<" has lost 15 unites of time."<< std:: endl;
						}
					}
				}
			}
			int dam;
			int randval;
			int Damagetotyres;
			if(rl == lg::Aggressive)
			{
				randval = rand() %10 +1;
				if(randval >= 7)
				{
					time[n] -= 40;
					dam = rand() %60 +5;
					std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to being aggressive, but has gained 40 units of time. "<< std:: endl;
					Damagetotyres =60;
				}
				else
				{
					if(randval >= 4 && randval <7 )
					{
						time[n] -= 40;
						dam = rand() %40 + 5;
						std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to being aggressive, but has gained 40 units of time. "<< std:: endl;
						Damagetotyres = 40;
					}
					else
					{
						if(randval < 4)
						{
							time[n] -= 40;						
							dam = rand()%20+0;
							std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to being aggressive,but has gained 40 units of time. "<< std:: endl;
							Damagetotyres =20;
						}
					}
				}
			}
				if(rl == lg::Moderate)
				{
				randval = rand() %10 +1;
				if(randval >= 8)
				{
					time[n] -= 20;	
					dam = rand() %40 +0;
					std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving at a moderate risk level, but has gained 20 units od time."<< std:: endl;
					Damagetotyres = 40;
				}
				else
				{
					if(randval >= 4 && randval <8)
					{
						time[n] -= 20;	
						dam = rand() %30 + 10;
						std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving at a moderate risk level,but has gained 20 units od time."<< std:: endl;
						Damagetotyres = 20;
					}
					else
					{
						if(randval < 4)
						{
							time[n] -= 20;							
							Damagetotyres =20;
							dam = rand()%10+0;
							std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving at a moderate risk levelbut has gained 20 units od time."<< std:: endl;
						}
					}
				}
				}
				if(rl == lg::Safe)
				{
				randval = rand() %10 +1;
				if(randval >= 8)
				{
					time[n] -= 10;	
					dam = rand() %15+0;
					std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving Safely and gained 10 units of time."<< std:: endl;
					Damagetotyres =20;
				}
				else
				{
					if(randval >= 4 && randval <8)
					{
						time[n] -= 10;	
						dam = rand() %10 + 0;
						std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving Safely and gained 10 units of time."<< std:: endl;
						Damagetotyres =20;
					}
					else
					{
						if(randval < 4)
						{
							time[n] -= 10;	
							dam = rand()%5+0;
							std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving Safely and gained 10 units of time."<< std:: endl;
							Damagetotyres = 0;
						}
					}
				}
			}
			deel_Damage(n,dam);
			
			if(DayWeather == lg::Normal)
			{
				int t = rand()%10+1 ;
				time[n] += t ;
				std::cout << driver[n]->getName() << "has lost "<<t << " units of time due to normal weather."<< std:: endl;
				Damagetotyres += 5;
			}
			else
			{
				if(DayWeather == lg::Hot)
			{
				int t = rand()%5+0 ;
				time[n] += t ;
				std::cout << driver[n]->getName() << " has lost "<<t << " units of time due to hot weather."<< std:: endl;
				Damagetotyres += 10;
			}
			else
			{
				if(DayWeather == lg::Rainy)
				{
					int t = rand()%15+1 ;
					time[n] += t;
					std::cout << driver[n]->getName() << " has lost "<<t << " units of time due to rainy weather."<< std:: endl;
					Damagetotyres += 15;
				}
			}
			}
			
			bool tyresleft;
			//reduce damage by tyre compound
			while(Damagetotyres>= 20)
			{
				Damagetotyres -= 20;
				if(tyresleft[n]){
				for(int m = 0; m <20; m++)
				{
					tyre->reduceThread();
				}
				tyresleft[n]= pitstop[n]->stop(Car[n], tyre);
			}
			}

			for(int m = 0; m <20; m++)
			{
					tyre->reduceThread();
			}
			
			}
			std::cout <<"Car "<< n << " has to take "<<Damagetotyres<<" pitstops through the race."<< std:: endl;
			if(getState(n) == "Broken")
			{
				getCarnotify(n);
				std::cout <<"Car "<< n << " has taken too much damage during and is broken. The race has ended for Car "<< n <<"."<< std:: endl;
				time[n] = 100;
			}
			else
			{
				if(getState(n) == "Damaged" && getDamage(n) >=80 )
				{
					int t = rand()%5+0;
					time[n] +=  t;
					std::cout <<"Car "<< n << " has taken damage and lost "<<t<<" units of time."<< std:: endl;
				}
				else
				{
					if(getState(n) == "Damaged" && getDamage(n) >=40 && getDamage(n) < 80)
					{
						int t = rand()%8+0;
						time[n] +=  t;
						std::cout <<"Car "<< n << " has taken damage and lost "<<t<<" units of time."<< std:: endl;
					}
					else
					{
						if(getState(n) == "Damaged" && getDamage(n) >=11 && getDamage(n) < 40)
						{
							int t = rand()%15+0;
							time[n] +=  t;
							std::cout <<"Car "<< n << " has taken a lot of damage and lost "<<t<<" units of time."<< std:: endl;
						}
					}
				}
			}//end if for broken car
			//still need to reduce amount of tires based on tire compound
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			if(!tyresleft[n])
			{
				time[n] = 100;
				getCarnotify[n];
			}
		}	
			if(time[n] < 0)
			{
				time[n] =0;
			}
			else
			{
				if(time[n] >100)
				{
					time[n] = 100;
				}
			}
		setScore(100 - time[n], n) ;
		
	}
	std::cout <<std:: endl<<"Race #"<<i+1<< " has ended."<<std:: endl<<std:: endl;
	
	int array[20];
	for(int k = 0; k< 20 ; k++)
	{
		array[k] = rand()%100+0; 
	}
	array[9] = getScore(0);
	array[19] = getScore(1);
	bool b[20];
	for(int i = 0; i < 20; i++)
	{
		b[i] = false;
	}
	int largepos = 0;
	int largest = 0;
	int position =1;
	for(int i = 0; i < 20; i ++)
	{
		for(int n = 0; n < 20; n++){
			if(largest <= array[n] && b[n] != true)
			{
					largest = array[n];
					largepos = n;
			}
		}
			if(position == 1)
				{
					resultarray[largepos] = 25;
				}
				if(position == 2)
				{
					resultarray[largepos] = 18;
				}
				if(position == 3)
				{
					resultarray[largepos] = 15;
				}
				if(position == 4)
				{
					resultarray[largepos] = 12;
				}
				if(position == 5)
				{
					resultarray[largepos] = 10;
				}
				if(position == 6)
				{
					resultarray[largepos] = 8;
				}
				if(position == 7)
				{
					resultarray[largepos] = 6;
				}
				if(position == 8)
				{
					resultarray[largepos] = 4;
				}
				if(position == 9)
				{
					resultarray[largepos] = 2;
				}
				if(position == 10)
				{
					resultarray[largepos] = 1;
				}
				if(position > 10)
				{
					resultarray[largepos] = 0;
				}
		b[largepos] = true;
		position++;
		largest = 0;
	}
		
	for(int j = 0; j < 2; j++)
	{
		lead[j]->createLeaderboard(driver[0]->getName(), driver[1]->getName(), resultarray);
		lead[j]->setdisplayLeaderboard(true);
		lead[j]->display();
		
	}
	
}
	lead[0]->setDriver(driver[0]->getName(), driver[1]->getName());
	lead[0]->setFinalScore(resultarray);
	int * ret = new int[2];
	ret[0] =  resultarray[9];
	ret[1] = resultarray[19];
	
		
	return ret;
}

eng::Car* RaceWeekend::getCar(int i) {
	return this->car[i];
}

void RaceWeekend::setCar(eng::Car* car, int i) {
	this->car[i] = car;
}

ppl::Driver* RaceWeekend::getDriver(int i) {
	return this->driver[i];
}

void RaceWeekend::setDriver(ppl::Driver* driver,int i) {
	this->driver[i] = driver;
}

list<ppl::Pitcrew*> RaceWeekend::getPitcrew() {
	return this->pitcrew;
}

void RaceWeekend::setPitcrew(list<ppl::Pitcrew*> pitcrew) {
	this->pitcrew = pitcrew;
}

void RaceWeekend::getCarnotify(int i)
{
	notify(car[i]);
}

int RaceWeekend::getTime(int i) {
	return this->time[i];
}

void RaceWeekend::setTime(int time, int i) {
	this->time[i] = time;
}

int RaceWeekend::getScore(int i) {
	return this->score[i];
}

void RaceWeekend::setScore(int score, int i) {
	this->score[i] = score;
}

RaceWeekend::RaceWeekend(eng::Car** cars, ppl::Driver** drivers, lg::Race* r, CreateStategy* s, list<ppl::Pitcrew*> p, Tyres * t, Leaderboard ** l) {
	car = new eng::Car*[2];
	driver = new ppl::Driver*[2];
	lead = new Leaderboard*[2];
	pitstop = new Pitstop*[2];
	pitcrew = p;
	tyre = t;
	strategy =s;
	CState = new CarState*[2];
	for(int i =0; i < 2; i++)
	{
		car[i] = cars[i];
		tyresleft[i] = true;
		pitstop[i] = new Pitstop();
		pitstop[i]->addCrew(pitcrew);
		pitstop[i]->tyres(tyre);
		pitstop[i]->setCar(car[i]);
		driver[i] = drivers[i];
		handling[i] = car[i]->getHandling();	
		lead[i] = l[i];
		CState[i] = new CarStateFullHP();
		Damage[i] = 0;
		
	}
	this->raceConditions =r;
	
	trackID = 1;
	
}

lg::WeatherConditions RaceWeekend::getDayWeather() {
	return this->DayWeather;
}

void RaceWeekend::setDayWeather() {
	DayWeather = raceConditions->getRaceDayWeather();
}

CarState* RaceWeekend::getCState(int i) {
	return this->CState[i];
}

void RaceWeekend::setCState(CarState* CState, int i) {
	delete this->CState[i] ;
	this->CState[i] = CState;
}

void RaceWeekend::deel_Damage(int i, int d)
{
	setDamage(getDamage(i) +d,i);
	car[i]->setDamage(d);
	if(getState(i) == "FullHP" && getDamage(i) > 10)
	{
		ChangeState(i);
	}
	else
	{
		if(getState(i) == "Damaged" && getDamage(i) > 90)
		{
			ChangeState(i);
		}
	}
}
std::string RaceWeekend::getState(int i)
{
	return this->CState[i]->getCarState();
}
int RaceWeekend::getDamage(int i) {
	return this->Damage[i];
}

void RaceWeekend::setDamage(int damage, int i) {
	this->Damage[i] = damage;
}

lg::RiskLevel RaceWeekend::getRiskLevel()
{
	return strategy->getRiskLevel();
}

void RaceWeekend::ChangeState(int i)
{
	CState[i]->handleChange();
	CState[i] = CState[i]->getState();
}
