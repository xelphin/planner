#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include "../Exception.h"
#include "../utilities.h"

class Date {

    public:
        /*
        * C'tor of Date class
        *
        * @return
        *      A new instance of Date.
        */
        Date(const int year, const int month, const int day);

        /*
        * Edit date
        * @param newMonth - The new month for the point
        * @param newDay - The new day for the point
        */
       void updateDate(const int newMonth, const int newDay);

    protected:
        int m_year;
        int m_month;
        int m_day;
};

#endif