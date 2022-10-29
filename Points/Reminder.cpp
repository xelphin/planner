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
    os << this -> printToString();
    return os;
}

std::string Reminder::printToString() const
{
    std::string text = "";
    int day = (*(this->getDate())).getDay();
    text += " " + std::to_string(day);
    this->addSpaceAfterDay(day) == true ? text += " " : text += "";
    text += "  ❕ " + this->getTitle() + "\n";
    text += "        " + this->textStart(this->getDescription(), DESCRIPTION_START_LENGTH) + "\n";
    text += "\n";
    return text;
}