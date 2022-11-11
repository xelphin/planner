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