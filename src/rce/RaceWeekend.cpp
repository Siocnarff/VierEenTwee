#include "RaceWeekend.h"
//#include "RiskLevel.h"
#include <iostream>
using namespace rce;
int * RaceWeekend::RacingWeekend()
{
    std::string output;
    int *final;
    trackID = raceConditions->getTrackID();
    int resultarray[20];
    TC = raceConditions->getTrackComplexity();
    broken[0]=false;
    broken[1]=false;
    pr::Doc::outputOverride=false;


    for(int i = 0; i < 3; i++)
    {
        setDayWeather();
        pr::Doc::midInfo("\n      Today's Weather: ");
        if (DayWeather == lg::Hot) {
            pr::Doc::midInfo("Hot\n");
            pr::Doc::detail("         Careful drivers! The tarmac is melting your tyres!\n");
        }
        else if (DayWeather == lg::Normal) {
            pr::Doc::midInfo("Normal\n");
            pr::Doc::detail("         One less thing to worry about.\n");
        }
        else if (DayWeather == lg::Rainy) {
            pr::Doc::midInfo("Rainy\n");
            pr::Doc::detail("         Careful around the bends.\n");
        }


        pr::Doc::detail("\n");
        lg::RiskLevel rl = getRiskLevel();
        pr::Doc::detail("##########################\n");
        pr::Doc::detail("#   Race # ");
        pr::Doc::detail(std::to_string(i+1));
        pr::Doc::detail(" is starting.\n");
        pr::Doc::detail("##########################\n\n");
        // pr::Doc::transparency=2;
        output = "Race # ";
        output.append(std::to_string(i+1));
        output.append(" is starting.\n");
        pr::Doc::midInfo(output);
        output = "";
//        std::cout <<std:: endl<<"Rakce #"<<i+1<< " is starting."<<std:: endl<<std:: endl;
        setDayWeather();
        for(int n = 0; n < 2; n++)
        {
            time[n] = 100;
//            if(set[n])
//            {
//                std::cout<<getState(n)<<" "<<set[n]->getTyreCompoundString()<<std::endl;
//            }

            if(getState(n)!= "Broken" && set[n] != nullptr)
            {

                score[n] = 0;
                speed = car[n]->getSpeed();
                hometrack = driver[n]->isHomeTrack(trackID);
                xp = driver[n]->getXp();
                if(speed >= 90)
                {
                    int t=rand()%50+20;
                    time[n] -= t;
                    //std::cout <<"Car "<< n << " is fast and made up 33 units of time. "<< std:: endl;
                    output = "#   Car ";
                    output.append(std::to_string(n));
                    output.append(" is fast and made up ");
                    output.append(std::to_string(t));
                    output.append(" units of time.\n");
                    // pr::Doc::detail(std::to_string(n));
                    pr::Doc::detail(output);
                    output = "";
                }
                else
                {
                    if(speed>= 60 && speed <90)
                    {
                        int t=rand()%40+10;
                        time[n] -=t;
                        output = "#   Car ";
                        output.append(std::to_string(n));
                        output.append(" is fast and made up ");
                        output.append(std::to_string(t));
                        output.append(" units of time.\n");
                        pr::Doc::detail(output);
                        output = "";
                        //std::cout <<"Car "<< n << " is fast and made up 22 units of time. "<< std:: endl;
                        // pr::Doc::detail("Car ");
                        // pr::Doc::detail(std::to_string(n));
                        // pr::Doc::detail(" is fast and made up 22 units of time.\n");
                    }
                    else
                    {
                        if(speed >=30 && speed <60)
                        {
//                            time[n] -= 11;
                            int t=rand()%30+5;
                            time[n] -= t;

                            //std::cout <<"Car "<< n << " is slow but made up 11 units of time. "<< std:: endl;
                            //pr::Doc::detail("Car ");
                            // pr::Doc::detail(std::to_string(n));
                            //pr::Doc::detail( " is slow but made up 11 units of time.\n");
                            output = "#   Car ";
                            output.append(std::to_string(n));
                            output.append(" is fast and made up ");
                            output.append(std::to_string(t));
                            output.append(" units of time.\n");
                            pr::Doc::detail(output);
                            output = "";
                        }
                        else
                        {
                            if(speed <30)
                            {
//                                time[n] -= 5;
                                int t=rand()%20;
                                time[n] -= t;

                                //std::cout <<"Car "<< n << " is slow but made up 5 units of time. "<< std:: endl;
                                // pr::Doc::detail("Car ");
                                // pr::Doc::detail(std::to_string(n));
                                // pr::Doc::detail(" is slow but made up 5 units of time.\n");
                                output = "Car ";
                                output.append(std::to_string(n));
                                output.append(" is fast and made up ");
                                output.append(std::to_string(t));
                                output.append(" units of time.\n");
                                pr::Doc::detail(output);
                                output = "";
                            }
                        }
                    }
                }//end of speed if
                if(handling[n] >= 90)
                {
                    int t=rand()%40+17;
                    time[n] -= t;
                    //std::cout <<"Car "<< n << " handles great and made up 33 units of time. "<< std:: endl;
                    //  pr::Doc::detail("Car ");
                    // pr::Doc::detail(std::to_string(n));
                    //  pr::Doc::detail(" handles great and made up 33 units of time.\n");
                    output = "Car ";
                    output.append(std::to_string(n));
                    output.append(" handles great and made up ");
                    output.append(std::to_string(t));
                    output.append(" units of time.\n");
                    pr::Doc::detail(output);
                    output = "";
                }
                else
                {
                    if(handling[n]>= 60 && handling[n] <90)
                    {
                        int t=rand()%40+12;
                        time[n] -= t;
                        //std::cout <<"Car "<< n << " handles good and made up 22 units of time. "<< std:: endl;
                        //pr::Doc::detail("Car ");
                        // pr::Doc::detail(std::to_string(n));
                        // pr::Doc::detail(" handles good and made up 22 units of time.\n");
                        output = "Car ";
                        output.append(std::to_string(n));
                        output.append(" handles good and made up ");
                        output.append(std::to_string(t));
                        output.append("units of time.\n");
                        pr::Doc::detail(output);
                        output = "";
                    }
                    else
                    {
                        if(handling[n] >=30 && handling[n] <60)
                        {
                            int t=rand()%30+6;
                            time[n] -= t;
                            //std::cout <<"Car "<< n << " handles bad but made up 11 units of time. "<< std:: endl;
                            //pr::Doc::detail("Car ");
                            // pr::Doc::detail(std::to_string(n));
                            // pr::Doc::detail(" handles bad but made up 11 units of time.\n");
                            output = "Car ";
                            output.append(std::to_string(n));
                            output.append(" handles bad and made up ");
                            output.append(std::to_string(t));
                            output.append(" units of time.\n");
                            pr::Doc::detail(output);
                            output = "";
                        }
                        else
                        {
                            if(handling[n] <30)
                            {
                                int t=rand()%20+5;
                                time[n] -= t;
                                //std::cout <<"Car "<< n << " handles bad but made up 5 units of time. "<< std:: endl;
                                // pr::Doc::detail("Car ");
                                //  pr::Doc::detail(std::to_string(n));
                                // pr::Doc::detail(" handles bad but made up 5 units of time.\n");
                                output = "Car ";
                                output.append(std::to_string(n));
                                output.append(" handles bad but made up ");
                                output.append(std::to_string(t));
                                output.append(" units of time.\n");
                                pr::Doc::detail(output);
                                output = "";
                            }
                        }
                    }
                }//end of handling if
                //srand(time(NULL));
                if(hometrack == true)
                {
                    int t = rand()%15+1;
                    time[n] -= t;
                    //std::cout <<"This is "<< driver[n]->getName() << "'s home track thus could make up "<<t << " units of time through prior knowledge."<< std:: endl;
                    //pr::Doc::detail("This is ");
                    // pr::Doc::detail(driver[n]->getName());
                    // pr::Doc::detail( "'s home track thus could make up ");
                    // pr::Doc::detail(std::to_string(t));
                    // pr::Doc::detail( " units of time through prior knowledge.\n");
                    output = "This is ";
                    output.append(driver[n]->getName());
                    output.append("'s home track thus could make up ");
                    output.append(std::to_string(t));
                    output.append(" units of time through prior knowledge.\n");
                    pr::Doc::detail(output);
                    output = "";
                }
                if(xp >= 90)
                {
                    int t=rand()%40+30;
                    time[n] -= t;
                    //std::cout << driver[n]->getName() << " has a lot of experience and could make up 40 units of time."<< std:: endl;
                    // pr::Doc::detail(driver[n]->getName());
                    // pr::Doc::detail( " has a lot of experience and could make up 40 units of time.\n");
                    output = driver[n]->getName();
                    output.append(" has a lot of experience and could make up ");
                    output.append(std::to_string(t));
                    output.append(" units of time.\n");
                    pr::Doc::detail(output);
                    output = "";
                }
                else
                {
                    if(xp>= 60 && xp <90)
                    {
                        int t=rand()%30+20;
                        time[n] -= t;
                        //std::cout << driver[n]->getName() << " has a good amount of experience and could make up 30 units of time."<< std:: endl;
                        // pr::Doc::detail(driver[n]->getName());
                        // pr::Doc::detail( " has a good amount of experience and could make up 30 units of time.\n");
                        output = driver[n]->getName();
                        output.append(" has a good amount of experience and could make up ");
                        output.append(std::to_string(t));
                        output.append(" units of time.\n");
                        pr::Doc::detail(output);
                        output = "";
                    }
                    else
                    {
                        if(xp >=30 && xp <60)
                        {
                            int t=rand()%20+15;
                            time[n] -= t;
                            //std::cout << driver[n]->getName() << " has some experience and could make up 20 units of time."<< std:: endl;
                            // pr::Doc::detail(driver[n]->getName());
                            //  pr::Doc::detail( " has some experience and could make up 20 units of time.\n");
                            output = driver[n]->getName();
                            output.append(" has some experience and could make up ");
                            output.append(std::to_string(t));
                            output.append(" units of time.\n");
                            pr::Doc::detail(output);
                            output = "";
                        }
                        else
                        {
                            if(xp <30)
                            {
                                int t=rand()%15+10;
                                time[n] -= t;
                                //std::cout << driver[n]->getName() << " has little experience and could make up 10 units of time."<< std:: endl;
                                // pr::Doc::detail(driver[n]->getName());
                                // pr::Doc::detail( " has little experience and could make up 10 units of time.\n");
                                output = driver[n]->getName();
                                output.append(" has little experience and could make up ");
                                output.append(std::to_string(t));
                               output.append(" units of time.\n");
                                pr::Doc::detail(output);
                                output = "";
                            }
                        }
                    }
                }//end of xp if
                if(TC == lg::Easy)
                {
                    int t= rand()%30+20;
                    time[n] -= t;
                    //std::cout << "The track was easy and " <<driver[n]->getName()<<" has gained 30 unites of time."<< std:: endl;
                    // pr::Doc::detail( "The track was easy and " );
                    // pr::Doc::detail(driver[n]->getName());
                    // pr::Doc::detail( " has gained 30 unites of time.\n");
                    output = "The track was easy and ";
                    output.append(driver[n]->getName());
                    output.append(" has gained ");
                    output.append(std::to_string(t));
                    output.append(" unites of time.\n");
                    pr::Doc::detail(output);
                    output = "";
                }
                else
                {
                    if(TC==lg::Average)
                    {
                        int t= rand()%15+10;
                        time[n] -= t;
                        //std::cout << "The track was good and " <<driver[n]->getName()<<" has gained 15 unites of time."<< std:: endl;
                        //pr::Doc::detail( "The track was good and " );
                        // pr::Doc::detail(driver[n]->getName());
                        // pr::Doc::detail( " has gained 15 unites of time.\n");
                        output = "The track was good and ";
                        output.append(driver[n]->getName());
                        output.append(" has gained ");
                        output.append(std::to_string(t));
                        output.append(" unites of time.\n");
                        pr::Doc::detail(output);
                        output = "";
                    }
                    else
                    {
                        if( TC == lg::Difficult)
                        {
                            int t= rand()%10;
                            time[n] += t;
                            //std::cout << "The track was difficult and " <<driver[n]->getName()<<" has lost 5 unites of time."<< std:: endl;
                            // pr::Doc::detail( "The track was difficult and " );
                            // pr::Doc::detail(driver[n]->getName());
                            // pr::Doc::detail( " has lost 5 unites of time.\n");
                            output = "The track was difficult and ";
                            output.append(driver[n]->getName());
                            output.append(" has gained ");
                            output.append(std::to_string(t));
                            output.append(" unites of time.\n");
                            pr::Doc::detail(output);
                            output = "";
                        }
                        else
                        {
                            if(TC== lg::Extreme)
                            {
                                int t=rand()%20+15;
                                time[n] += t;
                                //std::cout << "The track was extremely difficult and " <<driver[n]->getName()<<" has lost 15 unites of time."<< std:: endl;
                                // pr::Doc::detail( "The track was extremely difficult and " );
                                // pr::Doc::detail(driver[n]->getName());
                                // pr::Doc::detail( " has lost 15 unites of time.\n");
                                output = "The track was extremely difficult and ";
                                output.append(driver[n]->getName());
                                output.append( " has lost ");
                                output.append(std::to_string(t));
                                output.append(" unites of time.\n");
                                pr::Doc::detail(output);
                                output = "";
                            }
                        }
                    }
                }
                int dam;
                int randval;
                int Damagetotyres = 0;
                if(rl == lg::Aggressive)
                {
                    randval = rand() %10 +1;
                    if(randval >= 7)
                    {
                        int t=rand()%40+20 ;
                        time[n] -= t;
                        dam = rand() %60 +5;

                        output = "Car ";
                        output.append(std::to_string(n));
                        output.append( " has taken ");
                        output.append( std::to_string(dam));
                        output.append(" units of damage due to being aggressive, but has gained ");
                        output.append(std::to_string(t));
                        output.append(" units of time.\n");
                        pr::Doc::detail(output);
                        output = "";
                        Damagetotyres = rand() %250 +5;
                    }
                    else
                    {
                        if(randval >= 4 && randval <7 )
                        {
                            int t=rand()%40+20 ;
                            time[n] -= t;
                            dam = rand() %40 + 5;
                            //std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to being aggressive, but has gained 40 units of time. "<< std:: endl;
                            // pr::Doc::detail("Car ");
                            // pr::Doc::detail(std::to_string(n));
                            // pr::Doc::detail(" has taken ");
                            //  pr::Doc::detail(std::to_string(dam));
                            // pr::Doc::detail(" units of damage due to being aggressive, but has gained 40 units of time.\n");
                            output = "Car ";
                            output.append(std::to_string(n));
                            output.append( " has taken ");
                            output.append( std::to_string(dam));
                            output.append(" units of damage due to being aggressive, but has gained ");
                            output.append(std::to_string(t));
                            output.append(" units of time.\n");
                            pr::Doc::detail(output);
                            output = "";
                            Damagetotyres = rand() %230 +5;
                        }
                        else
                        {
                            if(randval < 4)
                            {
                                int t=rand()%40+20 ;
                                time[n] -= t;
                                dam = rand()%20+0;
                                //std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to being aggressive,but has gained 40 units of time. "<< std:: endl;
                                // pr::Doc::detail("Car ");
                                // pr::Doc::detail(std::to_string(n));
                                // pr::Doc::detail(" has taken ");
                                // pr::Doc::detail(std::to_string(dam));
                                //  pr::Doc::detail(" units of damage due to being aggressive, but has gained 40 units of time.\n");
                                output = "Car ";
                                output.append(std::to_string(n));
                                output.append( " has taken ");
                                output.append( std::to_string(dam));
                                output.append(" units of damage due to being aggressive, but has gained ");
                                output.append(std::to_string(t));
                                output.append(" units of time.\n");
                                pr::Doc::detail(output);
                                output = "";
                                Damagetotyres =rand() %210 +5;
                            }
                        }
                    }
                }
                if(rl == lg::Moderate)
                {
                    randval = rand() %10 +1;
                    if(randval >= 8)
                    {
                        int t=rand()%20+10 ;
                        time[n] -=t;
                        dam = rand() %40 +0;
                        //std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving at a moderate risk level, but has gained 20 units od time."<< std:: endl;
                        // pr::Doc::detail("Car ");
                        // pr::Doc::detail(std::to_string(n));
                        // pr::Doc::detail(" has taken ");
                        // pr::Doc::detail(std::to_string(dam));
                        // pr::Doc::detail(" units of damage due to driving at a moderate risk level, but has gained 20 units od time.\n");
                        output = "Car ";
                        output.append(std::to_string(n));
                        output.append( " has taken ");
                        output.append( std::to_string(dam));
                        output.append(" units of damage due to driving at a moderate risk level, but has gained ");
                        output.append(std::to_string(t));
                        output.append(" units od time.\n");
                        pr::Doc::detail(output);
                        output = "";
                        Damagetotyres = rand() %200 +5;
                    }
                    else
                    {
                        if(randval >= 4 && randval <8)
                        {
                            int t=rand()%20+10 ;
                            time[n] -=t;
                            dam = rand() %30 + 10;
                            //std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving at a moderate risk level,but has gained 20 units od time."<< std:: endl;
                            // pr::Doc::detail("Car ");
                            //  pr::Doc::detail(std::to_string(n));
                            // pr::Doc::detail(" has taken ");
                            // pr::Doc::detail(std::to_string(dam));
                            //  pr::Doc::detail(" units of damage due to driving at a moderate risk level, but has gained 20 units od time.\n");
                            output = "Car ";
                            output.append(std::to_string(n));
                            output.append( " has taken ");
                            output.append( std::to_string(dam));
                            output.append(" units of damage due to driving at a moderate risk level, but has gained ");
                            output.append(std::to_string(t));
                            output.append(" units od time.\n");
                            pr::Doc::detail(output);
                            output = "";
                            Damagetotyres = rand() %170;
                        }
                        else
                        {
                            if(randval < 4)
                            {
                                int t=rand()%20+10 ;
                                time[n] -=t;
                                Damagetotyres =rand() %130;
                                dam = rand()%10+0;
                                //std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving at a moderate risk levelbut has gained 20 units od time."<< std:: endl;
                                //pr::Doc::detail("Car ");
                                // pr::Doc::detail(std::to_string(n));
                                // pr::Doc::detail(" has taken ");
                                // pr::Doc::detail(std::to_string(dam));
                                //  pr::Doc::detail(" units of damage due to driving at a moderate risk level, but has gained 20 units od time.\n");
                                output = "Car ";
                                output.append(std::to_string(n));
                                output.append( " has taken ");
                                output.append( std::to_string(dam));
                                output.append(" units of damage due to driving at a moderate risk level, but has gained ");
                                output.append(std::to_string(t));
                                output.append(" units od time.\n");
                                pr::Doc::detail(output);
                                output = "";

                            }
                        }
                    }
                }
                if(rl == lg::Safe)
                {
                    randval = rand() %10 +1;
                    if(randval >= 8)
                    {
                        int t=rand()%10+5 ;
                        time[n] -= t;
                        dam = rand() %15+0;
                        //std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving Safely and gained 10 units of time."<< std:: endl;
                        //pr::Doc::detail("Car ");
                        // pr::Doc::detail(std::to_string(n));
                        // pr::Doc::detail(" has taken ");
                        // pr::Doc::detail(std::to_string(dam));
                        // pr::Doc::detail(" units of damage due to driving Safely and gained 10 units of time.\n");
                        output = "Car ";
                        output.append(std::to_string(n));
                        output.append( " has taken ");
                        output.append( std::to_string(dam));
                        output.append(" units of damage due to driving Safely and gained ");
                        output.append(std::to_string(t));
                        output.append(" units of time.\n");
                        pr::Doc::detail(output);
                        output = "";
                        Damagetotyres =rand() %150;
                    }
                    else
                    {
                        if(randval >= 4 && randval <8)
                        {
                            int t= rand()%10+5;
                            time[n] -= t;
                            dam = rand() %10 + 0;
                            //std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving Safely and gained 10 units of time."<< std:: endl;
                            // pr::Doc::detail("Car ");
                            //  pr::Doc::detail(std::to_string(n));
                            // pr::Doc::detail(" has taken ");
                            //  pr::Doc::detail(std::to_string(dam));
                            //  pr::Doc::detail(" units of damage due to driving Safely and gained 10 units of time.\n");
                            output = "Car ";
                            output.append(std::to_string(n));
                            output.append( " has taken ");
                            output.append( std::to_string(dam));
                            output.append(" units of damage due to driving Safely and gained ");
                            output.append(std::to_string(t));
                            output.append(" units of time.\n");
                            pr::Doc::detail(output);
                            output = "";
                            Damagetotyres =rand() %100;
                        }
                        else
                        {
                            if(randval < 4)
                            {
                                int t= rand()%10+5;
                                time[n] -= t;
                                dam = rand()%5+0;
                                //std::cout <<"Car "<< n << " has taken "<<dam<<" units of damage due to driving Safely and gained 10 units of time."<< std:: endl;
                                // pr::Doc::detail("Car ");
                                // pr::Doc::detail(std::to_string(n));
                                // pr::Doc::detail(" has taken ");
                                // pr::Doc::detail(std::to_string(dam));
                                //  pr::Doc::detail(" units of damage due to driving Safely and gained 10 units of time.\n");
                                output = "Car ";
                                output.append(std::to_string(n));
                                output.append( " has taken ");
                                output.append( std::to_string(dam));
                                output.append(" units of damage due to driving Safely and gained ");
                                output.append(std::to_string(t));
                                output.append("  units of time.\n");
                                pr::Doc::detail(output);
                                output = "";
                                Damagetotyres = rand() %50;
                            }
                        }
                    }
                }
                deel_Damage(n,dam);
                int threadleft;
                int count =0;
                if(set[n] != nullptr)
                {

                    if(set[n]->getTyreCompoundString() == "Medium Tyres")
                    {
                        Damagetotyres -= rand() %20;
                    }
                    else
                    {
                        if(set[n]->getTyreCompoundString() == "Hard Tyres")
                        {
                            Damagetotyres -= rand() %30;
                        }
                    }
                    while(Damagetotyres>= 100)
                    {
                        if(set[n] != nullptr)
                        {

                            threadleft = set[n]->getThread();
                            if(threadleft < Damagetotyres)
                            {
                                Damagetotyres -= threadleft;
                                set[n]->reduceThread(threadleft);
                                set[n] = pitstop[n]->stop();
                                count++;
                            }
                            else
                            {
                                if(threadleft == Damagetotyres)
                                {
                                    Damagetotyres -= threadleft;
                                    set[n]->reduceThread(threadleft);
                                    set[n] = pitstop[n]->stop();
                                    Damagetotyres =0;
                                    count++;
                                }
                                else
                                {
                                    if(threadleft > Damagetotyres)
                                    {
                                        set[n]->reduceThread(Damagetotyres);
                                        Damagetotyres = 0;
                                    }
                                }
                            }

                        }
                        else
                        {
                            break;// no tyres left
                        }
                    }
                }
                if(set[n] != nullptr)
                {
                    if(set[n]->getTyreCompoundString() == "Medium Tyres")
                    {
                        Damagetotyres -= rand() %20;
                    }
                    else
                    {
                        if(set[n]->getTyreCompoundString() == "Hard Tyres")
                        {
                            Damagetotyres -= rand() %30;
                        }
                    }
                    if(Damagetotyres> 0){
                        threadleft = set[n]->getThread();
                        if(threadleft < Damagetotyres)
                        {
                            Damagetotyres -= threadleft;
                            set[n]->reduceThread(threadleft);
                            set[n] = pitstop[n]->stop();
                            if(set[n] != nullptr)
                            {
                                set[n]->reduceThread(Damagetotyres);
                            }
                            Damagetotyres =0;
                            count++;
                        }
                        else
                        {
                            if(threadleft == Damagetotyres)
                            {
                                Damagetotyres -= threadleft;
                                set[n]->reduceThread(threadleft);
                                set[n] = pitstop[n]->stop();
                                Damagetotyres =0;
                                count++;
                            }
                            else
                            {
                                if(threadleft > Damagetotyres)
                                {
                                    Damagetotyres = 0;
                                    set[n]->reduceThread(Damagetotyres);
                                }
                            }
                        }
                    }
                }
                Damagetotyres =0;

                if(DayWeather == lg::Normal)
                {
                    int t = rand()%10+1 ;
                    time[n] += t ;
                    //std::cout << driver[n]->getName() << "has lost "<<t << " units of time due to normal weather."<< std:: endl;
                    //pr::Doc::detail(driver[n]->getName());
                    // pr::Doc::detail(std::to_string(n));
                    // pr::Doc::detail("has lost ");
                    // pr::Doc::detail(std::to_string(t));
                    // pr::Doc::detail(" units of time due to normal weather.\n");
                    output = driver[n]->getName();
                    output.append("has lost ");
                    output.append( std::to_string(t));
                    output.append(" units of time due to normal weather.\n");
                    pr::Doc::detail(output);
                    output = "";
                    Damagetotyres += rand() %70;
                }
                else
                {
                    if(DayWeather == lg::Hot)
                    {
                        int t = rand()%5+0 ;
                        time[n] += t ;
                        //std::cout << driver[n]->getName() << " has lost "<<t << " units of time due to hot weather."<< std:: endl;
                        //pr::Doc::detail(driver[n]->getName());
                        // pr::Doc::detail(std::to_string(n));
                        // pr::Doc::detail("has lost ");
                        // pr::Doc::detail(std::to_string(t));
                        // pr::Doc::detail(" units of time due to hot weather.\n");
                        output = driver[n]->getName();
                        output.append("has lost ");
                        output.append( std::to_string(t));
                        output.append(" units of time due to hot weather.\n");
                        pr::Doc::detail(output);
                        output = "";
                        Damagetotyres +=rand() %50;
                    }
                    else
                    {
                        if(DayWeather == lg::Rainy)
                        {
                            int t = rand()%15+1 ;
                            time[n] += t;
                            //std::cout << driver[n]->getName() << " has lost "<<t << " units of time due to rainy weather."<< std:: endl;
                            // pr::Doc::detail(driver[n]->getName());
                            // pr::Doc::detail(std::to_string(n));
                            // pr::Doc::detail("has lost ");
                            // pr::Doc::detail(std::to_string(t));
                            // pr::Doc::detail(" units of time due to rainy weather.\n");
                            output = driver[n]->getName();
                            output.append("has lost ");
                            output.append( std::to_string(t));
                            output.append(" units of time due to rainy weather.\n");
                            pr::Doc::detail(output);
                            output = "";
                            Damagetotyres +=rand() %15;
                        }
                    }
                }
                if(set[n] != nullptr)
                {
                    if(set[n]->getTyreCompoundString() == "Medium Tyres")
                    {
                        Damagetotyres -= rand() %20;
                    }
                    else
                    {
                        if(set[n]->getTyreCompoundString() == "Hard Tyres")
                        {
                            Damagetotyres -= rand() %30;
                        }
                    }
                    if(Damagetotyres> 0){
                        threadleft = set[n]->getThread();
                        if(threadleft < Damagetotyres)
                        {
                            Damagetotyres -= threadleft;
                            set[n]->reduceThread(threadleft);
                            set[n] = pitstop[n]->stop();
                            set[n]->reduceThread(Damagetotyres);
                            Damagetotyres =0;
                            count++;
                        }
                        else
                        {
                            if(threadleft == Damagetotyres)
                            {
                                Damagetotyres -= threadleft;
                                set[n]->reduceThread(threadleft);
                                set[n] = pitstop[n]->stop();
                                Damagetotyres =0;
                                count++;
                            }
                            else
                            {
                                if(threadleft > Damagetotyres)
                                {
                                    Damagetotyres = 0;
                                    set[n]->reduceThread(Damagetotyres);
                                }
                            }
                        }
                    }
                }

                //std::cout <<"Car "<< n << " has to take "<<count<<" pitstops through the race."<< std:: endl;
                // pr::Doc::detail("Car ");
                // pr::Doc::detail(std::to_string(n));
                // pr::Doc::detail(" has to take ");
                // pr::Doc::detail(std::to_string(count));
                // pr::Doc::detail(" pitstops through the race.\n");
                output = "Car ";
                output.append(std::to_string(n));
                output.append( " has to take ");
                output.append(std::to_string(count));
                output.append(" pitstops through the race.\n");
                pr::Doc::detail(output);
                output = "";
                if(getState(n) == "Broken")
                {
//                    getCarnotify(n, raceConditions);
                    broken[n]=true;
                    //std::cout <<"Car "<< n << " has taken too much damage during and is broken. The race has ended for Car "<< n <<"."<< std:: endl;
                    // pr::Doc::detail("Car ");
                    // pr::Doc::detail(std::to_string(n));
                    // pr::Doc::detail(" has taken too much damage during and is broken. The race has ended for Car ");
                    // pr::Doc::detail(std::to_string(n));
                    // pr::Doc::detail(".\n");
                    output = "Car ";
                    output.append(std::to_string(n));
                    output.append( " has taken too much damage during and is broken. The race has ended for Car ");
                    output.append(std::to_string(n));
                    pr::Doc::detail(output);
                    output = "";
                    time[n] = 100;
                }
                else
                {
                    if(getState(n) == "Damaged" && getDamage(n) >=80 )
                    {
                        int t = rand()%5+0;
                        time[n] +=  t;
                        //std::cout <<"Car "<< n << " has taken damage and lost "<<t<<" units of time."<< std:: endl;
                        //  pr::Doc::detail("Car ");
                        //   pr::Doc::detail(std::to_string(n));
                        //   pr::Doc::detail(" has taken damage and lost ");
                        //   pr::Doc::detail(std::to_string(t));
                        //   pr::Doc::detail(" units of time.\n");
                        output = "Car ";
                        output.append(std::to_string(n));
                        output.append( " has taken damage and lost ");
                        output.append(std::to_string(t));
                        output.append(" units of time.\n");
                        pr::Doc::detail(output);
                        output = "";
                    }
                    else
                    {
                        if(getState(n) == "Damaged" && getDamage(n) >=40 && getDamage(n) < 80)
                        {
                            int t = rand()%8+0;
                            time[n] +=  t;
                            //std::cout <<"Car "<< n << " has taken damage and lost "<<t<<" units of time."<< std:: endl;
                            // pr::Doc::detail("Car ");
                            // pr::Doc::detail(std::to_string(n));
                            // pr::Doc::detail(" has taken damage and lost ");
                            //  pr::Doc::detail(std::to_string(t));
                            //  pr::Doc::detail(" units of time.\n");
                            output = "Car ";
                            output.append(std::to_string(n));
                            output.append( " has taken damage and lost ");
                            output.append(std::to_string(t));
                            output.append(" units of time.\n");
                            pr::Doc::detail(output);
                            output = "";
                        }
                        else
                        {
                            if(getState(n) == "Damaged" && getDamage(n) >=11 && getDamage(n) < 40)
                            {
                                int t = rand()%15+0;
                                time[n] +=  t;
                                //std::cout <<"Car "<< n << " has taken a lot of damage and lost "<<t<<" units of time."<< std:: endl;
                                // pr::Doc::detail("Car ");
                                // pr::Doc::detail(std::to_string(n));
                                //  pr::Doc::detail(" has taken damage and lost ");
                                //  pr::Doc::detail(std::to_string(t));
                                //  pr::Doc::detail(" units of time.\n");
                                output = "Car ";
                                output.append(std::to_string(n));
                                output.append( " has taken damage and lost ");
                                output.append(std::to_string(t));
                                output.append(" units of time.\n");
                                pr::Doc::detail(output);
                                output = "";
                            }
                        }
                    }
                }//end if for broken car
                //still need to reduce amount of tires based on tire compound

                if(set[n] == nullptr)
                {
                    time[n] = 100;
//                    getCarnotify(n,raceConditions);
                    broken[n]=true;
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
        //std::cout <<std:: endl<<"Race #"<<i+1<< " has ended."<<std:: endl<<std:: endl;
        //pr::Doc::detail("Race # ");
        // pr::Doc::detail(std::to_string(i+1));
        // pr::Doc::detail(" has ended.\n");
        output = "Race # ";
        output.append(std::to_string(i+1));
        output.append( " has ended.\n");
        pr::Doc::midInfo(output);
        output = "";

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
        int largest = -1;
        int position =1;
        for(int i = 0; i < 20; i ++)
        {
            for(int n = 0; n < 20; n++)
            {
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
            largest = -1;
        }

        for(int j = 0; j < 2; j++)
        {
            lead[j]->createLeaderboard(driver[0]->getName(), driver[1]->getName(), resultarray);
            if(i == 2)
            {
                lead[j]->setdisplayLeaderboard(true);
                lead[j]->display();
            }
        }
    final=array;
    }
    ret = new int[2];
    ret[0] =  resultarray[9];
    ret[1] = resultarray[19];

    lead[0]->setDriver(driver[0]->getName(), driver[1]->getName());
    lead[0]->setFinalScore(resultarray);

//    notifybackCar(carresult,raceConditions);
    return ret;
}

RaceWeekend::~RaceWeekend()
{
    for(int i=0;i<2;i++)
    {
//        delete tyre[i];
//        delete car[i];
//        delete driver[i];
//        delete pitstop[i];
//        delete set[i];
//        delete CState[i]; //
    }
    delete []tyre;
    delete []set;
    delete []car;
    delete []pitstop;
    delete []driver;
    delete []CState;
    delete ret;


//    car = new eng::Car*[2];
//    driver = new ppl::Driver*[2];
////    lead = new Leaderboard*[2];
//    pitstop = new Pitstop*[2];
//    lead=l;
//    pitcrew = p;
//    tyre = new Tyres*[2];
//    set = new SetOfTyres*[2];
//    strategy =s;
//    CState = new CarState*[2];
//    strategy->getRiskLevel();
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

ppl::Person** RaceWeekend::getPitcrew() {
    return this->pitcrew;
}

void RaceWeekend::setPitcrew(ppl::Person** pitcrew) {
    this->pitcrew = pitcrew;
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

RaceWeekend::RaceWeekend(eng::Car** cars, ppl::Driver** drivers, lg::Race* r, CreateStrategy* s, ppl::Person** p, Tyres ** t, Leaderboard ** l) {
    car = new eng::Car*[2];
    driver = new ppl::Driver*[2];
//    lead = new Leaderboard*[2];
    pitstop = new Pitstop*[2];
    lead=l;
    pitcrew = p;
    tyre = new Tyres*[2];
    set = new SetOfTyres*[2];
    strategy =s;
    CState = new CarState*[2];
    strategy->getRiskLevel();
    for(int i =0; i < 2; i++)
    {
        tyre[i] = t[i];
        set[i] = tyre[i]->getTyres(0);
        if(set[i]  == nullptr)
        {
            set[i] = tyre[i]->getTyres(1);
            if(set[i]  == nullptr)
            {
                set[i] = tyre[i]->getTyres(2);
            }
        }

        if(!set[i])
        {
//            int tyreArr[3];
//            tyreArr[0]=1;
//            tyreArr[1]=2;
//            tyreArr[2]=3;
            delete tyre[i];
            tyre[i]=new Tyres(strategy->getTyres());
        }
        car[i] = cars[i];
//        tyresleft[i] = true;
        pitstop[i] = new DriverPitStop(car[i],tyre[i],pitcrew);
        pitstop[i]->addCrew(pitcrew);
        pitstop[i]->tyres(tyre[i]);
        pitstop[i]->setCar(car[i]);
        driver[i] = drivers[i];
        handling[i] = car[i]->getHandling();
//        lead[i] = l[i];
        CState[i] = new CarStateFullHP();
        Damage[i] = 0;

    }
    this->raceConditions =r;


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
bool* RaceWeekend::getBrokenCar()
{
    bool* k;
    k=broken;
    return k;
}
//void RaceWeekend::getCarnotify(int i,lg::Race* r)
//{
//    notify(car[i],r);
//}
//
//void RaceWeekend::notifybackCar(std::vector<eng::Car*> c, lg::Race *r)
//{
//    notify(c,r);
//}

//void RaceWeekend::hireEmployees(int)
//{
//
//}