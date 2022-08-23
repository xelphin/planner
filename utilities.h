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
* Check if the day/month/year exists
*
* @param year - Chosen year.
* @param month - Chosen month.
* @param month - Chosen day.
* @return
*      True: Day is valid | False: Day is invalid
*/
bool validDate(const int year, const int month, const int day);

#endif