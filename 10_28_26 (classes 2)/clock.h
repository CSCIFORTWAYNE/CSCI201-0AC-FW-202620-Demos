#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

class Clock
{
public:
    Clock(int hour = 0, int minute = 0, int second = 0);
    void setTime(int hour, int minute, int second);
    void getTime(int &hour, int &minute, int &second) const;
    std::string printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    // precondition: new hour in the proper range 0-23
    // postcondition: hr is set to the new hour
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    bool equalTime(const Clock &otherClock) const;

private:
    int hr;
    int min;
    int sec;
};