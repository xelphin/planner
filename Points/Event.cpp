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

std::string Event::printInfo_editingFormat() const 
{
  std::string text ="";
  text += Point::printInfo_editingFormat();

  text += "[6] Time Start: " + minutesToTime( (*(this->getDate())).getTime() )+ "\n";
  text += "[7] Time End: " + minutesToTime( (*(this->getDate())).getEnd() )+ "\n";

  return text;
}

std::ostream& Event::print(std::ostream& os) const
{
    os << this ->printToString(false);
    return os;
}

std::string Event::printToString(const bool withArrow) const
{
    std::string text = "";
    int day = (*(this->getDate())).getDay();
    int start = (*(this->getDate())).getTime();
    int end = (*(this->getDate())).getEnd();
    text += " " + std::to_string(day);
    this->addSpaceAfterDay(day) == true ? text += " " : text += "";
    text += "  ◉  " + this->getTitle();
    text += " : " + minutesToTime(start) + " - " + minutesToTime(end);
    withArrow ? text += "   <-\n" : text += "\n";
    text += "        " + this->textStart(this->getDescription(), DESCRIPTION_START_LENGTH) + "\n";
    text += "\n";
    return text;
}