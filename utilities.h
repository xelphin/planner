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
* @param str - String formatted like int array.
*/
template<std::size_t AMOUNT>
void parseStringToArray(std::array<int, AMOUNT>& arr, const std::string str)
{
    int size = str.size();
    bool needNumber = true;
    if (size<2 || str[0]!='[' || str[size-1]!=']')
        throw InvalidFormatOfRepetitionArray();
    int arrIndex = 0;
    for (std::string::size_type i = 1; i < str.size() - 1; i++) {
        if ( (str[i]!=' ' && !(str[i]>'0' && str[i]<'9')) || (str[i] == str[i+1] && str[i]==',') )
            throw InvalidFormatOfRepetitionArray();
        if (arrIndex>=int(AMOUNT))
            throw TooManyValuesInString();
        if (str[i] == ' ') {
            needNumber = true;
            continue;
        }
        if(str[i] == ',') {
            if(needNumber)
                throw InvalidFormatOfRepetitionArray();
            arrIndex++;
            continue;
        }
        needNumber = false;
        int strIndexAfterLast=i+1;
        while(str[strIndexAfterLast]>='0' && str[strIndexAfterLast]<='9') 
            strIndexAfterLast++;
        
        int numLength = strIndexAfterLast-i;
        if(numLength > 4)
            throw ArrayValueIsTooLarge();
        
        if(arrIndex>int(AMOUNT))
            throw InvalidFormatOfRepetitionArray();

        arr[arrIndex] = std::stoi(str.substr(i, numLength));

        arrIndex++;
        i = strIndexAfterLast;
    }

    if(arrIndex-1<int(AMOUNT)-1)
        throw TooLittleValuesInString();
}


#endif