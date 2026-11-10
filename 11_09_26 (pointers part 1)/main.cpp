#include <iostream>
#include <limits>
#include "clock.h"

Clock *makeClock();
int inputHours();
int inputMinutesOrSeconds(std::string part);
void resetStream();

int main()
{

    int *p = nullptr;
    int q = 7;
    p = &q;
    int numNums = 0;
    std::cout << "How many numbers? ";
    std::cin >> numNums;
    std::cout << std::endl;
    while (!std::cin || numNums < 1)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not valid. Please enter a number greater than 1." << std::endl;
        std::cout << "How many numbers? ";
        std::cin >> numNums;
        std::cout << std::endl;
    }
    p = new int[numNums];
    int *r = nullptr;
    for (r = p; r <= &p[numNums - 1]; r++)
    {
        *r = -999;
        std::cout << *r << std::endl;
    }
    for (int i = 0; i < numNums; i++)
    {
        std::cout << p[i] << "  ";
        p[i] = -3;
        std::cout << p[i] << std::endl;
    }

    std::cout << &q << std::endl;
    std::cout << *p << std::endl;

    Clock *c = nullptr;
    std::cout << c << std::endl;
    // c->incrementSeconds();
    // std::cout << c->printTime() << std::endl;

    Clock c1(18, 40, 00);
    c = &c1;
    (*c).incrementMinutes();
    std::cout << c1.printTime() << std::endl;
    std::cout << c->printTime() << std::endl;
    Clock *c2 = nullptr;
    c2 = makeClock();
    c = makeClock();
    std::cout << c2->printTime() << std::endl;
    std::cout << c->printTime() << std::endl;
    delete c;
    c = nullptr;
    delete c2;
    c2 = nullptr;
}

Clock *makeClock()
{
    int hour = inputHours();
    int minute = inputMinutesOrSeconds("minutes");
    int second = inputMinutesOrSeconds("seconds");
    Clock *c = new Clock(hour, minute, second);
    return c;
}

int inputHours()
{
    int hour;
    std::cout << "Enter the hour on the clock: ";
    std::cin >> hour;
    std::cout << std::endl;
    while (!std::cin || hour < 0 || hour > 23)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid hour. Please enter a number between 0 and 23." << std::endl;
        std::cout << "Enter the hour on the clock: ";
        std::cin >> hour;
        std::cout << std::endl;
    }
    return hour;
}

int inputMinutesOrSeconds(std::string part)
{
    int time;
    std::cout << "Enter the number of " << part << " on the clock: ";
    std::cin >> time;
    std::cout << std::endl;
    while (!std::cin || time < 0 || time > 59)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid value for the number of " << part << ". Please enter a number between 0 and 59." << std::endl;
        std::cout << "Enter the number of " << part << " on the clock: ";
        std::cin >> time;
        std::cout << std::endl;
    }
    return time;
}

void resetStream()
{
    std::cin.clear(); // unlocks the doors (clears the error flags from the stream)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}