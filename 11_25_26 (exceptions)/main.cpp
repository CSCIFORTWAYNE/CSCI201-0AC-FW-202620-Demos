#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <random>
#include "twentyfourHrClock.h"
#include "twelveHrClock.h"

int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool isIntInRange(int num, int low, int high);
bool isAorB(int num, int a, int b);
bool isGTX(int num, int low, int high = 0);
void resetStream();
Clock *makeClock();
int inputClockType();
TwelveHrClock::partOfDayType inputPartOfDay();

int main()
{
    std::vector<int> list;
    list.push_back(5);
    list[3] = 7;
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution distribution(0, 100);
    try
    {
        int x = inputInt("Enter a number: ", "error", isGTX, -1);
        list.at(x) = 7;
        // TwentyFourHrClock newclock(distribution(generator), distribution(generator), distribution(generator));
        Clock *newClock = makeClock();
        std::cout << *newClock << std::endl;
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (int n)
    {
        if (n == 8)
        {
            std::cout << "input failure detected" << std::endl;
            resetStream();
        }
        else if (n == 10)
        {
            std::cout << "negative input detected" << std::endl;
        }
    }
    catch (std::invalid_argument e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

bool isIntInRange(int num, int low, int high)
{
    return num >= low && num <= high;
}

bool isAorB(int num, int a, int b)
{
    return num == a || num == b;
}

bool isGTX(int num, int low, int high)
{
    return num > low;
}

int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;
    if (!std::cin)
    {
        throw 8;
    }
    if (!valid(num, low, high))
    {
        throw 10;
    }
    return num;
}

void resetStream()
{
    std::cin.clear(); // unlocks the doors (clears the error flags from the stream)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Clock *makeClock()
{
    Clock *clockptr = nullptr;
    int type = inputClockType();
    std::string hourPrompt = "Enter the clock's hour: ";
    std::string minPrompt = "Enter the clock's minutes: ";
    std::string secPrompt = "Enter the clock's seconds: ";
    int hour;
    int minute;
    int second;
    bool validHour = false;
    bool (*validHourFunc)(int, int, int) = isGTX;
    int hourLow = 0;
    int hourHigh = 0;
    bool validMinute = false;
    bool validSecond = false;
    bool validAM = false;
    bool retry = true;
    while (retry)
    {
        if (!validHour)
        {
            try
            {
                hour = inputInt(hourPrompt, "The hour is invalid", validHourFunc, hourLow, hourHigh);
            }
            catch (int e)
            {
                resetStream();
            }
            validHour = true;
        }
        if (!validMinute)
        {
            try
            {
                minute = inputInt(minPrompt, "error", isGTX);
            }
            catch (int e)
            {
                resetStream();
            }
            validMinute = true;
        }
        if (!validSecond)
        {
            try
            {
                second = inputInt(secPrompt, "error", isGTX);
            }
            catch (int e)
            {
                resetStream();
            }
            validSecond = true;
        }
        try
        {
            clockptr = new TwentyFourHrClock(hour, minute, second);
            retry = false;
        }
        catch (Invalid_Hour e)
        {
            std::cout << e.what() << std::endl;
            if (e.getHour() != -1)
            {
                e.getHourRange(hourLow, hourHigh);
                validHourFunc = isIntInRange;
            }
            validHour = false;
        }
        catch (std::invalid_argument e)
        {
            std::cout << e.what() << std::endl;
            validMinute = false;
            validSecond = false;
        }
    }
    return clockptr;
}

TwelveHrClock::partOfDayType inputPartOfDay()
{
    int partInt = -1;
    std::string prompt = "Is it \n1. AM\n2. PM\n";
    partInt = inputInt(prompt, "Please enter 1 or 2.", isAorB, 1, 2);
    return TwelveHrClock::parts[partInt - 1];
}

int inputClockType()
{

    int timeInt = inputInt("Is the clock 12 hour or 24 hour? ", "Please enter 12 or 24.", isAorB, 12, 24);

    return timeInt;
}