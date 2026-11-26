#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <random>
#include "twentyfourHrClock.h"
#include "twelveHrClock.h"
#include "inputExcept.h"

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
    int num = 100;
    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;
    if (!std::cin)
    {
        throw Input_Exception();
    }
    if (!valid(num, low, high))
    {
        throw Input_Exception(error, false);
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
    int hour = 100;
    int minute = 100;
    int second = 100;
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
            catch (Input_Exception e)
            {
                std::cout << e.what() << std::endl;
                if (e.hasStreamReset())
                {
                    resetStream();
                    e.setStreamReset(false);
                }
                validHour = false;
                continue;
            }
            validHour = true;
        }
        if (!validMinute)
        {
            try
            {
                minute = inputInt(minPrompt, "Please enter a minute between 0 and 59", isIntInRange, 0, 59);
            }
            catch (Input_Exception e)
            {
                std::cout << e.what() << std::endl;
                if (e.hasStreamReset())
                {
                    resetStream();
                    e.setStreamReset(false);
                }
                validMinute = false;
                continue;
            }
            validMinute = true;
        }
        if (!validSecond)
        {
            try
            {
                second = inputInt(secPrompt, "Please enter a second between 0 and 59", isIntInRange, 0, 59);
            }
            catch (Input_Exception e)
            {
                std::cout << e.what() << std::endl;
                if (e.hasStreamReset())
                {
                    resetStream();
                    e.setStreamReset(false);
                }
                validSecond = false;
                continue;
            }
            validSecond = true;
        }
        TwelveHrClock::partOfDayType part;
        try
        {
            if (type == 12)
            {
                if (!validAM)
                {
                    part = inputPartOfDay();
                    validAM = true;
                }
                clockptr = new TwelveHrClock(hour, minute, second, part);
            }
            else
            {
                clockptr = new TwentyFourHrClock(hour, minute, second);
            }
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
        catch (Invalid_Minute e)
        {
            std::cout << e.what() << std::endl;
            validMinute = false;
        }
        catch (Invalid_Second e)
        {
            std::cout << e.what() << std::endl;
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