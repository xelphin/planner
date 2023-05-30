#include "./graphic_bannerCreator.h"

graphics_banner::ACTION graphics_banner::characterToBannerType(const char& action)
{   
    switch (action) {
        case('e'):
            return graphics_banner::ACTION::EVENT;
        case('r'):
            return graphics_banner::ACTION::REMINDER;
        case('t'):
            return graphics_banner::ACTION::TASK;
        case('x'):
            return graphics_banner::ACTION::RETURN;
        default:
            return graphics_banner::ACTION::NOTHING;
    }
}

bool graphics_banner::mainBannerCreation(Calendar& calendar)
{
    system("clear");
    char type = 'x';
    std::string userInput = "";

    // PRINT ACTION BAR
    std::cout << graphics::calendarTitle() << std::endl;
    std::cout << graphics::promptWhichPointToAdd() << std::endl;
    
    // GET INPUT
    std::cin >> userInput;
    userInput = trim(userInput);

    type = userInput[0];

    // APPLY ACTION
    bool success = graphics_banner::chooseBannerCreation(calendar, type);
    system("clear");
    std::cout << graphics::calendarTitle() << std::endl;
    std::cout << graphics::bannerCompletion(success) << std::endl;
    // TODO: Once completed, query for repetitions
    std::cin >> userInput; // wait for key press to exit

    //
    return false;
}

bool graphics_banner::chooseBannerCreation(Calendar& calendar, const char& action_char)
{
    graphics_banner::ACTION action = graphics_banner::characterToBannerType(action_char);
    if (action == graphics_banner::ACTION::NOTHING) return false;

    // TODO: No need for switch case I think
    switch (action) {
        case(graphics_banner::ACTION::EVENT):
            return graphics_banner::bannerInitializer(calendar, Banner::TYPE::EVENT);
            break;
        case(graphics_banner::ACTION::REMINDER):
            return graphics_banner::bannerInitializer(calendar, Banner::TYPE::REMINDER);
            break;
        case(graphics_banner::ACTION::TASK):
            return graphics_banner::bannerInitializer(calendar, Banner::TYPE::TASK);
            break;
        default: // Return
            return false;
    }

    return true;
}

bool graphics_banner::bannerInitializer(Calendar& calendar, Banner::TYPE type)
{
    system("clear");
    int year = calendar.getYear();
    std::string b_type = Banner::typeToString(type);
    std::string b_title = "";
    std::string b_description = "";
    std::string b_location = "";
    std::string b_urgencyStr = "";
    int b_urgency = -1;
    int p_month = 1;
    int p_day = 1;
    int p_timeStart = 0;
    int p_timeEnd = 0;
    int p_deadline = 0;
    
    // Title
    graphics_helper::idleReadString(&graphics::promptPointTitle, &graphics_checks::validText, b_title, b_type, false);
    // Description
    graphics_helper::idleReadString(&graphics::promptPointDescription, &graphics_checks::validText, b_description, b_type, true);
    // Location
    graphics_helper::idleReadString(&graphics::promptPointLocation, &graphics_checks::validText, b_location, b_type, true);
    // Urgency
    graphics_helper::idleReadString(&graphics::promptPointUrgency, &graphics_checks::isNumberInRangeUrgency, b_urgencyStr, b_type, true);
    if (b_urgencyStr.empty()) b_urgencyStr = "-1";
    b_urgency = stoi(b_urgencyStr);
    // Get Date Inputs 
    graphics_helper::getDateInputs(year, type, p_month, p_day, p_timeStart, p_timeEnd, p_deadline);

    // CREATE BANNER
    switch (type) {
        case(Banner::TYPE::EVENT):
            calendar.createNewBannerEvent(b_title, b_location, b_description, b_urgency, p_month, p_day, p_timeStart, p_timeEnd);
            break;
        case(Banner::TYPE::REMINDER):
            calendar.createNewBannerReminder(b_title,b_location,b_description, b_urgency, p_month, p_day);
            break;
        case(Banner::TYPE::TASK):
            calendar.createNewBannerTask(b_title,b_location,b_description, b_urgency, p_month, p_day, p_deadline, false);
            break;
        default: // Return
            return false;
    }

    // Finished Successfully
    return true;
}






