#include "./Event.h"

Event::Event(std::shared_ptr<Banner> banner, const int year, const int month, const int day,
    const int timeStart, const int timeEnd) :
    Point(year, banner),
    m_date(std::make_unique<DateRange>(year, month, day, timeStart, timeEnd))
{}


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

std::ostream& Event::print(std::ostream& os) const
{
    int day = (*(this->getDate())).getDay();
    int start = (*(this->getDate())).getTime();
    int end = (*(this->getDate())).getEnd();
    os << " " << day;
    this->addSpaceAfterDay(day) == true ? os << " " : os << "";
    os << "  ◉  " << this->getTitle();
    os << " : " << minutesToTime(start) << " - " << minutesToTime(end) << std::endl;
    os << "        " << this->textStart(this->getDescription(), DESCRIPTION_START_LENGTH) << std::endl;
    os << std::endl;
    return os;
}