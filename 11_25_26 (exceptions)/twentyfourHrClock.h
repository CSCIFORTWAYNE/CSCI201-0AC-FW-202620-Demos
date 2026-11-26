#ifndef TWENTYFOUR_H
#define TWENTYFOUR_H

#include "clock.h"
#include "twelveHrClock.h"
class TwentyFourHrClock : public Clock
{
public:
    void incrementHours();
    void setHour(int hour);
    Clock *copyClock() const;
    TwentyFourHrClock(int hour, int minute, int second = 0);
    TwentyFourHrClock(const TwelveHrClock &);
    friend bool operator==(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock);
    friend bool operator!=(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock);
    friend bool operator<(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock);
    friend bool operator>(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock);
    friend bool operator<=(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock);
    friend bool operator>=(const TwentyFourHrClock &leftHandClock, const TwentyFourHrClock &rightHandClock);
    TwentyFourHrClock operator+(int minutesToAdd);
    friend TwentyFourHrClock operator+(int minutesToAdd, TwentyFourHrClock c);
};

#endif