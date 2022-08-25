#ifndef CALENDAR_H
#define CALENDAR_H

#include "./Points/Point.h"
#include "./Points/Event.h"
#include "./Points/Reminder.h"
#include "./Points/Task.h"
#include "./Date/DateAbstract.h"
#include "./Date/Date.h"
#include "./Date/DateDeadline.h"
#include "./Date/DateRange.h"
#include "./utilities.h"
#include "./Exception.h"

#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <memory>
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
        * Print Calendar.
        */
        friend std::ostream& operator<<(std::ostream& os, const Calendar& calendar);

        Calendar(const Calendar& calendar) = delete;
        Calendar& operator=(const Calendar& calendar) = delete;

    private:
        std::string m_fileName = "database.txt";
        int m_year;
        int* m_daysInMonth;
        std::list<std::unique_ptr<Point>> m_points;

        /*
        * Create database.txt file
        */
       void createDatabase() const;
};

#endif