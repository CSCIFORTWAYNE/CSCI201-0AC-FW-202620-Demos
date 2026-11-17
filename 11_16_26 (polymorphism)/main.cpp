#include <iostream>
#include <random>
#include "twelveHrClock.h"
#include "clock.h"
#include "twentyfourHrClock.h"

// Module 4 part A lab -- tell me where you are with your project as of Monday 11/16

void displayClocks(Clock **clocks, int numClocks);
// void setClock(Clock c);
int main()
{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distributionHour(1, 12);
    std::uniform_int_distribution<int> distribution24Hour(0, 23);
    std::uniform_int_distribution<int> distributionMS(0, 59);
    std::uniform_int_distribution<int> distributionAPM(0, 1);
    Clock **clocks = new Clock *[10];
    for (int i = 0; i < 10; i++)
    {
        int clockType = distributionAPM(generator);
        if (clockType == 0)
        {
            clocks[i] = new TwelveHrClock(distributionHour(generator), distributionMS(generator), distributionMS(generator), TwelveHrClock::parts[distributionAPM(generator)]);
        }
        else
        {
            clocks[i] = new TwentyFourHrClock(distribution24Hour(generator), distributionMS(generator), distributionMS(generator));
        }
    }
    Clock *c = new TwelveHrClock(12, 12, 12, "AM");
    delete c;
    displayClocks(clocks, 10);
    // setClock(*clocks[0]);
    for (int i = 0; i < 10; i++)
    {
        delete clocks[i];
    }
    delete[] clocks;

    return 0;
}

void displayClocks(Clock **clocks, int numClocks)
{
    for (int i = 0; i < numClocks; i++)
    {
        std::cout << clocks[i]->printTime() << std::endl;
    }
}

/* void setClock(Clock c) // causes slicing
{
    int x;
    x = 0;
} */
