#include "./Point.h"


Point::Point(const std::string title, const int year, const int month, const int day,
    const bool repeat, const std::string repeatArray,  const int amountRepetitions,
    const std::string description) :
    m_title(title),
    m_year(year),
    m_date(std::make_unique<Date>(year, month, day)),
    m_repeat(repeat),
    m_amountRepetitions(amountRepetitions),
    m_description(description)
{

}

Point::Point(const std::string title, const int year, const int month, const int day,
    const int deadline, const bool repeat, const std::string repeatArray,
    const int amountRepetitions, const std::string description) :
    m_title(title),
    m_year(year),
    m_date(std::make_unique<DateDeadline>(year, month, day, deadline)),
    m_repeat(repeat),
    m_amountRepetitions(amountRepetitions),
    m_description(description)
{

}

Point::Point(const std::string title, const int year, const int month, const int day,
    const int startTime,  const int endTime,
    const bool repeat, const std::string repeatArray, const int amountRepetitions,
    const std::string description) :
    m_title(title),
    m_year(year),
    m_date(std::make_unique<DateRange>(year, month, day, startTime, endTime)),
    m_repeat(repeat),
    m_amountRepetitions(amountRepetitions),
    m_description(description)
{

}

void Point::updateTitle(const std::string newTitle)
{
    int newLength = newTitle.length();
    if (newLength<Point::MIN_TITLE_LENGTH || newLength<Point::MAX_TITLE_LENGTH) {
        throw InvalidLength(Point::MIN_TITLE_LENGTH, Point::MAX_TITLE_LENGTH, newLength);
    }
    m_title = newTitle;
}

void Point::updateDescription(const std::string newDescription)
{
    int newLength = newDescription.length();
    if (newLength< Point::MIN_DESCRIPTION_LENGTH || newLength<Point::MAX_DESCRIPTION_LENGTH) {
        throw InvalidLength(Point::MIN_DESCRIPTION_LENGTH, Point::MAX_DESCRIPTION_LENGTH, newLength);
    }
    m_description = newDescription;
}