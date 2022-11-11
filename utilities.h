#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>
#include <cmath>
#include <array>
#include "./Exception.h"

/*
* Get the amount of days that belong to chosen month
*
* @param year - Chosen year.
* @param month - Chosen month.
* @return
*      Amount of days that belong to month.
*/
int amountDaysInMonth(const int year, const int month);

/*
* Get min/max allowed year
*/
int getMinYear();
int getMaxYear();

/*
* Get min/max allowed month
*/
int getMinMonth();
int getMaxMonth();

/*
* Check if the day/month/year exists
*
* @param year - Chosen year.
* @param month - Chosen month.
* @param month - Chosen day.
* @return
*      True: Day is valid | False: Day is invalid
*/
bool validDate(const int year, const int month, const int day);

/*
* Check if the time exists
*
* @param minutes - Chosen minutes.
* @return
*      True: Time is valid | False: Time is invalid
*/
bool checkValidTime(const int minutes);

/*
* Check if the time exists
*
* @param start - Minutes marking start.
* @param end - Minutes marking end.
* @return
*      True: Time is valid | False: Time is invalid
*/
bool checkValidTimeRange(const int start, const int end);

void printArray(int arr[], const int amount);

bool checkEquivalence(int arr1[], int arr2[], const int amount);


/*
* Ask user for year
* @return
*      A valid year.
*/
int askUserYear();


/*
* Returns the name of the month
*
* @param num - The month in num.
* @return
*      A string of the month name.
*/
std::string numToMonthName(const int num);

/*
* Translates the amount of minutes passed from start of the day into a string formatted time
*
* @param min - Amount of minutes passed from start of the day.
* @return
*      The time in string format.
*/
std::string minutesToTime(const int min);

/*
* Count amount of elements in a string that represents an array of strings and ints
*
* @param str - String that is an array of strings and ints
* @return
*      Amount of elements in str (of mixed elements)
*/
int countElemsInString(const std::string& str);

/*
* Helper function to countElemsInString(), check that the number is framed correctly in the array
*
* @param str - String that is an array of strings and ints
* @param length - Length of str
* @param i - Index where the number is starting from
*
* Leave i at upcoming ',' index or at i = length-2
*/
void checkBecomesValidNumber(const std::string& str, const int length, int& i);

/*
* Helper function to countElemsInString(), check that the nested string is framed correctly in the string array
*
* @param str - String that is an array of strings and ints
* @param length - Length of str
* @param i - Index where the opening " is
*
* Leave i at upcoming ',' index or at i = length-2
*/
void checkBecomesValidString(const std::string& str, const int length, int& i);

/*
* Helper function to countElemsInString(), check from element till next , or end of array is only spaces
*
* @param str - String that is an array of strings and ints
* @param length - Length of str
* @param i - Index where the opening " is
*
* Leave i at upcoming ',' index or at i = length-2
*/
void checkOnlySpacesTillComma(const std::string& str, const int length, int& i);

// Trimming String Functions (copy pasted from internet)
std::string trim(const std::string &s);
std::string rtrim(const std::string &s);
std::string ltrim(const std::string &s);

/*
* Gets string array and iterator reference, extracts (nested) string from where iterator starts
* Note!!! Use only after having checked array!!!!
* @param str - string array
* @param i - iterator pointing at opening " or space(s) and/or comma before opening "
*/
std::string extractString(std::string& str, int& i);

/*
* Gets string array and iterator reference, extracts (nested) string from where iterator starts
* Note!!! Use only after having checked array!!!!
* @param str - string array
* @param i - iterator pointing at opening digit/minus or space(s) and/or comma before opening digit/minus
*/
int extractInt(std::string& str, int& i);

/*
* Get the current (real-time) month and date
* @param month - reference to month
* @param day - reference to day
*/
void getCurrMonthDay(int& month, int& day);

#endif