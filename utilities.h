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

/*
* Takes string that looks like int array and parses it into an int array
*
* @param arr - Array that we are modifying.
* @param amount - Size of array we are modifying.
* @param str - String formatted like int array.
*/

void parseStringToArray(int arr[], const int amount, const std::string str);

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


#endif