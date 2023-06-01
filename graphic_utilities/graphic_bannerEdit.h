#ifndef GRAPHIC_BANNER_EDIT_H
#define GRAPHIC_BANNER_EDIT_H

#include <string>
#include <iostream>
#include <cmath>
#include <array>
#include "../Calendar/Calendar.h"
#include "../Banner/Banner.h"
#include "../Points/Point.h"
#include "../Points/Event.h"
#include "../Points/Reminder.h"
#include "../Points/Task.h"
#include "../utilities.h"
#include "./graphic_prints.h"
#include "./graphic_checks.h"
#include "./graphic_helper.h"
#include "../Exception.h"

namespace graphics_edit
{


    /*
     * Start process for editing Point (Banner).
     * @param calendar - reference to Calendar
     * @return: true: successfully edited Point | false: process incomplete
     */
    void mainBannerEditor(Calendar &calendar);

    /*
     * Get index of attribute from user. Available indices defined at Point::getAttribute_editingFormat()
     * @param calendar - reference to Calendar
     * @param pointType - to fill with the pointType
     * @return: the attribute that user wants to edit
     */
    pointsInfo::EDIT idleReadIndex(Calendar &calendar, pointsInfo::TYPE& pointType);


    /*
     * Depending on action, redirect to wanted edit frame
     * @param calendar - reference to Calendar
     * @param pointType - point type
     * @return: successful change
     */
    bool editRedirection(Calendar &calendar, const pointsInfo::EDIT editType, const pointsInfo::TYPE pointType);



    // TODO: Don't have this! Just use Banner::TYPE always and erase pointInfo::TYPE
    Banner::TYPE pointTypeToBanner(const pointsInfo::TYPE pointType);

}

#endif // GRAPHIC_BANNER_EDIT_H