#include "./utilities.h"

int amountDaysInMonth(const int year, const int month)
{
    if (year<0 || month<1 || month>12)
        throw;
    bool isLeapYear = (year%4 == 0);
    return (month == 2) ?
		(28 + isLeapYear) : 31 - (month - 1) % 7 % 2;
}

bool validDate(const int year, const int month, const int day)
{
    if (year<0 || month<1 || month>12 || day<1 || day>31)
        return false;
    try {
        if (day > amountDaysInMonth(year, month))
            return false;
    } catch (...) {
        return false;
    }
    return true;
}