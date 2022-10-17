#include "./Point.h"


Point::Point(const int year, std::shared_ptr<Banner> banner) :
    m_year(year),
    m_bannerInPoint(move(banner))
{

}


void Point::updateTitle(const std::string newTitle)
{
    (*m_bannerInPoint).updateTitle(newTitle);
}

std::string Point::getTitle() const
{
    return (*m_bannerInPoint).getTitle();
}

void Point::updateDescription(const std::string newDescription)
{
    (*m_bannerInPoint).updateDescription(newDescription);
}

std::string Point::getDescription() const
{
    return (*m_bannerInPoint).getDescription();
}




bool operator==(const Point& p1, const Point& p2)
{
    return (*(p1.getDate()) == *(p2.getDate())); 
}

bool Point::operator!=(const Point& other) const
{
  return !(other == *this);
}

bool operator<(const Point& p1, const Point& p2)
{
    return (*(p1.getDate()) < *(p2.getDate())); 
}

bool Point::operator>(const Point& other) const
{
  return (!(*this < other) && !(*this == other)) ;
}

bool Point::operator<=(const Point& other) const
{
  return !(*this > other);
}

bool Point::operator>=(const Point& other) const
{
  return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Point& toPrint)
{
    toPrint.print(os);
    return os;
}

bool Point::addSpaceAfterDay(const int day) const
{
  if (day>0 && day<10)
    return true;
  return false;
}

std::string Point::textStart(const std::string text, const std::string::size_type length) const
{
  if (text.size() <= length)
    return text;
  return text.substr(0,length-1) + "...";
}