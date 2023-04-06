#ifndef DATE_DEADLINE_H
#define DATE_DEADLINE_H

#include "./DateAbstract.h"
#include "../utilities.h"
#include "../Exception.h"
#include <iostream>
#include <string>

class DateDeadline : public DateAbstract {
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

    /*
    * Gets the starting time [important for comparison]
    */
    int getTime() const override;

    /*
    * Get amount of minutes passed till reached end
    */
    int getEnd() const;

    /*
    * Prints to os the date
    */
    void print(std::ostream& os) const {
        os << this->m_year << "/" << this->m_month << "/" << this->m_day << " till: " << m_minutes << std::endl;
    }

    /*
    * Parse date to text
    */
    std::string parseToText() const override;

    ~DateDeadline() {}


private:
    int m_minutes;
    static const int GENERAL = -1;
};


#endif