#include "./graphic_controls.h"



graphics::ACTION graphics::characterToAction(const char& action)
{   
    switch (action) {
        case('a'):
            return graphics::ACTION::L;
        case('d'):
            return graphics::ACTION::R;
        case('w'):
            return graphics::ACTION::U;
        case('s'):
            return graphics::ACTION::D;
        case('e'):
            return graphics::ACTION::EDIT;
        case('c'):
            return graphics::ACTION::CREATE;
        case('r'):
            return graphics::ACTION::REMOVE;
        case('x'):
            return graphics::ACTION::SAVE_AND_EXIT;
        default:
            return graphics::ACTION::NONE;
    }
}

void graphics::idleReadAction(Calendar& calendar)
{
    char action = 'x';
    std::string userInput = "";
    bool readAction = false;
    do {
        // PRINT ACTION BAR
        std::cout << graphics::calendarTitle() << std::endl;
        std::cout << graphics::actionBar() << std::endl;
        // PRINT CALENDAR
        std::cout << calendar.printMonthSimplified();
        
        // GET INPUT
        std::cin >> userInput;
        userInput = trim(userInput);
        if (userInput.empty()) break;

        action = userInput[0];

        // APPLY ACTION
        readAction = graphics::apllyAction(calendar, action);
        // TODO: prints and more action availablity
        // TODO: Point creation and editing
        system("clear");
        // TODO: udate dependencies in Makefile of graphics, add utilities to graphic_prints and apply trim to strings where necessary
    }
    while (readAction);
}

bool graphics::apllyAction(Calendar& calendar, const char& action_char)
{
    graphics::ACTION action = graphics::characterToAction(action_char);
    if (action == graphics::ACTION::NONE) return false;

    switch (action) {
        case(graphics::ACTION::U):
            calendar.selectEarlierPoint();
            break;
        case(graphics::ACTION::D):
            calendar.selectLaterPoint();
            break;
        case(graphics::ACTION::L):
            calendar.selectEarlierPointFromAPreviousMonth();
            break;
        case(graphics::ACTION::R):
            calendar.selectLaterPointFromAnUpcomingMonth();
            break;
        case(graphics::ACTION::EDIT):
            graphics_edit::mainBannerEditor(calendar);
            break;
        case(graphics::ACTION::CREATE):
            graphics_banner::mainBannerCreation(calendar);
            break;
        case(graphics::ACTION::REMOVE):
            calendar.removeSelectedPoint();
            break;
        case(graphics::ACTION::SAVE_AND_EXIT):
            calendar.parseCalendarToTextFile("database.txt");
            return false;
        default:
            return false;
    }

    return true;
}