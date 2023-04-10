#ifndef GRAPHIC_BANNER_CREATOR_H
#define GRAPHIC_BANNER_CREATOR_H

#include <string>
#include <iostream>
#include <cmath>
#include <array>
#include "../Calendar/Calendar.h"
#include "../Banner/Banner.h"
#include "./graphic_prints.h"

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
    * Waits idly for user input of string.
    * @param printFunc - wanted prompt printing function
    * @param checkFunc - checks input is valid
    * @param str - reference to string to fill
    * @param type - type of Banner
    */
   void idleReadString(Calendar& calendar, std::string (*printFunc)(const std::string), bool (*checkFunc)(const std::string, std::string&), std::string& str, const std::string type);

    /*
    * Calls on Banner creation after being given type
    * @param calendar - reference to Calendar
    * @param action - 'e', 't' , 'r', 'x'
    * @return: true: valid type | false: invalid type
    */
    bool chooseBannerCreation(Calendar& calendar, const char& action_char);


    // CHECK FUNCTIONS
    /*
    * Checks that the string is a valid text
    * @param str - string
    * @param err - reference to enter into it reason for error
    * @return: the string is a valid text
    */
    bool validText(const std::string str, std::string& err);

    /*
    * Checks that the string starts with a letter
    * @param str - string
    * @param err - reference to enter into it reason for error
    * @return: string starts with a letter
    */
    bool startsWithLetter(const std::string str, std::string& err);

    /*
    * Checks that the string has only letters and numbers
    * @param str - string
    * @param err - reference to enter into it reason for error
    * @return: has only letters and numbers
    */
    bool hasOnlyLettersAndNumbers(const std::string str, std::string& err);
}




#endif