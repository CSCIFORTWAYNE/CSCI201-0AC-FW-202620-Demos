#include "twentyfourHrClock.h"

void TwentyFourHrClock::incrementHours()
{
    hr++ % 24;
}

void TwentyFourHrClock::setHour(int hour)
{
    if (hour < 0 || hour > 23)
    {
        hour = abs(hour) % 24;
    }
    hr = hour;
}

Clock *TwentyFourHrClock::copyClock() const
{
    return new TwentyFourHrClock(*this);
}

TwentyFourHrClock::TwentyFourHrClock(int hour, int minute, int second)
{
    setTime(hour, minute, second);
}