#ifndef CLOCKE_H
#define CLOCKE_H
#include <stdexcept>

class Invalid_Hour : public std::invalid_argument
{
    public:
    Invalid_Hour();
    Invalid_Hour(int hour, int low, int high);
    int getHour() const;
    void getHourRange(int &low, int &high) const;

    private:
    int hour;
    int low;
    int high;
};


#endif