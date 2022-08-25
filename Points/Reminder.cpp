#include "./Reminder.h"

Reminder::Reminder(const std::string title, const int year, const int month, const int day,
    const int deadline, const bool repeat, const std::string repeatArray, 
    const int repeatAmount, const std::string description) :
    Point(title, year, repeat, repeatArray, repeatAmount, description),
    m_date(std::make_unique<DateDeadline>(year, month, day, deadline))
{}

void Reminder::updateDate(const int newMonth, const int newDay, const int newDeadline, const int arg2)
{
    if (newDeadline == Point::EMPTY_ARG)
        throw InvalidDate();
    (*m_date).updateDate(newMonth, newDay, newDeadline);
}

void Reminder::addRepeat(const int times[])
{
    try {
        m_repetitions.push_back(std::make_unique<DateDeadline>(m_year, times[0], times[1], times[2]));
    } catch(...) {
        throw InvalidFormatOfRepetitionArray();
    }
}