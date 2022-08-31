#include "./BannerEvent.h"

BannerEvent::BannerEvent(const std::string title, const std::string location, const std::string description) :
    Banner(title, description),
    m_location(location)
{}

void BannerEvent::updateLocation(const std::string newLocation)
{
    int newLength = newLocation.length();
    if (newLength<BannerEvent::MIN_BANNER_EVENT_LOCATION_LENGTH || newLength>BannerEvent::MAX_BANNER_EVENT_LOCATION_LENGTH) {
        throw InvalidLength(BannerEvent::MIN_BANNER_EVENT_LOCATION_LENGTH, BannerEvent::MAX_BANNER_EVENT_LOCATION_LENGTH, newLength);
    }
    m_location = newLocation;
}

std::string BannerEvent::getLocation() const
{
    return m_location;
}