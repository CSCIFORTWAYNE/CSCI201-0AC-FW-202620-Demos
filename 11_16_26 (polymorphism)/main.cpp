#include <iostream>
#include <random>
#include <sstream>
#include <fstream>
#include "twelveHrClock.h"
#include "clock.h"
#include "twentyfourHrClock.h"
#include "movieTimes.h"

// Module 4 part A lab -- tell me where you are with your project as of Monday 11/16

void displayClocks(Clock **clocks, int numClocks);
void resetStream();
MovieTimes getMovieFromFile(std::ifstream &in);
std::string trim(const std::string &str, const std::string &whitespace);
// void setClock(Clock c);
int main()
{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distributionHour(1, 12);
    std::uniform_int_distribution<int> distribution24Hour(0, 23);
    std::uniform_int_distribution<int> distributionMS(0, 59);
    std::uniform_int_distribution<int> distributionAPM(0, 1);
    Clock **clocks = new Clock *[10];
    for (int i = 0; i < 10; i++)
    {
        int clockType = distributionAPM(generator);
        if (clockType == 0)
        {
            clocks[i] = new TwelveHrClock(distributionHour(generator), distributionMS(generator), distributionMS(generator), TwelveHrClock::parts[distributionAPM(generator)]);
        }
        else
        {
            clocks[i] = new TwentyFourHrClock(distribution24Hour(generator), distributionMS(generator), distributionMS(generator));
        }
    }
    Clock *c = new TwelveHrClock(12, 12, 12, "AM");
    delete c;
    displayClocks(clocks, 10);
    // setClock(*clocks[0]);
    for (int i = 0; i < 10; i++)
    {
        delete clocks[i];
    }
    delete[] clocks;

    std::ifstream in("movies.txt");
    MovieTimes **movies = new MovieTimes *[100];
    int numMovies = 0;
    while (!in.eof())
    {
        movies[numMovies++] = new MovieTimes(getMovieFromFile(in));
    }
    for (int i = 0; i < numMovies; i++)
    {
        std::cout << movies[i]->toString() << std::endl;
        delete movies[i];
    }
    delete[] movies;

    return 0;
}

void displayClocks(Clock **clocks, int numClocks)
{
    for (int i = 0; i < numClocks; i++)
    {
        std::cout << clocks[i]->printTime() << std::endl;
    }
}

/* void setClock(Clock c) // causes slicing
{
    int x;
    x = 0;
} */

MovieTimes getMovieFromFile(std::ifstream &in)
{
    /*
    movie title
    rating (string like R or PG-13)
    runtime (int in minutes)
    time, time, time, time

    */
    std::string title;
    std::string rating;
    int runtime;
    std::string times;
    std::string token;
    std::string hr;
    std::string min;
    std::string sec;
    std::string tod;
    int hour;
    int minute;
    int second;
    std::getline(in >> std::ws, title);
    std::getline(in, rating);
    in >> runtime;
    MovieTimes movie(title, runtime, rating);
    std::getline(in >> std::ws, times);
    std::istringstream timeSplit(times);
    while (!timeSplit.eof())
    {
        tod = "";
        std::getline(timeSplit, token, ',');
        token = trim(token, " ");
        std::istringstream tokenSplit(token);
        std::getline(tokenSplit, hr, ':');
        hour = stoi(hr);
        getline(tokenSplit, min, ':');
        minute = stoi(min);
        getline(tokenSplit, sec, ' ');
        second = stoi(sec);
        getline(tokenSplit, tod);
        Clock *mTime;
        if (tod != "")
        {
            mTime = new TwelveHrClock(hour, minute, second, tod);
        }
        else
        {
            mTime = new TwentyFourHrClock(hour, minute, second);
        }
        movie.addTime(*mTime);
        delete mTime;
        mTime = nullptr;
    }

    return movie;
}

std::string trim(const std::string &str, const std::string &whitespace)
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

void resetStream()
{
    std::cin.clear(); // unlocks the doors (clears the error flags from the stream)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
