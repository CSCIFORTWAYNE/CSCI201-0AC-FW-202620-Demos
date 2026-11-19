#ifndef CLOCK_H
#define CLOCK_H
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

class Clock
{
public:
    // Clock(int hour, int minute, int second);
    void setTime(int hour, int minute, int second);
    void getTime(int &hour, int &minute, int &second) const;
    virtual std::string printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    virtual void incrementHours() = 0;
    // precondition: new hour in the proper range 0-23
    // postcondition: hr is set to the new hour
    virtual void setHour(int hour) = 0;
    void setMinute(int minute);
    void setSecond(int second);
    bool equalTime(const Clock &otherClock) const;
    virtual ~Clock() {};
    virtual Clock *copyClock() const = 0;

protected:
    int hr;
    int min;
    int sec;
};
#endif