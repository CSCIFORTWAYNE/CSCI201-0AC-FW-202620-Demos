#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <random>
#include "twentyfourHrClock.h"

int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool isIntInRange(int num, int low, int high);
bool isAorB(int num, int a, int b);
bool isGTX(int num, int low, int high = 0);
void resetStream();

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
        TwentyFourHrClock newclock(distribution(generator), distribution(generator), distribution(generator));
        std::cout << newclock << std::endl;
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