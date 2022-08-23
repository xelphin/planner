#include "./Date.h"

Date::Date(const int year, const int month, const int day) :
    m_year(year),
    m_month(month),
    m_day(day)
{}

void Date::updateDate(const int newMonth, const int newDay)
{
    if(!validDate(m_year, newMonth, newDay))
        throw InvalidDate();
    m_month = newMonth;
    m_day = newDay;
}