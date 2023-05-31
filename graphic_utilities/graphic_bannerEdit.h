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

namespace graphics_edit
{
    /*
     * Start process for editing Point (Banner).
     * @param calendar - reference to Calendar
     * @return: true: successfully edited Point | false: process incomplete
     */
    void mainBannerEditor(Calendar &calendar);

    /*
     * Start process for editing Point (Banner).
     * @param calendar - reference to Calendar
     * @return: true: successfully edited Point | false: process incomplete
     */
    bool queryForEdit(Calendar &calendar);
}

#endif // GRAPHIC_BANNER_EDIT_H