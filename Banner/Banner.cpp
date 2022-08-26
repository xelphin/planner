#include "./Banner.h"


Banner::Banner(const std::string title, const std::string description) :
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