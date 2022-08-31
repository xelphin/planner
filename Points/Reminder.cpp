#include "./Reminder.h"

Reminder::Reminder(std::shared_ptr<BannerReminder> banner, const int year, const int month, const int day) :
    Point(year),
    m_date(std::make_unique<Date>(year, month, day)),
    m_banner(move(banner))
{}

void Reminder::updateTitle(const std::string newTitle)
{
    (*m_banner).updateTitle(newTitle);
}

std::string Reminder::getTitle() const
{
    return (*m_banner).getTitle();
}

void Reminder::updateDescription(const std::string newDescription)
{
    (*m_banner).updateDescription(newDescription);
}

std::string Reminder::getDescription() const
{
    return (*m_banner).getDescription();
}

void Reminder::updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd)
{
    (*m_date).updateDate(newMonth, newDay);
}

DateAbstract* Reminder::getDate() const
{
    return m_date.get();
}

void Reminder::updateLocation(const std::string newLocation)
{
    (*m_banner).updateLocation(newLocation);
}

std::string Reminder::getLocation() const
{
    return (*m_banner).getLocation();
}