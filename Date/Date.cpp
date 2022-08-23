#include "./Date.h"

Date::Date(const int year, const int month, const int day) :
    m_year(year),
    m_month(month),
    m_day(day)
{
    if(!validDate(year, month, day))
        throw InvalidDate();
}

void Date::updateDate(const int newMonth, const int newDay)
{
    if(!validDate(m_year, newMonth, newDay))
        throw InvalidDate();
    m_month = newMonth;
    m_day = newDay;
}

bool operator==(const Date& d1, const Date& d2)
{
    return (d1.m_month == d2.m_month && d1.m_day == d2.m_day);   
}

bool Date::operator!=(const Date& other) const
{
  return !(other == *this);
}

bool operator<(const Date& d1, const Date& d2)
{
    if (d1.m_month<d2.m_month)
        return true;
    if(d1.m_month>d2.m_month)
        return false;
    if (d1.m_day<d2.m_day)
        return true;
    return false;
}

bool Date::operator>(const Date& other) const
{
  return (!(*this < other) && !(*this == other)) ;
}

bool Date::operator<=(const Date& other) const
{
  return !(*this > other);
}

bool Date::operator>=(const Date& other) const
{
  return !(*this < other);
}