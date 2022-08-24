#include "./DateAbstract.h"

DateAbstract::DateAbstract(const int year, const int month, const int day) :
    m_year(year),
    m_month(month),
    m_day(day)
{
    if(!validDate(year, month, day))
        throw InvalidDate();
}

void DateAbstract::updateDate(const int newMonth, const int newDay)
{
    if(!validDate(m_year, newMonth, newDay))
        throw InvalidDate();
    m_month = newMonth;
    m_day = newDay;
}

int DateAbstract::getTime() const
{
    return DateAbstract::ALL_DAY;
}

int DateAbstract::getEnd() const
{
    return DateAbstract::ALL_DAY;
}

bool operator==(const DateAbstract& d1, const DateAbstract& d2)
{
    return (d1.m_month == d2.m_month && d1.m_day == d2.m_day && d1.getTime()==d2.getTime() && d1.getEnd()==d2.getEnd()); 
}

bool DateAbstract::operator!=(const DateAbstract& other) const
{
  return !(other == *this);
}

bool operator<(const DateAbstract& d1, const DateAbstract& d2)
{
    if (d1.m_month<d2.m_month)
        return true;
    if(d1.m_month>d2.m_month)
        return false;
    if (d1.m_day<d2.m_day)
        return true;
    if (d1.m_day>d2.m_day)
        return false;
    if (d1.getTime()<d2.getTime())
        return true;
    if (d1.getTime()>d2.getTime())
        return false;
    if (d1.getEnd()<d2.getEnd())
        return true;
    return false;
}

bool DateAbstract::operator>(const DateAbstract& other) const
{
  return (!(*this < other) && !(*this == other)) ;
}

bool DateAbstract::operator<=(const DateAbstract& other) const
{
  return !(*this > other);
}

bool DateAbstract::operator>=(const DateAbstract& other) const
{
  return !(*this < other);
}