#include <iostream>
#include <vector>
#include <map>
#include "twentyfourHrClock.h"
#include "arrayList.h"

/* int max(int x, int y);
double max(double x, double y);
long max(long x, long y);
short max(short x, short y);
float max(float x, float y); */
template <class t>
t max(t x, t y);

// Module 5 part A lab
// Add the numeric char (1-9) to hexValues.
// use insert at least once and [] at least once

int main()
{
    std::map<char, int> hexValues; // A = 10, a = 10
    hexValues['A'] = 10;
    hexValues['B'] = 11;
    hexValues['C'] = 12;
    hexValues['D'] = 13;
    hexValues['E'] = 14;
    hexValues['F'] = 15;
    std::pair<std::map<char, int>::iterator, bool> p;
    p = hexValues.insert(std::pair<char, int>('H', 11));
    if (!p.second)
    {
        std::cout << "Unable to insert 'A' with a value of 11." << std::endl;
        std::cout << hexValues['A'] << std::endl;
    }

    int one = max(3, 4);
    long two = max(3L, 4L);
    short three = max(3, 4);
    float four = max(3.0f, 4.0f);
    double five = max(3.0, 4.0);
    TwentyFourHrClock midnight(0, 0, 0);
    std::vector<TwentyFourHrClock> clocks(100, midnight);
    std::vector<TwentyFourHrClock>::iterator clockIt;
    auto clockIt2 = clocks.begin();
    for (clockIt = clocks.begin(); clockIt != clocks.end(); ++clockIt)
    {
        std::cout << *clockIt << std::endl;
    }
    ArrayListType<int> nums;
    nums.insert(3);
    nums.insert(7);
    nums.insert(4);
    nums.insert(2);
    nums.insert(8);
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << std::endl;
    }
    std::cout << std::endl;
    nums.remove(4);
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << std::endl;
    }

    return 0;
}

/* int max(int x, int y)
{
    if (x >= y)
        return x;
    else
        return y;
}

double max(double x, double y)
{
    if (x >= y)
        return x;
    else
        return y;
}

long max(long x, long y)
{
    if (x >= y)
        return x;
    else
        return y;
}

float max(float x, float y)
{
    if (x >= y)
        return x;
    else
        return y;
}

short max(short x, short y)
{
    if (x >= y)
        return x;
    else
        return y;
} */

template <class t>
t max(t x, t y)
{
    if (x >= y)
        return x;
    else
        return y;
}