#include "twelveHrClock.h"
#include "clock.h"
#include <iostream>

int main()
{
    TwelveHrClock c(2, 3, 3, TwelveHrClock::partOfDayType::AM);
    Clock c1(0, 0, 0);
    // c1.hr;
    std::cout << c.printTime() << std::endl;
    std::cout << c1.printTime() << std::endl;
    return 0;
}