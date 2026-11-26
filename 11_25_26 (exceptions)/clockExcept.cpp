#include "clockExcept.h"

Invalid_Hour::Invalid_Hour() : invalid_argument("The hour given is invalid.")
{
    hour = -1;
    low = -1;
    high = -1;
}

Invalid_Hour::Invalid_Hour(int hour, int low, int high) : invalid_argument("The hour (" + std::to_string(hour) + ") is invalid. Expected range: " + std::to_string(low) + " - " + std::to_string(high))
{
    this->hour = hour;
    this->low = low;
    this->high = high;
}

int Invalid_Hour::getHour() const
{
    return hour;
}

void Invalid_Hour::getHourRange(int &low, int &high) const
{
    low = this->low;
    high = this->high;
}
