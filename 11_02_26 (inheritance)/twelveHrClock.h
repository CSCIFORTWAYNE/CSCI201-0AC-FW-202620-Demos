#ifndef TWELVE_H
#define TWELVE_H
#include "clock.h"

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
    void setTime(int hour, int minute, int second, partOfDayType part);
    void incrementHour();
    void setHour(int hour);
    static partOfDayType parts[2];
    static std::string partToStr[2];

private:
    partOfDayType partOfDay;
};
#endif