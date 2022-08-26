#include "./Point.h"


Point::Point(std::shared_ptr<Banner> banner, const int year) :
    m_year(year),
    m_banner(move(banner))
{

}

void Point::updateTitle(const std::string newTitle)
{
    (*m_banner).updateTitle(newTitle);
}

std::string Point::getTitle() const
{
    return (*m_banner).getTitle();
}

void Point::updateDescription(const std::string newDescription)
{
    (*m_banner).updateDescription(newDescription);
}

std::string Point::getDescription() const
{
    return (*m_banner).getDescription();
}