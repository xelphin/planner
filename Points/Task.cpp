#include "./Task.h"

Task::Task(const std::string title, const int year, const int month, const int day,
    const bool repeat, const std::string repeatArray, 
    const int repeatAmount, const std::string description) :
    Point(title, year, repeat, repeatArray, repeatAmount, description),
    m_date(std::make_unique<Date>(year, month, day))
{}

void Task::updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd)
{
    (*m_date).updateDate(newMonth, newDay);
}

void Task::addRepeat(const int times[])
{
    try {
        m_repetitions.push_back(std::make_unique<Date>(m_year, times[0], times[1]));
    } catch(...) {
        throw InvalidFormatOfRepetitionArray();
    }
}