#include "./Reminder.h"

Reminder::Reminder(std::shared_ptr<Banner> banner, const int year, const int month, const int day) :
    Point(year, banner),
    m_date(std::make_unique<Date>(year, month, day))
{}

void Reminder::updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd)
{
    (*m_date).updateDate(newMonth, newDay);
}

DateAbstract* Reminder::getDate() const
{
    return m_date.get();
}

std::ostream& Reminder::print(std::ostream& os) const
{
    int day = (*(this->getDate())).getDay();
    os << " " << day;
    this->addSpaceAfterDay(day) == true ? os << " " : os << "";
    os << "  ❕ " << this->getTitle() << std::endl;
    os << "        " << this->textStart(this->getDescription(), DESCRIPTION_START_LENGTH) << std::endl;
    os << std::endl;
    return os;
}