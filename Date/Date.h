#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include "./DateAbstract.h"
#include "../Exception.h"
#include "../utilities.h"

class Date : public DateAbstract{

    public:
        /*
        * C'tor of Date class
        *
        * @return
        *      A new instance of Date.
        */
        Date(const int year, const int month, const int day);

        /*
        * Prints to os the date
        */
        void print(std::ostream& os) const {
            os << this->m_year << "/" << this->m_month << "/" << this->m_day << std::endl;
        }

        /*
        * Parse date to text
        */
       std::string parseToText() const override;

       ~Date() {}

};

#endif