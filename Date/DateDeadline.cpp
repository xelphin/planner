#include "./DateDeadline.h"

DateDeadline::DateDeadline(const int year, const int month, const int day, const int minutes) :
    Date(year,month,day),
    m_minutes(minutes)
{}

void DateDeadline::updateDate(const int newMonth, const int newDay, const int newDeadline)
{
    this->Date::updateDate(newMonth, newDay);
    if(!checkValidTime(newDeadline))
        throw InvalidDate();
    m_minutes = newDeadline;
}