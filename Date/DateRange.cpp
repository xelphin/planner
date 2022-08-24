#include "./DateRange.h"

DateRange::DateRange(const int year, const int month, const int day, const int start, const int end) :
    DateAbstract(year,month,day),
    m_start(start),
    m_end(end)
{
    if(!checkValidTimeRange(start,end))
        throw InvalidDate();
}

void DateRange::updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd)
{
    this->DateAbstract::updateDate(newMonth, newDay);
    if(!checkValidTimeRange(newStart,newEnd))
        throw InvalidDate();
    m_start = newStart;
    m_end = newEnd;
}

int DateRange::getTime() const
{
    return m_start;
}

int DateRange::getEnd() const
{
    return m_end;
}