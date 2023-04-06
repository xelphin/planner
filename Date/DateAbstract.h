#ifndef DATE_ABSTRACT_H
#define DATE_ABSTRACT_H

#include <string>
#include <iostream>
#include "../Exception.h"
#include "../utilities.h"

/**
 * 
 * WHAT
 * Abstract class for the different types of dates (Date [normal], DateDeadline and DateRange)
 * 
 * IMPORTANT
 * The parseToText() method parses the date class into a text format.
 * The text format is saved in the database.txt file.
 * This way, when project initializes, it parses the text into the proper date class and enters it into the Calendar.
 *
*/

class DateAbstract {

    public:
        /*
        * C'tor of Date class
        *
        * @return
        *      A new instance of Date.
        */
        DateAbstract(const int year, const int month, const int day);

        /*
        * Edit date
        * @param newMonth - The new month for the point
        * @param newDay - The new day for the point
        */
       void updateDate(const int newMonth, const int newDay);

        /*
        * @return
        *      month
        */
       int getMonth() const;

        /*
        * @return
        *      day
        */
       int getDay() const;

        /*
        * Get amount of minutes from start of day
        */
       virtual int getTime() const;

        /*
        * Get amount of minutes passed till reached end
        */
       virtual int getEnd() const;

        /*
        * @return
        *      True: d1 == d2
        */
       friend bool operator==(const DateAbstract& d1, const DateAbstract& d2);

        /*
        * @return
        *      True: d1 != d2
        */
       bool operator!=(const DateAbstract& other) const;

        /*
        * @return
        *      True: d1 < d2
        */
       friend bool operator<(const DateAbstract& d1, const DateAbstract& d2);

        /*
        * @return
        *      True: d1 > d2
        */
       bool operator>(const DateAbstract& other) const;

        /*
        * @return
        *      True: d1 <= d2
        */
       bool operator<=(const DateAbstract& other) const;

        /*
        * @return
        *      True: d1 >= d2
        */
       bool operator>=(const DateAbstract& other) const;

        /*
        * Prints to os the date
        */
       virtual void print(std::ostream& os) const = 0;

        /*
        * Parse date to text
        */
       virtual std::string parseToText() const = 0;

       friend std::ostream& operator<<(std::ostream& os, const DateAbstract& toPrint);

        // D'tor
        virtual ~DateAbstract() {}

    protected:
        int m_year;
        int m_month;
        int m_day;

        static const int ALL_DAY = -1;
};

#endif