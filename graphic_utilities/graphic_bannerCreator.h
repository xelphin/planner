#ifndef GRAPHIC_BANNER_CREATOR_H
#define GRAPHIC_BANNER_CREATOR_H

#include <string>
#include <iostream>
#include <cmath>
#include <array>
#include "../Calendar/Calendar.h"
#include "../Banner/Banner.h"
#include "../utilities.h"
#include "./graphic_prints.h"
#include "./graphic_checks.h"
#include "./graphic_helper.h"

namespace graphics_banner
{

    enum class ACTION
    {
        EVENT,
        REMINDER,
        NOTHING,
        TASK,
        RETURN
    };

    /*
     * Translate from action character to enum
     * @param action - 'e', 'r', 't', 'x'
     */
    graphics_banner::ACTION characterToBannerType(const char &action);

    /*
     * Start process for new Point creation.
     * @param calendar - reference to Calendar
     * @return: true: successfully created Point | false: process incomplete
     */
    bool mainBannerCreation(Calendar &calendar);

    /*
     * Start process for new Banner of Point creation.
     * @param calendar - reference to Calendar
     * @param type - Banner Type
     * @return: true: successfully created Banner | false: process incomplete
     */
    bool bannerInitializer(Calendar &calendar, Banner::TYPE type);

    /*
     * Starts Banner creation after being given type
     * @param calendar - reference to Calendar
     * @param action - 'e', 't' , 'r', 'x'
     * @param b_type - Banner Type
     * @return: true: valid type | false: invalid type
     */
    bool chooseBannerCreation(Calendar &calendar, const char &action_char, Banner::TYPE& b_type);

}

#endif