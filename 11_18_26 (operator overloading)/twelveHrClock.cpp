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

TwelveHrClock::TwelveHrClock(int hour, int minute, int second, partOfDayType part)
{
    setTime(hour, minute, second, part);
    x = 0;
    y = 0;
    z = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    str = "Hello World!!";
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

void TwelveHrClock::incrementHours()
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

TwelveHrClock::TwelveHrClock(int hour, int minute, int second, std::string partDay)
{
    Clock::setTime(hour, minute, second);
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

Clock *TwelveHrClock::copyClock() const
{
    return new TwelveHrClock(*this);
}

/* void TwelveHrClock::setTime(int hour, int minute, int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
} */

bool TwelveHrClock::operator==(const TwelveHrClock &rightHandClock) const
{
    return this->hr == rightHandClock.hr && this->min == rightHandClock.min && this->sec == rightHandClock.sec && this->partOfDay == rightHandClock.partOfDay;
}

TwelveHrClock TwelveHrClock::operator+(const TwelveHrClock &rightHandClock) const
{
    TwelveHrClock copy(*this);
    for (int i = 0; i < rightHandClock.sec; i++)
    {
        copy.incrementSeconds();
    }
    for (int i = 0; i < rightHandClock.min; i++)
    {
        copy.incrementMinutes();
    }
    for (int i = 0; i < rightHandClock.hr; i++)
    {
        copy.incrementHours();
    }

    return copy;
}
TwelveHrClock::partOfDayType TwelveHrClock::getPartOfDay() const
{
    return partOfDay;
}

std::ostream &operator<<(std::ostream &out, const TwelveHrClock &clock)
{
    out << clock.printTime();
    return out;
}
std::istream &operator>>(std::istream &in, TwelveHrClock &clock)
{
    // TODO: insert return statement here
    int hour;
    int minute;
    int second;
    std::string part;
    in >> hour >> minute >> second;
    in >> part;
    TwelveHrClock c(hour, minute, second, part);
    clock = c;
    return in;
}
TwelveHrClock::partOfDayType TwelveHrClock::parts[2] = {partOfDayType::AM,
                                                        partOfDayType::PM};
std::string TwelveHrClock::partToStr[2] = {"AM", "PM"};

TwelveHrClock TwelveHrClock::operator++()
{
    incrementSeconds();
    return *this;
}

TwelveHrClock TwelveHrClock::operator++(int)
{
    TwelveHrClock copy = *this;
    incrementSeconds();
    return copy;
}