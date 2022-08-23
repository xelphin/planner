#ifndef DATE_DEADLINE_H
#define DATE_DEADLINE_H

#include "Date.h"
#include "../utilities.h"
#include <iostream>
#include <string>

class DateDeadline : public Date {
public:
    /*
     * C'tor of DateDeadline class
     *
     * @param name - Rogue's name.
     * @return
     *      A new instance of Rogue.
    */
    DateDeadline(const int year, const int month, const int day, const int minutes);

    /*
    * Edit date
    * @param newMonth - The new month for the point
    * @param newDay - The new day for the point
    */
    void updateDate(const int newMonth, const int newDay, const int newDeadline);


private:
    int m_minutes;
    static const int GENERAL = -1;
};

#endif