#include "./BannerTask.h"

BannerTask::BannerTask(const std::string title, const int urgency,  const std::string description) :
    Banner(title, description),
    m_urgency(urgency)
{}

void BannerTask::updateUrgency(const int newUrgency)
{
    if ((newUrgency<BannerTask::MIN_URGENCY || newUrgency>BannerTask::MAX_URGENCY) && newUrgency!=BannerTask::UNDEFINED_URGENCY ) {
        throw InvalidLength(BannerTask::MIN_URGENCY, BannerTask::MAX_URGENCY, newUrgency);
    }
    m_urgency = newUrgency;
}

int BannerTask::getUrgency() const
{
    return m_urgency;
}

std::string BannerTask::getBannerParsed() const
{
    std::string str = "[";
    str += "\"" + this->getTitle() + "\"";
    str += ",";
    str += std::to_string(this->getUrgency());
    str += ",";
    str += "\"" + this->getDescription() + "\"";
    str += "]";
    return str;
}