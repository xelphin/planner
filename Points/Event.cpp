#include "./Event.h"

Event::Event(std::shared_ptr<Banner> banner, const int year, const int month, const int day,
    const int timeStart, const int timeEnd) :
    Point(move(banner), year),
    m_date(std::make_unique<DateRange>(year, month, day, timeStart, timeEnd))
{}

void Event::updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd)
{
    if (newStart == Point::EMPTY_ARG || newEnd == Point::EMPTY_ARG)
        throw InvalidDate();
    (*m_date).updateDate(newMonth, newDay, newStart, newEnd);
}