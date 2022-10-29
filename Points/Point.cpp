#include "./Point.h"


Point::Point(const int year, std::shared_ptr<Banner> banner) :
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

void Point::updateLocation(const std::string newLocation)
{
    (*m_banner).updateLocation(newLocation);
}

std::string Point::getLocation() const
{
    return (*m_banner).getLocation();
}

void Point::updateUrgency(const int newUrgency)
{
    (*m_banner).updateUrgency(newUrgency);
}

int Point::getUrgency() const
{
    return (*m_banner).getUrgency();
}

void Point::markComplete()
{
    m_complete = true;
}

void Point::markIncomplete()
{
    m_complete = false;
}

bool Point::getComplete() const
{
    return m_complete;
}

std::string Point::getBannerParsed() const
{
    return (*m_banner).getBannerParsed();
}

std::shared_ptr<Banner> Point::getBanner()
{
  return m_banner;
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

std::string Point::parsePointToTextFull() const
{
  std::string fullText = "";
  std::string bannerText = this->getBannerParsed();
  std::string dateText = (*(this->getDate())).parseToText();
  fullText += bannerText.substr(0, bannerText.length() - 1);
  fullText += ", ";
  fullText += dateText.substr(1, dateText.length() - 1);
  return fullText;
}

std::string Point::parsePointToText() const
{
  return (*(this->getDate())).parseToText();
}