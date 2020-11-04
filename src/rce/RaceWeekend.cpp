#include "RaceWeekend.h"
#include "RiskLevel.h"
#include <stdlib.h>
#include <time.h>

using namespace rce;

int RaceWeekend::RacingWeekend() {
    for (int i = 0; i < 3; i++) {
//        setDayWeather();
        for (int n = 0; n < 2; n++) {
            if (CState[n]->getCarState() != "Broken") {
                time[i] = 100;
                score[i] = 0;
                speed = car[i]->getSpeed();
                handling = car[i]->getHandling();
                hometrack = driver[i]->isHomeTrack(trackID);
                xp = driver[i]->getXp();
                if (speed >= 90) {
                    time[n] -= 25;
                } else {
                    if (speed >= 60 && speed < 90) {
                        time[n] -= 15;
                    } else {
                        if (speed >= 30 && speed < 60) {
                            time[n] -= 10;
                        } else {
                            if (speed < 30) {
                                time[n] -= 5;
                            }
                        }
                    }
                }//end of speed if
                if (handling >= 90) {
                    time[n] -= 25;
                } else {
                    if (handling >= 60 && handling < 90) {
                        time[n] -= 15;
                    } else {
                        if (handling >= 30 && handling < 60) {
                            time[n] -= 10;
                        } else {
                            if (handling < 30) {
                                time[n] -= 5;
                            }
                        }
                    }
                }//end of handling if
                srand(0);//srand(time);
                if (hometrack == true) {
                    time[n] -= rand() % 10 + 1;
                }
                if (xp >= 90) {
                    time[n] -= 40;
                } else {
                    if (xp >= 60 && xp < 90) {
                        time[n] -= 30;
                    } else {
                        if (xp >= 30 && xp < 60) {
                            time[n] -= 20;
                        } else {
                            if (xp < 30) {
                                time[n] -= 10;
                            }
                        }
                    }
                }//end of xp if
                lg::RiskLevel rl = strategy->getRiskLevel();
                int dam;
                int randval;
                if (rl == lg::Aggressive) {
                    randval = rand() % 10 + 1;
                    if (randval >= 7) {
                        dam = rand() % 60 + 30;
                    } else {
                        if (randval >= 4 && randval < 7) {
                            dam = rand() % 40 + 20;
                        } else {
                            if (randval < 4) {
                                dam = rand() % 20 + 0;
                            }
                        }
                    }
                } else {
                    if (rl == lg::Moderate) {
                        randval = rand() % 10 + 1;
                        if (randval >= 8) {
                            dam = rand() % 50 + 20;
                        } else {
                            if (randval >= 4 && randval < 8) {
                                dam = rand() % 30 + 10;
                            } else {
                                if (randval < 4) {
                                    dam = rand() % 10 + 0;
                                }
                            }
                        }
                    } else {
                        if (rl == lg::Safe) {
                            randval = rand() % 10 + 1;
                            if (randval >= 8) {
                                dam = rand() % 40 + 10;
                            } else {
                                if (randval >= 4 && randval < 8) {
                                    dam = rand() % 30 + 0;
                                } else {
                                    if (randval < 4) {
                                        dam = rand() % 5 + 0;
                                    }
                                }
                            }
                        }
                    }
                }
                if (DayWeather == lg::Hot) {
                    time[n] += rand() % 10 + 1;
                } else {
                    if (DayWeather == lg::Normal) {
                        time[n] += rand() % 5 + 0;
                    } else {
                        if (DayWeather == lg::Rainy) {
                            time[n] += rand() % 15 + 1;
                        }
                    }
                }
                deel_Damage(n, dam);
                if (CState[n]->getCarState() == "Broken") {
                    //notifyCar(int n);
                } else {
                    if (CState[n]->getCarState() == "Broken" && CState[n]->getDamage() >= 80) {
                        time[n] += rand() % 5 + 1;
                    } else {
                        if (CState[n]->getCarState() == "Broken" && CState[n]->getDamage() >= 40 &&
                            CState[n]->getDamage() < 80) {
                            time[n] += rand() % 8 + 1;
                        } else {
                            if (CState[n]->getCarState() == "Broken" && CState[n]->getDamage() >= 11 &&
                                CState[n]->getDamage() < 40) {
                                time[n] += rand() % 15 + 1;
                            }
                        }
                    }
                }//end if for broken car

                //tyre changes based on strat



            }//end if,if not broken car

        }
    }
}

eng::Car *RaceWeekend::getCar(int i) {
    return this->car[i];
}

void RaceWeekend::setCar(eng::Car *car, int i) {
    this->car[i] = car;
}

ppl::Driver *RaceWeekend::getDriver(int i) {
    return this->driver[i];
}

void RaceWeekend::setDriver(ppl::Driver *driver, int i) {
    this->driver[i] = driver;
}

list<ppl::Person*> RaceWeekend::getPitcrew() {
	return this->pitcrew;
}

void RaceWeekend::setPitcrew(std::list<ppl::Person*> pitcrew) {
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

	trackID = 1;//todo Ray

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
//	todo Louis
}
	}

std::string RaceWeekend::getState(int i)
{
	return this->CState[i]->getCarState();
}
int RaceWeekend::getDamage(int i)
{
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
