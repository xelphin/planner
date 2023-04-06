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

bool graphics_banner::mainBannerCreationProcess(Calendar& calendar)
{
    system("clear");
    graphics_banner::idleReadBanner(calendar, &graphics::promptWhichPointToAdd, &graphics_banner::chooseBannerCreation);
    return false;
}


void graphics_banner::idleReadBanner(Calendar& calendar, std::string (*printFunc)(), bool (*chooseFunc)(Calendar&, const char&))
{
    char type = 'x';
    std::string userInput = "";
    bool readAction = false;
    do {
        // PRINT ACTION BAR
        std::cout << graphics::calendarTitle() << std::endl;
        std::cout << printFunc() << std::endl;
        
        // GET INPUT
        std::cin >> userInput;
        userInput = trim(userInput);
        if (userInput.empty()) break;

        type = userInput[0];

        // APPLY ACTION
        readAction = chooseFunc(calendar, type);
        system("clear");
    }
    while (readAction);
}

bool graphics_banner::chooseBannerCreation(Calendar& calendar, const char& action_char)
{
    graphics_banner::ACTION action = graphics_banner::characterToBannerType(action_char);
    if (action == graphics_banner::ACTION::NOTHING) return false;

    switch (action) {
        case(graphics_banner::ACTION::EVENT):
            // Create Event
            break;
        case(graphics_banner::ACTION::REMINDER):
            // Create Reminder
            break;
        case(graphics_banner::ACTION::TASK):
            // Create Task
            break;
        default:
            return false;
    }

    return true;
}