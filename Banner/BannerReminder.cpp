#include "./BannerReminder.h"

BannerReminder::BannerReminder(const std::string title, const std::string location, const std::string description) :
    Banner(title, description),
    m_location(location)
{}

void BannerReminder::updateLocation(const std::string newLocation)
{
    int newLength = newLocation.length();
    if (newLength<BannerReminder::MIN_BANNER_REMINDER_LOCATION_LENGTH || newLength>BannerReminder::MAX_BANNER_REMINDER_LOCATION_LENGTH) {
        throw InvalidLength(BannerReminder::MIN_BANNER_REMINDER_LOCATION_LENGTH, BannerReminder::MAX_BANNER_REMINDER_LOCATION_LENGTH, newLength);
    }
    m_location = newLocation;
}

std::string BannerReminder::getLocation() const
{
    return m_location;
}