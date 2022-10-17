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
        Point(const int year, std::shared_ptr<Banner> banner);

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

        /*
        * Get the Date of the Point
        * @return
        *      Date of the Point.
        */
        virtual DateAbstract* getDate() const = 0;

        /*
        * Get the Month of the Point
        * @return
        *      Month of the Point.
        */
        virtual int getMonth() const = 0;

        /*
        * Get the Day of the Point
        * @return
        *      Day of the Point.
        */
        virtual int getDay() const = 0;

        /*
        * Get the Banner of the Point Parsed
        * @return
        *      String of Parsed Banner
        */
        virtual std::string getBannerParsed() const = 0;

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

        /*
        * Print Point
        */
       virtual std::ostream& print(std::ostream& os) const = 0 ;

       friend std::ostream& operator<<(std::ostream& os, const Point& toPrint);

        // D'tor
        virtual ~Point() {}

    protected:
        int m_year;
        std::shared_ptr<Banner> m_bannerInPoint; // For polymorphic purposes
        // TODO: Hopefully study and find way such that there's no m_banner in Event/Reminder/Task
        //       only here

        static const int EMPTY_ARG = -2;
        static const std::string::size_type DESCRIPTION_START_LENGTH = 40;

        bool addSpaceAfterDay(const int day) const;

        std::string textStart(const std::string text, const std::string::size_type length) const;

};

#endif