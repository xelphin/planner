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

namespace graphics_banner {

    enum class ACTION {EVENT, REMINDER, NOTHING, TASK, RETURN};

    /*
    * Translate from action character to enum
    * @param action - 'a', 'd' , 'w', 's', 'e', 'c', 'r', 'x'
    */
    graphics_banner::ACTION characterToBannerType(const char& action);

    /*
    * Start process for new Point creation.
    * @param calendar - reference to Calendar
    * @return: true: successfully created Point | false: process incomplete
    */
    bool mainPointCreationProcess(Calendar& calendar);

    /*
    * Start process for new Banner of Point creation.
    * @param calendar - reference to Calendar
    * @param type - Banner Type
    * @return: true: successfully created Banner | false: process incomplete
    */
    bool mainBannerCreationProcess(Calendar& calendar, Banner::TYPE type);

    /*
    * Starts Banner creation after being given type
    * @param calendar - reference to Calendar
    * @param action - 'e', 't' , 'r', 'x'
    * @return: true: valid type | false: invalid type
    */
    bool chooseBannerCreation(Calendar& calendar, const char& action_char);

    /*
    * Fills date inputs depending on types
    * @param year - year in Calendar
    * @param type - Banner Type
    * @param month - Month of Point
    * @param day - Day of Point
    * @param timeStart - timeStart of Point (for Event type)
    * @param timeEnd - timeEnd of Point (for Event type)
    * @param deadline - deadline of Point (for Task type)
    */
    bool getDateInputs(const int year, Banner::TYPE type, int& month, int& day, int& timeStart, int& timeEnd, int& deadline);

    /*
    * Waits idly for user input of string.
    * @param printFunc - wanted prompt printing function
    * @param checkFunc - checks input is valid
    * @param str - reference to string to fill
    * @param type - type of Banner
    * @param canBeEmpty - If true, then an empty string will be represented by the user as 'n'
    */
   void idleReadString(std::string (*printFunc)(const std::string), bool (*checkFunc)(const std::string, std::string&), std::string& str, const std::string type, const bool canBeEmpty);

    /*
    * Waits idly for user input of date.
    * @param year - year of calendar
    * @param userInput - reference to string to fill
    */
    void getDate(const int year, int& month, int& day);

    /*
    * Waits idly for user input of time, different prompts for different Point types.
    * @param calendar - reference to Calendar
    * @param type - Banner Type
    * @param timeStart - timeStart of Point (for Event type)
    * @param timeEnd - timeEnd of Point (for Event type)
    * @param deadline - deadline of Point (for Task type)
    */
   void getTime(Banner::TYPE type, int& timeStart, int& timeEnd, int& deadline);

}




#endif