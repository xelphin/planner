#include "./utilities.h"

#define MIN_YEAR 2000
#define MAX_YEAR 3000

int amountDaysInMonth(const int year, const int month)
{
    if (year<MIN_YEAR || year>MAX_YEAR || month<1 || month>12)
        throw;
    bool isLeapYear = (year%4 == 0);
    return (month == 2) ?
		(28 + isLeapYear) : 31 - (month - 1) % 7 % 2;
}

int getMinYear() {return MIN_YEAR;}
int getMaxYear() {return MAX_YEAR;}

bool validDate(const int year, const int month, const int day)
{
    if (year<MIN_YEAR || year>MAX_YEAR || month<1 || month>12 || day<1 || day>31)
        return false;
    try {
        if (day > amountDaysInMonth(year, month))
            return false;
    } catch (...) {
        return false;
    }
    return true;
}

bool checkValidTime(const int minutes)
{
    return !(minutes<0 || minutes>1440);
}

bool checkValidTimeRange(const int start, const int end)
{
    return !(start>end || !checkValidTime(start) || !checkValidTime(end));
}