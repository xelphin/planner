#include "./Date.h"

Date::Date(const int year, const int month, const int day) :
    DateAbstract(year, month, day)
{}

std::string Date::parseToText() const
{
    std::string text = "[";
    text += std::to_string(m_month) + ", ";
    text += std::to_string(m_day) + "]";
    return text;
}