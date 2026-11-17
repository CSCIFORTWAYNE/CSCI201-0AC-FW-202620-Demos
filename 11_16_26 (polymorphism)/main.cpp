#include <iostream>
#include <random>
#include "twelveHrClock.h"
#include "clock.h"

void displayClocks(Clock **clocks, int numClocks);
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
            clocks[i] = new Clock(distribution24Hour(generator), distributionMS(generator), distributionMS(generator));
        }
    }
    displayClocks(clocks, 10);

    return 0;
}

void displayClocks(Clock **clocks, int numClocks)
{
    for (int i = 0; i < numClocks; i++)
    {
        std::cout << clocks[i]->printTime() << std::endl;
    }
}
