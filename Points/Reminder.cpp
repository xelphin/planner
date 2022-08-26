#include "./Reminder.h"

Reminder::Reminder(std::shared_ptr<Banner> banner, const int year, const int month, const int day,
    const int deadline) :
    Point(move(banner), year),
    m_date(std::make_unique<DateDeadline>(year, month, day, deadline))
{}

void Reminder::updateDate(const int newMonth, const int newDay, const int newDeadline, const int arg2)
{
    if (newDeadline == Point::EMPTY_ARG)
        throw InvalidDate();
    (*m_date).updateDate(newMonth, newDay, newDeadline);
}

