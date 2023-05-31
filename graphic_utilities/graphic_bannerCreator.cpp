#include "./graphic_bannerCreator.h"

graphics_banner::ACTION graphics_banner::characterToBannerType(const char &action)
{
    switch (action)
    {
    case ('e'):
        return graphics_banner::ACTION::EVENT;
    case ('r'):
        return graphics_banner::ACTION::REMINDER;
    case ('t'):
        return graphics_banner::ACTION::TASK;
    case ('x'):
        return graphics_banner::ACTION::RETURN;
    default:
        return graphics_banner::ACTION::NOTHING;
    }
}

bool graphics_banner::mainBannerCreation(Calendar &calendar)
{
    system("clear");
    char type = 'x';
    std::string userInput = "";
    Banner::TYPE b_type = Banner::TYPE::EVENT;

    // PRINT ACTION BAR
    std::cout << graphics::calendarTitle() << std::endl;
    std::cout << graphics::promptWhichPointToAdd() << std::endl;

    // GET INPUT
    std::cin >> userInput;
    userInput = trim(userInput);

    type = userInput[0];

    // CREATE BANNER
    bool success = graphics_banner::chooseBannerCreation(calendar, type, b_type);
 

    // SUGGEST REPETITIONS
    graphics_banner::queryForRepetitions(calendar, b_type);


    // COMPLETED
    system("clear");
    std::cout << graphics::calendarTitle() << std::endl;
    std::cout << graphics::bannerCompletion(success) << std::endl;
    std::cin >> userInput; // wait for key press to exit

    //
    return false;
}

bool graphics_banner::chooseBannerCreation(Calendar &calendar, const char &action_char, Banner::TYPE &b_type)
{
    graphics_banner::ACTION action = graphics_banner::characterToBannerType(action_char);
    if (action == graphics_banner::ACTION::NOTHING)
        return false;

    // TODO: No need for switch case I think
    switch (action)
    {
    case (graphics_banner::ACTION::EVENT):
        b_type = Banner::TYPE::EVENT;
        return graphics_banner::bannerInitializer(calendar, Banner::TYPE::EVENT);
        break;
    case (graphics_banner::ACTION::REMINDER):
        b_type = Banner::TYPE::REMINDER;
        return graphics_banner::bannerInitializer(calendar, Banner::TYPE::REMINDER);
        break;
    case (graphics_banner::ACTION::TASK):
        b_type = Banner::TYPE::TASK;
        return graphics_banner::bannerInitializer(calendar, Banner::TYPE::TASK);
        break;
    default: // Return
        return false;
    }

    return true;
}

bool graphics_banner::bannerInitializer(Calendar &calendar, Banner::TYPE type)
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
    if (b_urgencyStr.empty())
        b_urgencyStr = "-1";
    b_urgency = stoi(b_urgencyStr);
    // Get Date Inputs
    bool successDate = graphics_helper::getDateInputs(year, type, p_month, p_day, p_timeStart, p_timeEnd, p_deadline, false);
    if (!successDate) {
        return false;
    }

    // CREATE BANNER
    switch (type)
    {
    case (Banner::TYPE::EVENT):
        calendar.createNewBannerEvent(b_title, b_location, b_description, b_urgency, p_month, p_day, p_timeStart, p_timeEnd);
        break;
    case (Banner::TYPE::REMINDER):
        calendar.createNewBannerReminder(b_title, b_location, b_description, b_urgency, p_month, p_day);
        break;
    case (Banner::TYPE::TASK):
        calendar.createNewBannerTask(b_title, b_location, b_description, b_urgency, p_month, p_day, p_deadline, false);
        break;
    default: // Return
        return false;
    }

    // Finished Successfully
    return true;
}

void graphics_banner::queryForRepetitions(Calendar &calendar, const Banner::TYPE b_type)
{
    system("clear");
    // Declare Variables
    int year = calendar.getYear();
    int p_month = 1;
    int p_day = 1;
    int p_timeStart = 0;
    int p_timeEnd = 0;
    int p_deadline = 0;
    bool userWantsToAdd = true;

    // Ask from user repetition
    while (userWantsToAdd) {
        userWantsToAdd = graphics_helper::getDateInputs(year, b_type, p_month, p_day, p_timeStart, p_timeEnd, p_deadline, true);

        if (userWantsToAdd) {
            // Add repetition to Calendar
            // Note: The calendar is selecting the newly created Point (Banner)
            switch (b_type)
            {
            case (Banner::TYPE::EVENT):
                calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), p_month, p_day, p_timeStart, p_timeEnd);
                continue;
            case (Banner::TYPE::REMINDER):
                calendar.addReminder( ( *(calendar.getSelectedPoint()) ).getBanner(), p_month, p_day);
                continue;
            case (Banner::TYPE::TASK):
                calendar.addTask( ( *(calendar.getSelectedPoint()) ).getBanner(), p_month, p_day, p_deadline, false);
                continue;
            default: // Return
                return;
            }

        }
    }

}