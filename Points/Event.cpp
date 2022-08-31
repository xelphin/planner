#include "./Event.h"

Event::Event(std::shared_ptr<BannerEvent> banner, const int year, const int month, const int day,
    const int timeStart, const int timeEnd) :
    Point(year),
    m_date(std::make_unique<DateRange>(year, month, day, timeStart, timeEnd)),
    m_banner(move(banner))
{}

void Event::updateTitle(const std::string newTitle)
{
    (*m_banner).updateTitle(newTitle);
}

std::string Event::getTitle() const
{
    return (*m_banner).getTitle();
}

void Event::updateDescription(const std::string newDescription)
{
    (*m_banner).updateDescription(newDescription);
}

std::string Event::getDescription() const
{
    return (*m_banner).getDescription();
}

void Event::updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd)
{
    if (newStart == Point::EMPTY_ARG || newEnd == Point::EMPTY_ARG)
        throw InvalidDate();
    (*m_date).updateDate(newMonth, newDay, newStart, newEnd);
}

DateAbstract* Event::getDate() const
{
    return m_date.get();
}

void Event::updateLocation(const std::string newLocation)
{
    (*m_banner).updateLocation(newLocation);
}

std::string Event::getLocation() const
{
    return (*m_banner).getLocation();
}

std::ostream& Event::print(std::ostream& os) const
{
    os << " ◉  ";
    os << this->getTitle() << std::endl;
    os << "    " << *(this->getDate());
    os << std::endl;
    return os;
}