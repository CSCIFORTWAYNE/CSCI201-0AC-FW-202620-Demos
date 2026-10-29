#include "clock.h"

Clock::Clock(int hour, int minute, int second)
{
    setTime(hour, minute, second);
}

void Clock::setTime(int hour, int minute, int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

void Clock::getTime(int &hour, int &minute, int &second) const
{
    hour = hr;
    minute = min;
    second = sec;
}

std::string Clock::printTime() const
{
    // output hh:mm:ss ex 09:03:02
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
    return out.str();
}

void Clock::incrementSeconds()
{
    sec++;
    if (sec == 60)
    {
        sec = 0;
        incrementMinutes();
    }
}

void Clock::incrementMinutes()
{
    min++;
    if (min == 60)
    {
        min = 0;
        incrementHours();
    }
}

void Clock::incrementHours()
{
    hr++ % 24;
}

void Clock::setHour(int hour)
{
    if (hour < 0 || hour > 23)
    {
        hour = abs(hour) % 24;
    }
    hr = hour;
}

void Clock::setMinute(int minute)
{
    if (minute < 0 || minute > 59)
    {
        minute = abs(minute) % 60;
    }
    min = minute;
}

void Clock::setSecond(int second)
{
    if (second < 0 || second > 59)
    {
        second = abs(second) % 60;
    }
    sec = second;
}

bool Clock::equalTime(const Clock &otherClock) const
{

    return hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec;
}
