#ifndef GRAPHIC_CHECKS_H
#define GRAPHIC_CHECKS_H

#include <string>
#include <iostream>
#include <cmath>
#include <array>
#include "../utilities.h"
#include "./graphic_prints.h"

namespace graphics_checks {

    // CHECK FUNCTIONS

    /*
    * Checks that the string is a valid text
    * @param str - string
    * @param err - reference to enter into it reason for error
    * @return: the string is a valid text
    */
    bool validText(const std::string str, std::string& err);

    /*
    * Checks that the string is not empty
    * @param str - string
    * @param err - reference to enter into it reason for error
    * @return: the string is not empty
    */
    bool isNotEmpty(const std::string str, std::string& err);

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

    /*
    * Checks that the string has number between 1-5 (or is letter 'n')
    * @param str - string
    * @param err - reference to enter into it reason for error
    * @return: has number between 1-5 (or is letter 'n')
    */
    bool isNumberInRangeUrgency(const std::string str, std::string& err);

    /*
    * Checks that the string is a number
    * @param str - string
    * @param err - reference to enter into it reason for error
    * @return: is a number
    */
    bool isNumber(const std::string str, std::string& err);

    /*
    * Checks that the string is a valid month/day format
    * @param calendar - year of calendar
    * @param userInput - string
    * @param err - reference to enter into it reason for error
    * @return: is a valid month/day format
    */
    bool isValidMonthDayFormat(const int year,const std::string userInput, std::string& err, int& month, int& day);

    /*
    * Checks that the string is a valid time
    * @param str - string
    * @param err - reference to enter into it reason for error
    * @return: is a valid time
    */
    bool isValidTime(const std::string str, std::string& err);

    /*
    * Converts time string into int of minutes
    * @param str - valid time string
    * @return: the amount of minutes that the time represents
    */
    int timeToMinutes(const std::string time);
}




#endif // GRAPHIC_CHECKS_H