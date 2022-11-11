#ifndef GRAPHIC_CONTROLS_H
#define GRAPHIC_CONTROLS_H

#include <string>
#include <iostream>
#include <cmath>
#include <array>
#include "../Calendar/Calendar.h"

namespace graphics {

    enum class DIRECTION {L,R,U,D, NONE};

    /*
    * Translate from direction character to enum
    * @param direction - 'a', 'd' , 'w', 's'
    */
    graphics::DIRECTION characterToDirection(const char& direction);

    /*
    * Select closest Point that is in requested direction
    * @param calendar - reference to Calendar
    * @param direction - 'a', 'd' , 'w', 's'
    * @return: true: valid direction | false: invalud direction
    */
    bool select_Point(Calendar& calendar, const char& direction);
}




#endif