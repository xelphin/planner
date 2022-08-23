#include "./DateRange.h"

DateRange::DateRange(const int year, const int month, const int day, const int start, const int end) :
    Date(year,month,day),
    m_start(start),
    m_end(end)
{
    if(!checkValidTimeRange(start,end))
        throw InvalidDate();
}

void DateRange::updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd)
{
    this->Date::updateDate(newMonth, newDay);
    if(!checkValidTimeRange(newStart,newEnd))
        throw InvalidDate();
    m_start = newStart;
    m_end = newEnd;
}

bool operator==(const DateRange& d1, const DateRange& d2)
{
    return (d1.m_month == d2.m_month && d1.m_day == d2.m_day && d1.m_start == d2.m_start && d1.m_end == d2.m_end);   
}

bool DateRange::operator!=(const DateRange& other) const
{
  return !(other == *this);
}

bool operator<(const DateRange& d1, const DateRange& d2)
{
    if ((Date)d1<(Date)d2)
        return true;
    if((Date)d1>(Date)d2)
        return false;
    if (d1.m_start<d2.m_start)
        return true;
    return false;
}

bool DateRange::operator>(const DateRange& other) const
{
  return (!(*this < other) && !(*this == other)) ;
}

bool DateRange::operator<=(const DateRange& other) const
{
  return !(*this > other);
}

bool DateRange::operator>=(const DateRange& other) const
{
  return !(*this < other);
}