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

std::string Reminder::printInfo_editingFormat(int& maxAvailable, pointsInfo::TYPE& pointType) const 
{
  std::string text ="";
  text += Point::printInfo_editingFormat(maxAvailable, pointType);

  pointType = pointsInfo::TYPE::REMINDER;
  return text;
}

pointsInfo::EDIT Reminder::getAttribute_editingFormat(const int index) const
{
    pointsInfo::EDIT typeFromBase = Point::getAttribute_editingFormat(index);
    
    return typeFromBase;

}

std::ostream& Reminder::print(std::ostream& os) const
{
    os << this -> printToString(false);
    return os;
}

std::string Reminder::printToString(const bool withArrow) const
{
    std::string text = "";
    int day = (*(this->getDate())).getDay();
    text += " " + std::to_string(day);
    this->addSpaceAfterDay(day) == true ? text += " " : text += "";
    text += "  ❕ " + this->getTitle();
    withArrow ? text += "   <-\n" : text += "\n";
    text += "        " + this->textStart(this->getDescription(), DESCRIPTION_START_LENGTH) + "\n";
    text += "\n";
    return text;
}