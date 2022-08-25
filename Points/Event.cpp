#include "./Event.h"

Event::Event(const std::string title, const int year, const int month, const int day,
    const int timeStart, const int timeEnd, const bool repeat, const std::string repeatArray, 
    const int repeatAmount, const std::string description) :
    Point(title, year, repeat, repeatArray, repeatAmount, description),
    m_date(std::make_unique<DateRange>(year, month, day, timeStart, timeEnd))
{}

void Event::updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd)
{
    if (newStart == Point::EMPTY_ARG || newEnd == Point::EMPTY_ARG)
        throw InvalidDate();
    (*m_date).updateDate(newMonth, newDay, newStart, newEnd);
}

void Event::addRepeat(const int times[])
{
    try {
        m_repetitions.push_back(std::make_unique<DateRange>(m_year, times[0], times[1], times[2], times[3]));
    } catch(...) {
        throw InvalidFormatOfRepetitionArray();
    }
}