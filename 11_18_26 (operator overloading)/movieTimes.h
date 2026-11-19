#ifndef MOVIE_H
#define MOVIE_H

#include "clock.h"
#include "twelveHrClock.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

class MovieTimes
{
public:
    MovieTimes(std::string title, int runtime, std::string rating);
    MovieTimes(const MovieTimes &movieToCopy);
    std::string toString() const;
    std::string getTitle() const;
    int getRuntime() const;
    std::string getRating() const;
    void addTime(const Clock &timeAdd);
    void clearTimes();
    ~MovieTimes();

private:
    std::string title;
    int runtime;
    std::string rating;
    Clock **showTimes;
    int numTimes;
    void copyMovie(const MovieTimes &movieToCopy);
};

#endif