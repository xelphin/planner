#include "./Task.h"

Task::Task(std::shared_ptr<BannerTask> banner, const int year, const int month, const int day,
    const int deadline) :
    Point(year),
    m_date(std::make_unique<DateDeadline>(year, month, day, deadline)),
    m_banner(move(banner))
{}

void Task::updateTitle(const std::string newTitle)
{
    (*m_banner).updateTitle(newTitle);
}

std::string Task::getTitle() const
{
    return (*m_banner).getTitle();
}

void Task::updateDescription(const std::string newDescription)
{
    (*m_banner).updateDescription(newDescription);
}

std::string Task::getDescription() const
{
    return (*m_banner).getDescription();
}

void Task::updateDate(const int newMonth, const int newDay, const int newDeadline, const int arg2)
{
    if (newDeadline == Point::EMPTY_ARG)
        throw InvalidDate();
    (*m_date).updateDate(newMonth, newDay, newDeadline);
}

DateAbstract* Task::getDate() const
{
    return m_date.get();
}

void Task::updateUrgency(const int newUrgency)
{
    (*m_banner).updateUrgency(newUrgency);
}

int Task::getUrgency() const
{
    return (*m_banner).getUrgency();
}