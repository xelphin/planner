#ifndef GRAPHIC_BANNER_CREATOR_H
#define GRAPHIC_BANNER_CREATOR_H

#include <string>
#include <iostream>
#include <cmath>
#include <array>
#include "../Calendar/Calendar.h"
#include "./graphic_prints.h"

namespace graphics_banner {

    enum class ACTION {EVENT, REMINDER, NOTHING, TASK, RETURN};

    /*
    * Translate from action character to enum
    * @param action - 'a', 'd' , 'w', 's', 'e', 'c', 'r', 'x'
    */
    graphics_banner::ACTION characterToBannerType(const char& action);

    /*
    * Start process for new Banner creation.
    * @param calendar - reference to Calendar
    * @return: true: successfully created banner | false: process incomplete
    */
    bool mainBannerCreationProcess(Calendar& calendar);

    /*
    * Waits idly for banner type.
    */
    void idleReadBanner(Calendar& calendar, std::string (*printFunc)(), bool (*chooseFunc)(Calendar&, const char&));

    /*
    * Calls on Banner creation after being given type
    * @param calendar - reference to Calendar
    * @param action - 'e', 't' , 'r', 'x'
    * @return: true: valid type | false: invalid type
    */
    bool chooseBannerCreation(Calendar& calendar, const char& action_char);
}




#endif