#include "./graphic_bannerEdit.h"

void graphics_edit::mainBannerEditor(Calendar &calendar)
{
    // GET WANTED EDIT
    pointsInfo::TYPE pointType = pointsInfo::TYPE::INVALID;
    pointsInfo::EDIT attr = graphics_edit::idleReadIndex(calendar,pointType);
    if (attr == pointsInfo::EDIT::OUT_OF_RANGE) {
        return;
    }
    system("clear");

    // REDIRECT FOR EDIT
    graphics_edit::editRedirection(calendar, attr, pointType);

    // EXIT
    std::cout << "Press a letter and then ENTER to exit\n";
    std::string tmp;
    std::cin >> tmp; // wait for key press to exit
}

pointsInfo::EDIT graphics_edit::idleReadIndex(Calendar &calendar, pointsInfo::TYPE& pointType)
{
    system("clear");
    std::string userInput = "";
    std::string err = "";
    int maxAvailable = 0;
    std::string attributeStr = ( *(calendar.getSelectedPoint()) ).printInfo_editingFormat(maxAvailable, pointType);

    // PRINT ACTION BAR
    std::cout << graphics::calendarTitle() << std::endl;
    std::cout << graphics::pointEditorString() << std::endl;
    std::cout << graphics::promptIndexOfAttribute(maxAvailable) << std::endl;
    std::cout << attributeStr;
    
    // GET INPUT
    std::cin >> userInput;
    userInput = trim(userInput);

    // RETURN ATTRIBUTE REQUESTED
    bool isNum = graphics_checks::isNumber(userInput, err); // non-negative whole number
    if (isNum && userInput.length() > 0) {
        int index = std::stoi(userInput);
        if (index >=0 || index <= maxAvailable) {
            return ( *(calendar.getSelectedPoint()) ).getAttribute_editingFormat(index);
        }
    }

    return pointsInfo::EDIT::OUT_OF_RANGE;
}


bool graphics_edit::editRedirection(Calendar &calendar, const pointsInfo::EDIT editType, const pointsInfo::TYPE pointType)
{
    std::string versionStr = "";
    std::string newStr = "";
    std::string pointTypeStr = Point::pointTypeToString(pointType);
    std::shared_ptr<Point> point = (calendar.getSelectedPoint());

    // DOWNCAST
    std::shared_ptr<Event> event;
    std::shared_ptr<Task> task;
    std::shared_ptr<Reminder> reminder;

    switch (pointType) 
    {
        case pointsInfo::TYPE::EVENT:
            event = std::dynamic_pointer_cast<Event>(point);
            if (!event) {
                return false;
            }
            break;
        case pointsInfo::TYPE::TASK:
            task = std::dynamic_pointer_cast<Task>(point);
            if (!task) {
                return false;
            }
            break;
        case pointsInfo::TYPE::REMINDER:
            reminder = std::dynamic_pointer_cast<Reminder>(point);
            if (!reminder) {
                return false;
            }
            break;
        default:
            return false;
    }


    // APLLY EDIT
    switch (editType)
    {
    case (pointsInfo::EDIT::REPETITION):
        graphics_helper::queryForRepetitions(calendar, graphics_edit::pointTypeToBanner(pointType));
        break;
    case (pointsInfo::EDIT::TITLE):
        versionStr = graphics::strCurrentVersion("Title", point->getTitle());
        graphics_helper::idleReadString(&graphics::promptPointTitle, &graphics_checks::validText, newStr, pointTypeStr, false, versionStr, true);
        point->updateTitle(newStr);
        break;
    case (pointsInfo::EDIT::DESCRIPTION):
        versionStr = graphics::strCurrentVersion("Description", point->getDescription());
        graphics_helper::idleReadString(&graphics::promptPointDescription, &graphics_checks::validText, newStr, pointTypeStr, true, versionStr, true);
        point->updateDescription(newStr);
        break;
    case (pointsInfo::EDIT::LOCATION):
        versionStr = graphics::strCurrentVersion("Location", point->getLocation());
        graphics_helper::idleReadString(&graphics::promptPointLocation, &graphics_checks::validText, newStr, pointTypeStr, true, versionStr, true);
        point->updateLocation(newStr);
        break;
    case (pointsInfo::EDIT::URGENCY):
        versionStr = graphics::strCurrentVersion("Urgency", std::to_string(point->getUrgency()));
        graphics_helper::idleReadString(&graphics::promptPointUrgency, &graphics_checks::isNumberInRangeUrgency, newStr, pointTypeStr, true, versionStr, true);
        if (newStr.empty())
            newStr = "-1";
        point->updateUrgency(stoi(newStr));
        break;
    default: // Return
        return false;
    }
    return true;
}

// TODO: Just don't have pointsInfo::TYPE and only use instead Banner::TYPE (or vice versa)
Banner::TYPE graphics_edit::pointTypeToBanner(const pointsInfo::TYPE pointType)
{
  switch(pointType) 
  {
    case (pointsInfo::TYPE::EVENT):
        return Banner::TYPE::EVENT;
        break;
    case (pointsInfo::TYPE::TASK):
        return Banner::TYPE::TASK;
        break;
    case (pointsInfo::TYPE::REMINDER):
        return Banner::TYPE::REMINDER;
        break;
    default: // Return
        return Banner::TYPE::INVALID;
  }
}