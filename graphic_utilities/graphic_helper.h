#ifndef GRAPHIC_HELPER_H
#define GRAPHIC_HELPER_H

#include <string>
#include <iostream>
#include <cmath>
#include <array>
#include "../Calendar/Calendar.h"
#include "../Banner/Banner.h"
#include "../utilities.h"
#include "./graphic_prints.h"
#include "./graphic_checks.h"
#include "../Exception.h"

namespace graphics_helper {

    /*
    * Fills date inputs depending on types
    * @param year - year in Calendar
    * @param type - Banner Type
    * @param month - Month of Point
    * @param day - Day of Point
    * @param timeStart - timeStart of Point (for Event type)
    * @param timeEnd - timeEnd of Point (for Event type)
    * @param deadline - deadline of Point (for Task type)
    * @param isForRep - asking for a repetition (means it will be okay if empty)
    */
    bool getDateInputs(const int year, Banner::TYPE type, int& month, int& day, int& timeStart, int& timeEnd, int& deadline, const bool isForRep);

    /*
    * Waits idly for user input of string.
    * @param printFunc - wanted prompt printing function
    * @param checkFunc - checks input is valid
    * @param str - reference to string to fill
    * @param type - type of Banner
    * @param canBeEmpty - If true, then an empty string will be represented by the user as 'n'
    * @param currVersion - Current Version of type string (only used by graphics_edit)
    * @param isEdit - True = from graphics_edit | False = from graphics_createBanner
    */
   void idleReadString(
        std::string (*printFunc)(const std::string),
        bool (*checkFunc)(const std::string, std::string&),
        std::string& str,
        const std::string type,
        const bool canBeEmpty,
        const std::string currVersion = "",
        const bool isEdit = false
    );

    /*
    * Waits idly for user input of date.
    * @param year - year of calendar
    * @param userInput - reference to string to fill
    */
    void getDate(const int year, int& month, int& day, const bool isForRep);

    /*
    * Waits idly for user input of time, different prompts for different Point types.
    * @param calendar - reference to Calendar
    * @param type - Banner Type
    * @param timeStart - timeStart of Point (for Event type)
    * @param timeEnd - timeEnd of Point (for Event type)
    * @param deadline - deadline of Point (for Task type)
    */
   void getTime(Banner::TYPE type, int& timeStart, int& timeEnd, int& deadline);


    /*
     * Ask if user wants repetitions, so long as they do add them
     * @param calendar - reference to Calendar
     * @param b_type - Banner Type
     */
    void queryForRepetitions(Calendar &calendar, const Banner::TYPE b_type);

    /*
     * Notify user that the process was stopped midway deliberatley
     * @param processName - Process that was stopped
     */
    void notifyProcessStopped(const std::string processName);
}




#endif // GRAPHIC_HELPER_H