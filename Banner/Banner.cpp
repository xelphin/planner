#include "./Banner.h"


Banner::Banner(const std::string title, const std::string description, const std::string location, const int urgency) :
    m_title(title),
    m_description(description)
{
    
}

void Banner::updateTitle(const std::string newTitle)
{
    int newLength = newTitle.length();
    if (newLength<Banner::MIN_TITLE_LENGTH || newLength>Banner::MAX_TITLE_LENGTH) {
        throw InvalidLength(Banner::MIN_TITLE_LENGTH, Banner::MAX_TITLE_LENGTH, newLength);
    }
    m_title = newTitle;
}

std::string Banner::getTitle() const
{
    return m_title;
}

void Banner::updateDescription(const std::string newDescription)
{
    int newLength = newDescription.length();
    if (newLength< Banner::MIN_DESCRIPTION_LENGTH || newLength<Banner::MAX_DESCRIPTION_LENGTH) {
        throw InvalidLength(Banner::MIN_DESCRIPTION_LENGTH, Banner::MAX_DESCRIPTION_LENGTH, newLength);
    }
    m_description = newDescription;
}

std::string Banner::getDescription() const
{
    return m_description;
}

void Banner::updateLocation(const std::string newLocation)
{
    int newLength = newLocation.length();
    if (newLength<Banner::MIN_BANNER_EVENT_LOCATION_LENGTH || newLength>Banner::MAX_BANNER_EVENT_LOCATION_LENGTH) {
        throw InvalidLength(Banner::MIN_BANNER_EVENT_LOCATION_LENGTH, Banner::MAX_BANNER_EVENT_LOCATION_LENGTH, newLength);
    }
    m_location = newLocation;
}

std::string Banner::getLocation() const
{
    return m_location;
}

void Banner::updateUrgency(const int newUrgency)
{
    if ((newUrgency<Banner::MIN_URGENCY || newUrgency>Banner::MAX_URGENCY) && newUrgency!=Banner::UNDEFINED_URGENCY ) {
        throw InvalidLength(Banner::MIN_URGENCY, Banner::MAX_URGENCY, newUrgency);
    }
    m_urgency = newUrgency;
}

int Banner::getUrgency() const
{
    return m_urgency;
}

std::string Banner::getBannerParsed() const
{
    std::string str = "[";
    str += "\"" + this->getTitle() + "\"";
    str += ",";
    str += "\"" + this->getLocation() + "\"";
    str += ",";
    str += "\"" + std::to_string(this->getUrgency()) + "\"";
    str += ",";
    str += "\"" + this->getDescription() + "\"";
    str += "]";
    return str;
}