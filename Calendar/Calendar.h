#ifndef CALENDAR_H
#define CALENDAR_H

#include "../Points/Point.h"
#include "../Points/Event.h"
#include "../Points/Reminder.h"
#include "../Points/Task.h"
#include "../Date/DateAbstract.h"
#include "../Date/Date.h"
#include "../Date/DateDeadline.h"
#include "../Date/DateRange.h"
#include "../Banner/Banner.h"
#include "../Banner/BannerEvent.h"
#include "../Banner/BannerTask.h"
#include "../Banner/BannerReminder.h"
#include "../utilities.h"
#include "../Exception.h"

#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <list>
#include <vector>
#include <array>
#include <ctime>


class Calendar {

public:

    enum class FORMAT {SHOW_ALL, SHOW_POINTS, SHOW_EVENTS, SHOW_REMINDERS, SHOW_TASKS};

    /*
    * C'tor of Calendar class
    *
    * @return
    *      A new instance of Calendar.
    */
    Calendar();

    /*
    * Add BannerEvent to Calendar
    * @param title - title of Banner (for Event)
    * @param location - location of Banner (for Event)
    * @param description - description of Banner (for Event)
    */
   void addBannerEvent(const std::string title, const std::string location, const std::string description);

    /*
    * Add BannerTask to Calendar
    * @param title - title of Banner (for Event)
    * @param urgency - urgency of Banner (for Event)
    * @param description - description of Banner (for Event)
    */
   void addBannerTask(const std::string title, const int urgency, const std::string description);

    /*
    * Add BannerReminder to Calendar
    * @param title - title of Banner (for Event)
    * @param location - location of Banner (for Event)
    * @param description - description of Banner (for Event)
    */
   void addBannerReminder(const std::string title, const std::string location, const std::string description);

    /*
    * Add Event to Calendar
    * @param banner - Banner of Event, contains title and description
    * @param month - The month of the Event
    * @param day - The day of the Event
    * @param timeStart - The timeStart of the Event
    * @param timeEnd - The timeEnd of the Event
    */
   void addEvent(std::shared_ptr<BannerEvent> banner, const int month, const int day,
        const int timeStart, const int timeEnd);

    /*
    * Add Task to Calendar
    * @param banner - Banner of Event, contains title and description
    * @param month - The month of the Event
    * @param day - The day of the Event
    * @param deadline - The timeStart of the Event
    */
   void addTask(std::shared_ptr<BannerTask> banner, const int month, const int day,
        const int deadline);

    /*
    * Add Reminder to Calendar
    * @param banner - Banner of Event, contains title and description
    * @param month - The month of the Event
    * @param day - The day of the Event
    */
   void addReminder(std::shared_ptr<BannerReminder> banner, const int month, const int day);


    /*
    * Print Calendar.
    */
    void print(std::ostream& os) const;

    /*
    * Compare two unique_ptr to Point
    * @param ptr1 - first pointer
    * @param ptr2 - second pointer
    * @return
    *      true: ptr1 < ptr2 || false: !(ptr1 < ptr2)
    */
    static bool pointCompare(const std::unique_ptr<Point>& ptr1, const std::unique_ptr<Point>& ptr2) {
        return *ptr1 < *ptr2;
    }

    friend std::ostream& operator<<(std::ostream& os, const Calendar& calendar);

    Calendar(const Calendar& calendar) = delete;
    Calendar& operator=(const Calendar& calendar) = delete;

private:
    std::string m_fileName = "database.txt";
    int m_year;
    int* m_daysInMonth;
    std::list<std::unique_ptr<Point>> m_points;
    std::vector<std::shared_ptr<Banner>> m_banners;

    /*
    * Create database.txt file
    */
    void createDatabase() const;

    /*
    * Print month titles (not including) prev until curr
    * @param os - OS onto which we are printing
    * @param prev - (NOT printed) previous month
    * @param curr - current month
    */
    void printMonthTitles(std::ostream& os, const int prev, const int curr) const;

    /*
    * Print month titles (not including) prev until (not including) curr
    * @param os - OS onto which we are printing
    * @param prev - (NOT printed) previous day
    * @param curr - (NOT printed) current day
    * @param month - Month which the days belong
    */
    void printEmptyDayRanges(std::ostream& os, const int prev, const int curr, const int month) const;
};

#endif