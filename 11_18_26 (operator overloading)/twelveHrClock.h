#ifndef TWELVE_H
#define TWELVE_H
#include "clock.h"
#include <algorithm>

class TwelveHrClock : public Clock
{
public:
    enum class partOfDayType
    {
        AM,
        PM
    };
    std::string printTime() const;
    TwelveHrClock(int hour, int minute, int second, partOfDayType part);
    TwelveHrClock(int hour, int minute, int second, std::string partDay);
    void setTime(int hour, int minute, int second, partOfDayType part);
    // void setTime(int hour, int minute, int second);
    void incrementHours();
    void setHour(int hour);
    Clock *copyClock() const;
    bool operator==(const TwelveHrClock &rightHandClock) const; // leftHandClock == rightHandClock
    TwelveHrClock operator+(const TwelveHrClock &rightHandClock) const;
    static partOfDayType parts[2];
    static std::string partToStr[2];

private:
    partOfDayType partOfDay;
    int x;
    int y;
    int z;
    int a;
    int b;
    int c;
    int d;
    std::string str;
};
#endif