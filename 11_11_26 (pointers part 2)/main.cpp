#include <iostream>
#include <limits>
#include <string>

void resetStream();
int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high);
bool isIntInRange(int num, int low, int high);
bool isAorB(int num, int a, int b);
bool isGTX(int num, int x, int = 0);
bool isGTEQX(int num, int x, int = 0);

int main()
{
    int newNum = inputInt("Enter a number greater than 0. ", "That is not a number greater than 0. Please try again.", isGTX, 0, 0);
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
