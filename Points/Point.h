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
        * Edit location
        * @param newLocation - The new location
        */
        void updateLocation(const std::string newLocation);

        /*
        * @return
        *      title of banner.
        */
        std::string getLocation() const;

        /*
        * Edit location
        * @param newLocation - The new location for the point
        */
        void updateUrgency(const int newUrgency);

        /*
        * @return
        *      urgency
        */
        int getUrgency() const;

        /*
        * Mark task as complete
        */
        void markComplete();

        /*
        * Mark task as incomplete
        */
        void markIncomplete();

        /*
        * @return
        *      true: task is complete || false: task is incomplete
        */
        bool getComplete() const;

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
        * Get the Banner of the Point - Parsed
        * @return
        *      String of Parsed Banner
        */
        std::string getBannerParsed() const;

        /*
        * Get the Banner of the Point - Pointer
        * @return
        *      String of Parsed Banner
        */
        std::shared_ptr<Banner> getBanner(); // const??

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
        std::shared_ptr<Banner> m_banner;
        bool m_complete = false;

        static const int EMPTY_ARG = -2;
        static const std::string::size_type DESCRIPTION_START_LENGTH = 40;

        bool addSpaceAfterDay(const int day) const;

        std::string textStart(const std::string text, const std::string::size_type length) const;

};

#endif