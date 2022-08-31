#include "./Point.h"


Point::Point(const int year) :
    m_year(year)
{

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