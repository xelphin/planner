#include "./Task.h"

Task::Task(std::shared_ptr<Banner> banner, const int year, const int month, const int day) :
    Point(move(banner), year),
    m_date(std::make_unique<Date>(year, month, day))
{}

void Task::updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd)
{
    (*m_date).updateDate(newMonth, newDay);
}

DateAbstract* Task::getDate() const
{
    return m_date.get();
}
