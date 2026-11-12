#include "movieTimes.h"

MovieTimes::MovieTimes(std::string title, int runtime, std::string rating)
{
    this->title = title;
    this->runtime = runtime;
    this->rating = rating;
    this->numTimes = 0;
    this->showTimes = nullptr;
}

MovieTimes::MovieTimes(const MovieTimes &movieToCopy)
{
    this->numTimes = 0;
    this->showTimes = nullptr;
    copyMovie(movieToCopy);
}

std::string MovieTimes::toString() const
{
    std::ostringstream out;
    out << std::left;
    out << "| " << std::setw(40) << title << " | " << std::setw(5) << rating << " | " << std::setw(3) << runtime << " mins | ";
    for (int i = 0; i < numTimes; i++)
    {
        out << showTimes[i]->printTime() << " ";
    }
    out << " | ";
    return out.str();
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

void MovieTimes::addTime(TwelveHrClock timeAdd)
{
    TwelveHrClock **temp = showTimes;
    showTimes = new TwelveHrClock *[numTimes + 1];
    for (int i = 0; i < numTimes; i++)
    {
        showTimes[i] = temp[i]; // acceptable shallow copy
    }
    showTimes[numTimes++] = new TwelveHrClock(timeAdd); // numTimes++ numTimes changes after it is used as the index
    delete[] temp;
}

void MovieTimes::clearTimes()
{
    for (int i = 0; i < numTimes; i++)
    {
        delete showTimes[i];
    }
    delete[] showTimes;
    showTimes = nullptr;
    numTimes = 0;
}

MovieTimes::~MovieTimes()
{
    clearTimes();
}

void MovieTimes::copyMovie(const MovieTimes &movieToCopy)
{
    this->title = movieToCopy.title;
    this->rating = movieToCopy.rating;
    this->runtime = movieToCopy.runtime;
    if (numTimes > 0)
    {
        clearTimes();
    }
    this->numTimes = movieToCopy.numTimes;
    showTimes = new TwelveHrClock *[numTimes];
    for (int i = 0; i < numTimes; i++)
    {
        // showTimes[i] = movieToCopy.showTimes[i]; //bad shallow copy
        showTimes[i] = new TwelveHrClock(*(movieToCopy.showTimes[i]));
    }
}
