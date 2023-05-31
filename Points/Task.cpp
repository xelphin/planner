#include "./Task.h"

Task::Task(std::shared_ptr<Banner> banner, const int year, const int month, const int day,
    const int deadline, const bool completed) :
    Point(year, banner),
    m_date(std::make_unique<DateDeadline>(year, month, day, deadline))
{
    m_complete = completed;
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

std::string Task::printInfo_editingFormat(int& maxAvailable, pointsInfo::TYPE& pointType) const 
{
  std::string text ="";
  text += Point::printInfo_editingFormat(maxAvailable, pointType);

  text += "[6] Deadline: " + minutesToTime( (*(this->getDate())).getTime() ) + "\n";
  std::string completed = this->getComplete() == true ? "true" : "false";
  text += "[7] Completed: " + completed + "\n";

  maxAvailable = 7;
  pointType = pointsInfo::TYPE::TASK;
  return text;
}

pointsInfo::EDIT Task::getAttribute_editingFormat(const int index) const
{
    pointsInfo::EDIT typeFromBase = Point::getAttribute_editingFormat(index);
    if (typeFromBase != pointsInfo::EDIT::OUT_OF_RANGE) {
        return typeFromBase;
    }
    
    switch (index)
    {
    case (6):
        return pointsInfo::EDIT::DEADLINE;
    case (7):
        return pointsInfo::EDIT::COMPLETE;
    default:
        return pointsInfo::EDIT::OUT_OF_RANGE;
    }
}

std::ostream& Task::print(std::ostream& os) const
{
    os << this -> printToString(false);
    return os;
}

std::string Task::printToString(const bool withArrow) const
{
    std::string text = "";
    int day = (*(this->getDate())).getDay();
    int deadline = (*(this->getDate())).getTime();
    text += " " + std::to_string(day);
    this->addSpaceAfterDay(day) == true ? text += " " : text += "";
    if(!(this->getComplete())) {
        text += "  ◻  ";
    } else {
        text += "  ☑  ";
    }
    text += this->getTitle();
    text += " : " + minutesToTime(deadline);
    withArrow ? text += "   <-\n" : text += "\n";
    text += "        " + this->textStart(this->getDescription(), DESCRIPTION_START_LENGTH) + "\n";
    text += "\n";
    return text;
}

std::string Task::parsePointToTextFull() const
{
    std::string baseText = Point::parsePointToTextFull();
    std::string complete_str;
    m_complete ? complete_str = "1" : complete_str = "0";
    std::string fullText = baseText.substr(0, baseText.length() - 1) + ", " + complete_str + "]";
    return fullText;
}

std::string Task::parsePointToText() const
{
    std::string baseText = Point::parsePointToText();
    std::string complete_str;
    m_complete ? complete_str = "1" : complete_str = "0"; // TODO: make helper function
    std::string fullText = baseText.substr(0, baseText.length() - 1) + ", " + complete_str + "]";
    return fullText;
}