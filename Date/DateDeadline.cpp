#include "./DateDeadline.h"

DateDeadline::DateDeadline(const int year, const int month, const int day, const int minutes) :
    Date(year,month,day),
    m_minutes(minutes)
{
    if(!checkValidTime(minutes))
        throw InvalidDate();
}

void DateDeadline::updateDate(const int newMonth, const int newDay, const int newDeadline)
{
    this->Date::updateDate(newMonth, newDay);
    if(!checkValidTime(newDeadline))
        throw InvalidDate();
    m_minutes = newDeadline;
}

bool operator==(const DateDeadline& d1, const DateDeadline& d2)
{
    return (d1.m_month == d2.m_month && d1.m_day == d2.m_day && d1.m_minutes == d2.m_minutes);   
}

bool DateDeadline::operator!=(const DateDeadline& other) const
{
  return !(other == *this);
}

bool operator<(const DateDeadline& d1, const DateDeadline& d2)
{
    if ((Date)d1<(Date)d2)
        return true;
    if((Date)d1>(Date)d2)
        return false;
    if (d1.m_minutes<d2.m_minutes)
        return true;
    return false;
}

bool DateDeadline::operator>(const DateDeadline& other) const
{
  return (!(*this < other) && !(*this == other)) ;
}

bool DateDeadline::operator<=(const DateDeadline& other) const
{
  return !(*this > other);
}

bool DateDeadline::operator>=(const DateDeadline& other) const
{
  return !(*this < other);
}