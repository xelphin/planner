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

int Task::getMonth() const
{
    return (*m_date).getMonth();
}

int Task::getDay() const
{
    return (*m_date).getDay();
}

void Task::updateUrgency(const int newUrgency)
{
    (*m_banner).updateUrgency(newUrgency);
}

int Task::getUrgency() const
{
    return (*m_banner).getUrgency();
}


void Task::markComplete()
{
    m_complete = true;
}

void Task::markIncomplete()
{
    m_complete = false;
}

bool Task::getComplete() const
{
    return m_complete;
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