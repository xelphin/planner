#include "./Event.h"

Event::Event(const std::string title, const int year, const int month, const int day,
    const int timeStart, const int timeEnd, const bool repeat, const std::string repeatArray, 
    const int repeatAmount, const std::string description) :
    Point(title, year, month, day, timeStart, timeEnd,  repeat, repeatArray, repeatAmount, description)
{}


void Event::updateDate(const int newMonth, const int newDay)
{
    std::cout << "TODO" << std::endl;
}

void Event::addRepeat(const int times[])
{
    // TODO: Check input
    m_repetitions.push_back(std::make_unique<DateRange>(m_year, times[0], times[1], times[2], times[3]));
}