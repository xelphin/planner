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

int Reminder::getMonth() const
{
    return (*m_date).getMonth();
}

int Reminder::getDay() const
{
    return (*m_date).getDay();
}

std::string Reminder::getBannerParsed() const
{
    return (*m_banner).getBannerParsed();
}

void Reminder::updateLocation(const std::string newLocation)
{
    (*m_banner).updateLocation(newLocation);
}

std::string Reminder::getLocation() const
{
    return (*m_banner).getLocation();
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