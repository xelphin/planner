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

       ~Date() {}

};

#endif