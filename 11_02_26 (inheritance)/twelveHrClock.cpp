#include "twelveHrClock.h"

std::string TwelveHrClock::printTime() const
{
    std::string out = Clock::printTime();
    return std::string();
}

TwelveHrClock::TwelveHrClock(int hour, int minute, int second, partOfDayType part)
{
}

void TwelveHrClock::setTime(int hour, int minute, int second, partOfDayType part)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
    partOfDay = part;
}

void TwelveHrClock::incrementHour()
{
}

void TwelveHrClock::setHour(int hour)
{
    if (hour < 1 || hour > 12)
    {
        hour = abs(hour) % 12 + 1;
    }
    hr = hour;
}
