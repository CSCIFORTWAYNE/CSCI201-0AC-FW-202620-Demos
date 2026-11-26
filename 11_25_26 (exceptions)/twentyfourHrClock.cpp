#include "twentyfourHrClock.h"

void TwentyFourHrClock::incrementHours()
{
    hr++ % 24;
}

void TwentyFourHrClock::setHour(int hour)
{
    if (hour < 0 || hour > 23)
    {
        throw Invalid_Hour(hour, 0, 23);
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
TwentyFourHrClock::TwentyFourHrClock(const TwelveHrClock &clockToConvert)
{
    int hour;
    int minute;
    int second;
    clockToConvert.getTime(hour, minute, second);
    TwelveHrClock::partOfDayType part = clockToConvert.getPartOfDay();
    if (hour == 12)
    {
        hour = 0;
    }
    if (part == TwelveHrClock::partOfDayType::PM)
    {
        hour = hour + 12;
    }
    hr = hour;
    min = minute;
    sec = second;
}

TwentyFourHrClock TwentyFourHrClock::operator+(int minutesToAdd)
{
    TwentyFourHrClock copy = *this;
    for (int i = 0; i < minutesToAdd; i++)
    {
        copy.incrementMinutes();
    }
    return copy;
}

bool operator==(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock)
{
    return leftHandClock.hr == rightHandClock.hr && leftHandClock.min == rightHandClock.min && leftHandClock.sec == rightHandClock.sec;
}

bool operator!=(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock)
{
    return !(leftHandClock == rightHandClock);
}
bool operator<(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock)
{
    bool lessThan = true;
    if (rightHandClock.hr < leftHandClock.hr)
    {
        lessThan = false;
    }
    else if (rightHandClock.hr == leftHandClock.hr)
    {
        if (rightHandClock.min < leftHandClock.min)
        {
            lessThan = false;
        }
        else if (rightHandClock.min == leftHandClock.min)
        {
            if (rightHandClock.sec <= leftHandClock.sec)
            {
                lessThan = false;
            }
        }
    }
    return lessThan;
}
bool operator>(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock)
{
    bool greaterThan = true;
    if (rightHandClock.hr > leftHandClock.hr)
    {
        greaterThan = false;
    }
    else if (rightHandClock.hr == leftHandClock.hr)
    {
        if (rightHandClock.min > leftHandClock.min)
        {
            greaterThan = false;
        }
        else if (rightHandClock.min == leftHandClock.min)
        {
            if (rightHandClock.sec >= leftHandClock.sec)
            {
                greaterThan = false;
            }
        }
    }
    return greaterThan;
}
bool operator<=(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock)
{
    return leftHandClock < rightHandClock || leftHandClock == rightHandClock;
}
bool operator>=(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock)
{
    return leftHandClock > rightHandClock || leftHandClock == rightHandClock;
}

TwentyFourHrClock operator+(int minutesToAdd, TwentyFourHrClock c)
{
    return c + minutesToAdd;
}
