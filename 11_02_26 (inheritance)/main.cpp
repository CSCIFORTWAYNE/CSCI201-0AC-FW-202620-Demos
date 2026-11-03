#include "twelveHrClock.h"
#include "clock.h"
#include <iostream>
// Module 2 Part A Lecture/Lab Activity
// implement the room class based on the room.h header file
// submit your room.cpp to IvyLearn

int main()
{
    TwelveHrClock c(2, 3, 3, TwelveHrClock::partOfDayType::AM);
    Clock c1(0, 0, 0);
    // c1.hr;
    std::cout << c.printTime() << std::endl;
    std::cout << c1.printTime() << std::endl;
    return 0;
}