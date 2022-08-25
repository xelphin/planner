#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>
#include <memory>
#include <list>
#include "../Exception.h"
#include "../utilities.h"
#include "../Date/DateAbstract.h"

class Point {

    public:
        /*
        * C'tor of Point class
        *
        * @return
        *      A new instance of Point.
        */
        Point(const std::string title, const int year,const bool repeat,
            const std::string repeatArray,  const int amountRepetitions,
            const std::string description);

        /*
        * Edit title
        * @param newTitle - The new title for the point
        */
       void updateTitle(const std::string newTitle);

        /*
        * Edit description
        * @param newDescription - The new description
        */
       void updateDescription(const std::string newDescription);

        /*
        * Edit date
        * @param newMonth - The new month for the point
        * @param newDay - The new day for the point
        * @param arg1 - Deadline or TimeStart depending on whether or not arg2 is EMPTY_ARG
        * @param arg2 - TimeEnd
        */
       virtual void updateDate(const int newMonth, const int newDay,
                               const int arg1 = EMPTY_ARG, const int arg2 = EMPTY_ARG) = 0;

        /*
        * Add date where Point will be repeated
        * @param times - Array with data of new date
        */
       virtual void addRepeat(const int times[]) = 0;

        // D'tor
        virtual ~Point() {}

    protected:
        std::string m_title;
        int m_year;
        bool m_repeat;
        int m_amountRepetitions;
        std::string m_description;
        std::list<std::unique_ptr<DateAbstract>> m_repetitions;

        static const int MIN_TITLE_LENGTH = 1;
        static const int MAX_TITLE_LENGTH = 40;
        static const int MIN_DESCRIPTION_LENGTH = 0;
        static const int MAX_DESCRIPTION_LENGTH = 400;
        static const int EMPTY_ARG = -1;

};

#endif