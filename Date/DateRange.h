#ifndef DATE_RANGE_H
#define DATE_RANGE_H

#include "./DateAbstract.h"
#include "../utilities.h"
#include "../Exception.h"
#include <iostream>
#include <string>

class DateRange : public DateAbstract {
public:
    /*
     * C'tor of DateDeadline class
     *
     * @param name - Rogue's name.
     * @return
     *      A new instance of Rogue.
    */
    DateRange(const int year, const int month, const int day, const int start, const int end);

    /*
    * Edit date
    * @param newMonth - The new month for the point
    * @param newDay - The new day for the point
    */
    void updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd);

    /*
    * Gets the starting time [important for comparison]
    */
    int getTime() const override;

    /*
    * Get amount of minutes passed till reached end
    */
    int getEnd() const override;

    /*
    * Prints to os the date
    */
    void print(std::ostream& os) const {
        os << this->m_year << "/" << this->m_month << "/" << this->m_day 
        << " from : " << m_start << " till: "<< m_end << std::endl;
    }

    /*
    * Parse date to text
    */
    std::string parseToText() const override;

    ~DateRange() {}

private:
    int m_start;
    int m_end;
    static const int GENERAL = -1;
};

#endif