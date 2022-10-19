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

std::ostream& Task::print(std::ostream& os) const
{
    int day = (*(this->getDate())).getDay();
    int deadline = (*(this->getDate())).getTime();
    os << " " << day;
    this->addSpaceAfterDay(day) == true ? os << " " : os << "";
    if(!(this->getComplete())) {
        os << "  ◻  ";
    } else {
        os << "  ☑  ";
    }
    os << this->getTitle();
    os << " : " << minutesToTime(deadline) << std::endl;
    os << "        " << this->textStart(this->getDescription(), DESCRIPTION_START_LENGTH) << std::endl;
    os << std::endl;
    return os;
}