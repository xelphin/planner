#include "./graphic_controls.h"



graphics::DIRECTION graphics::characterToDirection(const char& direction)
{   
    switch (direction) {
        case('a'):
            return graphics::DIRECTION::L;
        case('d'):
            return graphics::DIRECTION::R;
        case('w'):
            return graphics::DIRECTION::U;
        case('s'):
            return graphics::DIRECTION::D;
        default:
            return graphics::DIRECTION::NONE;
    }
}

void graphics::idleReadAction(Calendar& calendar)
{
    char action = 'x';
    std::string userInput = "";
    bool readAction = false;
    do {
        std::cout << graphics::calendarTitle() << std::endl;
        std::cout << graphics::actionBar() << std::endl;
        std::cout << calendar.printMonthSimplified();
        
        std::cin >> userInput;
        userInput = trim(userInput);
        if (userInput.empty()) break;

        action = userInput[0];
        readAction = graphics::select_Point(calendar, action);
        // TODO: prints and more action availablity
        // TODO: Point creation and editing
        system("clear");
        // TODO: udate dependencies in Makefile of graphics, add utilities to graphic_prints and apply trim to strings where necessary
    }
    while (readAction);
}

bool graphics::select_Point(Calendar& calendar, const char& direction)
{
    graphics::DIRECTION action = graphics::characterToDirection(direction);
    if (action == graphics::DIRECTION::NONE) return false;

    switch (action) {
        case(graphics::DIRECTION::U):
            calendar.selectEarlierPoint();
            break;
        case(graphics::DIRECTION::D):
            calendar.selectLaterPoint();
            break;
        case(graphics::DIRECTION::L):
            calendar.selectEarlierPointFromAPreviousMonth();
            break;
        case(graphics::DIRECTION::R):
            calendar.selectLaterPointFromAnUpcomingMonth();
            break;
        default:
            return false;
    }

    return true;
}