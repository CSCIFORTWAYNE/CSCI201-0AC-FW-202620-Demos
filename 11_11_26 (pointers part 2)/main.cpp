#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "movieTimes.h"
#include "twelveHrClock.h"

void resetStream();
int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high);
bool isIntInRange(int num, int low, int high);
bool isAorB(int num, int a, int b);
bool isGTX(int num, int x, int = 0);
bool isGTEQX(int num, int x, int = 0);
MovieTimes getMovieFromFile(std::ifstream &in);

/*
Module 3 part b lab:
put together input for 5 movies including their times in a txt file.
submit the txt file to IvyLearn.
movie title
rating (string like R or PG-13)
runtime (int in minutes)
time, time, time, time
movie title2



time format hh:mm:ss AM or hh:mm:ss pm
*/

int main()
{
    return 0;
}

int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;
    while (!std::cin || !valid(num, low, high))
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << error << std::endl;
        std::cout << prompt;
        std::cin >> num;
        std::cout << std::endl;
    }
    return num;
}

void resetStream()
{
    std::cin.clear(); // unlocks the doors (clears the error flags from the stream)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool isIntInRange(int num, int low, int high)
{
    return low >= num && num <= high;
}

bool isAorB(int num, int a, int b)
{
    return num == a || num == b;
}

bool isGTX(int num, int x, int)
{
    return num > x;
}

bool isGTEQX(int num, int x, int)
{
    return num >= x;
}
