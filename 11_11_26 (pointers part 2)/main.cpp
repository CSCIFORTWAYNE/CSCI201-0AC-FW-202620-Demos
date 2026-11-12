#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <memory>
#include "movieTimes.h"
#include "twelveHrClock.h"

void resetStream();
int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high);
bool isIntInRange(int num, int low, int high);
bool isAorB(int num, int a, int b);
bool isGTX(int num, int x, int = 0);
bool isGTEQX(int num, int x, int = 0);
std::string trim(const std::string &str, const std::string &whitespace);
MovieTimes getMovieFromFile(std::ifstream &in);

/*
Module 3 part b lab:
put together input for 5 movies including their times in a txt file.
submit the txt file to IvyLearn.
movie title
rating (string like R or PG-13)
runtime (int in minutes)
time, time, time, time
movie title2



time format hh:mm:ss AM or hh:mm:ss pm
*/

int main()
{
    std::ifstream in("movies.txt");
    while (!in.eof())
    {
        MovieTimes m = getMovieFromFile(in);
        std::cout << m.toString() << std::endl;
    }

    return 0;
}

int inputInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;
    while (!std::cin || !valid(num, low, high))
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << error << std::endl;
        std::cout << prompt;
        std::cin >> num;
        std::cout << std::endl;
    }
    return num;
}

void resetStream()
{
    std::cin.clear(); // unlocks the doors (clears the error flags from the stream)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool isIntInRange(int num, int low, int high)
{
    return low >= num && num <= high;
}

bool isAorB(int num, int a, int b)
{
    return num == a || num == b;
}

bool isGTX(int num, int x, int)
{
    return num > x;
}

bool isGTEQX(int num, int x, int)
{
    return num >= x;
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
        TwelveHrClock mTime(hour, minute, second, tod);
        movie.addTime(mTime);
    }

    return movie;
}

TwelveHrClock::partOfDayType inputPartOfDay()
{
    std::string ampm;
    std::cout << "Is it AM or PM? ";
    std::cin >> ampm;
    std::transform(ampm.begin(), ampm.end(), ampm.begin(), ::toupper);
    while (ampm != "AM" && ampm != "PM")
    {
        std::cout << "Please enter AM or PM. ";

        std::cin >> ampm;
        std::transform(ampm.begin(), ampm.end(), ampm.begin(), ::toupper);
    }
    if (ampm == "AM")
    {
        return TwelveHrClock::partOfDayType::AM;
    }
    else
    {

        return TwelveHrClock::partOfDayType::PM;
    }
}

int inputHours()
{
    int hour;
    std::cout << "Enter the hour on the clock: ";
    std::cin >> hour;
    std::cout << std::endl;
    while (!std::cin || hour < 0 || hour > 23)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid hour. Please enter a number between 0 and 23." << std::endl;
        std::cout << "Enter the hour on the clock: ";
        std::cin >> hour;
        std::cout << std::endl;
    }
    return hour;
}
int inputMinutesOrSeconds(std::string part)
{
    int time;
    std::cout << "Enter the number of " << part << " on the clock: ";
    std::cin >> time;
    std::cout << std::endl;
    while (!std::cin || time < 0 || time > 59)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid value for the number of " << part << ". Please enter a number between 0 and 59." << std::endl;
        std::cout << "Enter the number of " << part << " on the clock: ";
        std::cin >> time;
        std::cout << std::endl;
    }
    return time;
}
std::shared_ptr<TwelveHrClock> makeClock()
{
    int hour = inputHours();
    int minute = inputMinutesOrSeconds("minutes");
    int seconds = inputMinutesOrSeconds("seconds");
    TwelveHrClock::partOfDayType part = inputPartOfDay();

    std::shared_ptr<TwelveHrClock> newClock = std::make_shared<TwelveHrClock>(hour, minute, seconds, part);
    return newClock;
}
MovieTimes enterMovie()
{
    std::string title;
    std::string rating;
    int runtime;
    std::cout << "Enter the movie title: ";
    std::getline(std::cin >> std::ws, title);
    std::cout << std::endl;

    std::cout << "Enter the runtime in minutes: ";
    std::cin >> runtime;
    std::cout << std::endl;
    while (!std::cin || runtime < 1)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid runtime. Please enter a number greater than 0." << std::endl;
        std::cout << "Enter the runtime in minutes: ";
        std::cin >> runtime;
        std::cout << std::endl;
    }
    std::cout << "Enter the rating: ";
    std::cin >> std::ws;
    std::getline(std::cin, rating);
    std::cout << std::endl;
    MovieTimes theMovie(title, runtime, rating);
    char more = 'y';
    while (more == 'y')
    {
        std::shared_ptr<TwelveHrClock> clock = makeClock();
        theMovie.addTime(*clock);

        std::cout << "Would you like to add another showtime? ";
        std::cin >> more;
        std::cout << std::endl;
        more = tolower(more);
    }

    return theMovie;
}
