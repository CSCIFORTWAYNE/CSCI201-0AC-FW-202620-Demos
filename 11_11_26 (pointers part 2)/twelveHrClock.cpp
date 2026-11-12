#include "twelveHrClock.h"

std::string TwelveHrClock::printTime() const
{
    std::string out = Clock::printTime() + " ";
    for (int i = 0; i < 2; i++)
    {
        if (partOfDay == parts[i])
        {
            out += partToStr[i];
        }
    }
    return out;
}

TwelveHrClock::TwelveHrClock(int hour, int minute, int second, partOfDayType part) : Clock(hour, minute, second)
{
    setTime(hour, minute, second, part);
}
/* TwelveHrClock::TwelveHrClock() : Clock(0, 0, 0)
{
} */
void TwelveHrClock::setTime(int hour, int minute, int second, partOfDayType part)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
    partOfDay = part;
}

void TwelveHrClock::incrementHour()
{
    hr++;
    if (hr == 12)
    {
        if (partOfDay == partOfDayType::AM)
        {
            partOfDay = partOfDayType::PM;
        }
        else
        {
            partOfDay = partOfDayType::AM;
        }
    }
    if (hr > 12)
    {
        hr = hr % 12 + 1;
    }
}

void TwelveHrClock::setHour(int hour)
{
    if (hour < 1 || hour > 12)
    {
        hour = abs(hour) % 12 + 1;
    }
    hr = hour;
}

TwelveHrClock::TwelveHrClock(int hour, int minute, int second, std::string partDay) : Clock(hour, minute, second)
{
    setHour(hour);
    bool part = false;
    std::transform(partDay.begin(), partDay.end(), partDay.begin(), ::toupper);

    for (int i = 0; i < 2; i++)
    {
        if (partDay == partToStr[i])
        {
            this->partOfDay = parts[i];
            part = true;
        }
    }
    if (!part)
    {
        this->partOfDay = partOfDayType::AM;
    }
}

TwelveHrClock::partOfDayType TwelveHrClock::parts[2] = {partOfDayType::AM,
                                                        partOfDayType::PM};
std::string TwelveHrClock::partToStr[2] = {"AM", "PM"};