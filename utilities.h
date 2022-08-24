#ifndef UTILITIES_H
#define UTILITIES_H

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

#endif