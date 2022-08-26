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
#include <memory>
#include <list>
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
    * Add Event to Calendar
    * @param title - The title of the Event
    * @param month - The month of the Event
    * @param day - The day of the Event
    * @param timeStart - The timeStart of the Event
    * @param timeEnd - The timeEnd of the Event
    * @param repeat - The repeat of the Event
    * @param repeatArray - The repeatArray of the Event
    * @param repeatAmount - The repeatAmount of the Event
    * @param description - The description of the Event
    */
   void addEvent(const std::string title, const int month, const int day,
        const int timeStart, const int timeEnd, const bool repeat, const std::string repeatArray, 
        const int repeatAmount, const std::string description);

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
    std::list<std::shared_ptr<Point>> m_points;

    /*
    * Create database.txt file
    */
    void createDatabase() const;
};

#endif