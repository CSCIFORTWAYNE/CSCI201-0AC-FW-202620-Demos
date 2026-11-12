#include "movieTimes.h"

MovieTimes::MovieTimes(std::string title, int runtime, std::string rating)
{
    this->title = title;
    this->runtime = runtime;
    this->rating = rating;
}

std::string MovieTimes::toString() const
{
    return std::string();
}

std::string MovieTimes::getTitle() const
{
    return this->title;
}

int MovieTimes::getRuntime() const
{
    return this->runtime;
}

std::string MovieTimes::getRating() const
{
    return this->rating;
}
