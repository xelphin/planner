#include "./DateRange.h"

DateRange::DateRange(const int year, const int month, const int day, const int start, const int end) :
    Date(year,month,day),
    m_start(start),
    m_end(end)
{}

void DateRange::updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd)
{
    this->Date::updateDate(newMonth, newDay);
    if(!checkValidTimeRange(newStart,newEnd))
        throw InvalidDate();
    m_start = newStart;
    m_end = newEnd;
}