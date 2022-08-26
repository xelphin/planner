#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>
#include <memory>
#include <list>
#include "../Exception.h"
#include "../utilities.h"
#include "../Date/DateAbstract.h"
#include "../Banner/Banner.h"

class Point {

    public:
        /*
        * C'tor of Point class
        *
        * @return
        *      A new instance of Point.
        */
        Point(std::shared_ptr<Banner> banner, const int year);

        /*
        * Edit title
        * @param newTitle - The new title for the point
        */
       void updateTitle(const std::string newTitle);

        /*
        * @return
        *      Title of banner.
        */
       std::string getTitle() const;

        /*
        * Edit description
        * @param newDescription - The new description
        */
       void updateDescription(const std::string newDescription);

        /*
        * @return
        *      Description of banner.
        */
       std::string getDescription() const;

        /*
        * Edit date
        * @param newMonth - The new month for the point
        * @param newDay - The new day for the point
        * @param arg1 - Deadline or TimeStart depending on whether or not arg2 is EMPTY_ARG
        * @param arg2 - TimeEnd
        */
       virtual void updateDate(const int newMonth, const int newDay,
                               const int arg1 = EMPTY_ARG, const int arg2 = EMPTY_ARG) = 0;

        virtual DateAbstract* getDate() const = 0;

        /*
        * @return
        *      True: p1 == p2
        */
       friend bool operator==(const Point& p1, const Point& p2);

        /*
        * @return
        *      True: p1 != p2
        */
       bool operator!=(const Point& other) const;

        /*
        * @return
        *      True: p1 < p2
        */
       friend bool operator<(const Point& p1, const Point& p2);

        /*
        * @return
        *      True: p1 > p2
        */
       bool operator>(const Point& other) const;

        /*
        * @return
        *      True: p1 <= p2
        */
       bool operator<=(const Point& other) const;

        /*
        * @return
        *      True: p1 >= p2
        */
       bool operator>=(const Point& other) const;

        // D'tor
        virtual ~Point() {}

    protected:
        int m_year;
        std::shared_ptr<Banner> m_banner;

        static const int EMPTY_ARG = -2;

};

#endif