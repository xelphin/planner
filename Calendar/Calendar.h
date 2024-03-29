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
    Calendar(std::string databaseName = "database.txt");

    /*
    * C'tor of Calendar class
    *
    * @return
    *      A new instance of Calendar.
    */
    int getYear() const;

    /*
    * Add new BannerEvent to Calendar
    * @param title - title of Banner (for Event)
    * @param location - location of Banner (for Event)
    * @param description - description of Banner (for Event)
    * @param month - The month of the Event
    * @param day - The day of the Event
    * @param timeStart - The timeStart of the Event
    * @param timeEnd - The timeEnd of the Event
    */
   void createNewBannerEvent(const std::string title, const std::string location, const std::string description, const int urgency,
    const int month, const int day, const int timeStart, const int timeEnd);

    /*
    * Add new BannerTask to Calendar
    * @param title - title of Banner (for Event)
    * @param urgency - urgency of Banner (for Event)
    * @param description - description of Banner (for Event)
    * @param month - The month of the Event
    * @param day - The day of the Event
    * @param deadline - The timeStart of the Event
    */
   void createNewBannerTask(const std::string title, const std::string location, const std::string description, const int urgency,
    const int month, const int day, const int deadline, const bool completed);

    /*
    * Add new BannerReminder to Calendar
    * @param title - title of Banner (for Event)
    * @param location - location of Banner (for Event)
    * @param description - description of Banner (for Event)
    * @param month - The month of the Event
    * @param day - The day of the Event
    */
   void createNewBannerReminder(const std::string title, const std::string location, const std::string description, const int urgency,
    const int month, const int day);

    /*
    * Add Event to Calendar
    * @param banner - Banner of Event, contains title and description
    * @param month - The month of the Event
    * @param day - The day of the Event
    * @param timeStart - The timeStart of the Event
    * @param timeEnd - The timeEnd of the Event
    */
   void addEvent(std::shared_ptr<Banner> banner, const int month, const int day,
        const int timeStart, const int timeEnd);

    /*
    * Add Task to Calendar
    * @param banner - Banner of Event, contains title and description
    * @param month - The month of the Event
    * @param day - The day of the Event
    * @param deadline - The timeStart of the Event
    * @param completed - Whether the Task has been completed or not (used in parsing from .txt file)
    */
   void addTask(std::shared_ptr<Banner> banner, const int month, const int day,
        const int deadline, const bool completed);

    /*
    * Add Reminder to Calendar
    * @param banner - Banner of Event, contains title and description
    * @param month - The month of the Event
    * @param day - The day of the Event
    */
   void addReminder(std::shared_ptr<Banner> banner, const int month, const int day);

    /*
    * Get current Point that is selected (by user)
    *
    * @return
    *      shared_ptr to Point
    */
   std::shared_ptr<Point> getSelectedPoint() const; 
    // NOTE: I know that instead of m_selectedPoint, having an iterator type thing is better
    //       but I get leaks so I'm resorting to creating these not very economical functions

    /*
    * Move current Point (m_currPoint) to select (point to) the Point before (first earlier Point)
    */
    void selectEarlierPoint();

    /*
    * Move current Point (m_currPoint) to select (point to) the Point before (first earlier Point)
    * from a previous month (if it exists)
    */
    void selectEarlierPointFromAPreviousMonth();

    /*
    * Move current Point (m_currPoint) to select (point to) the Point after (first later Point)
    */
    void selectLaterPoint();

    /*
    * Move current Point (m_currPoint) to select (point to) the Point after (first later Point)
    * from an upcoming month (if it exists)
    */
    void selectLaterPointFromAnUpcomingMonth();

    /*
    * Move current Point (m_currPoint) to select (point to) the Point from or after 
    * the month/day arguments
    */
    void selectFirstPointFromDate(const int month, const int day);

    /*
    * Remove currently selected Point
    */
    void removeSelectedPoint();

    /*
    * Print Calendar.
    */
    void print(std::ostream& os) const;

    /*
    * Print Month.
    */
    std::string printMonth(const int month) const;

    /*
    * Print Month Simplified (from m_selectedPoint onwards).
    * A version where less relevant data is shown with [...]
    */
    std::string printMonthSimplified() const;

    // TODO: make private
    /*
    * Print the month
    * @param month - month to print
    * @param it - starting iterator over m_points (point to Point inside of requested month or inside of later month)
    * @param simplified - whether the print should be displayed in a simplified version or not
    * @param dayPreviousInSameMonth - 0: no previous day in same month || irrelevant (because not simplified)
    *                                 int>0: day of previous Point in same month
    * (previous Point: point that appears before m_selectedPoint) 
    * @return
    *      month as string
    */
    std::string printMonth_withIt(const int month, std::list<std::shared_ptr<Point>>::const_iterator& it,
     const bool simplified= false, const int dayPreviousInSameMonth = 0) const;

    /*
    * Compare two shared_ptr to Point
    * @param ptr1 - first pointer
    * @param ptr2 - second pointer
    * @return
    *      true: ptr1 < ptr2 || false: !(ptr1 < ptr2)
    */
    static bool pointCompare(const std::shared_ptr<Point>& ptr1, const std::shared_ptr<Point>& ptr2) {
        return *ptr1 < *ptr2;
    }

    friend std::ostream& operator<<(std::ostream& os, const Calendar& calendar);

    /*
    * Parse Calendar into database
    * -> Saves (parses) Calendar data into dabase file
    * -> Cleans Calendar data in memory (exit)
    */
   void parseCalendarToTextFile(const std::string& databaseName);

    Calendar(const Calendar& calendar) = delete;
    Calendar& operator=(const Calendar& calendar) = delete;

private:
    std::string m_fileName;
    int m_year;
    int* m_daysInMonth;
    std::list<std::shared_ptr<Point>> m_points;
    std::shared_ptr<Point> m_selectedPoint;

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
    std::string printMonthTitles(const int prev, const int curr) const;

    /*
    * Print month titles (not including) prev until (not including) curr
    * @param os - OS onto which we are printing
    * @param prev - (NOT printed) previous day
    * @param curr - (NOT printed) current day
    * @param month - Month which the days belong
    */
    std::string printEmptyDayRanges(const int prev, const int curr, const int month) const;

    /*
    * Parses text file into calendar (called from constructor)
    * @param file - database file where the first line has been already read
    */
    void parseTextFileToCalendar(std::ifstream& file);

    /*
    * Gets next line with text
    * @param file - database file 
    * @param line - line that is Point type
    * @param lineIndex - index of line in txt file
    */
    void getNextLineWithText(std::ifstream& file, std::string& line, int& lineIndex);

    /*
    * Parses text into Point
    * @param file - database file 
    * @param line - line that is Point type
    * @param lineIndex - index of line in txt file
    */
    void parseTextToPoint(std::ifstream& file, std::string& line, int& lineIndex);

    /*
    * Parses text into Event
    * @param file - database file 
    * @param line - line that is Event banner + base date
    * @param lineIndex - index of line in txt file
    */
    void parseTextToEvent(std::ifstream& file, std::string& line, int& lineIndex);

    /*
    * Parses text into Task
    * @param file - database file 
    * @param line - line that is Task banner + base date
    * @param lineIndex - index of line in txt file
    */
    void parseTextToTask(std::ifstream& file, std::string& line, int& lineIndex);

    /*
    * Parses text into Reminder
    * @param file - database file 
    * @param line - line that is Reminder banner + base date
    * @param lineIndex - index of line in txt file
    */
    void parseTextToReminder(std::ifstream& file, std::string& line, int& lineIndex);

    /*
    * Parses text into Event repetitions
    * ASSUMPTION: createNewBannerEvent() updates m_selectedPoint (was implemented this way)
    * @param file - database file 
    * @param line - line that is Event repetitions
    * @param lineIndex - index of line in txt file
    */
    void parseTextToEventRepetitions(std::ifstream& file, std::string& line, int& lineIndex);

    /*
    * Parses text into Task repetitions
    * ASSUMPTION: createNewBannerTask() updates m_selectedPoint (was implemented this way)
    * @param file - database file 
    * @param line - line that is Task repetitions
    * @param lineIndex - index of line in txt file
    */
    void parseTextToTaskRepetitions(std::ifstream& file, std::string& line, int& lineIndex);

    /*
    * Parses text into Reminder repetitions
    * ASSUMPTION: createNewBannerReminder() updates m_selectedPoint (was implemented this way)
    * @param file - database file 
    * @param line - line that is Reminder repetitions
    * @param lineIndex - index of line in txt file
    */
    void parseTextToReminderRepetitions(std::ifstream& file, std::string& line, int& lineIndex);

    /*
    * Extracts Point data from 'line' (generic)
    * @param line - line that is Point type
    * @param i - index of next extraction data variable
    * @param title - title of Banner 
    * @param location - location of Banner 
    * @param description - description of Banner 
    * @param urgency - urgency of Banner 
    * @param month - The month of the Event
    * @param day - The day of the Event
    */
    void extractPointData(std::string& line, int& i,
     std::string& title, std::string& location, std::string& description, int& urgency,
     int& month, int& day);

    /*
    * Removes Banner and all its assigned Points from Calendar and puts it in the 'database'
    * @param database - txt file where the Banner + its assigned Points are parsed into
    */
    void parseBannerToTextFile(std::ofstream& database);

    /*
    * Move current Point (m_currPoint) to select (point to) the first Point (earliest)
    */
    void selectFirstPoint();

};

#endif

// Q&A :
/*

- Why are the Points not implemented as a private data in Banner?
    Because otherwise it is difficult to do actions like printing and interacting with the Calendar
    (A Banner can have multiple Points dispersed across a timeline)

- Why does Calendar not have a Banner shared_ptr vector/list?
    Because I want that the moment no Points are pointing at the Banner that it will be erased,
    if Calendar is pointing at it as well, it won't get erased

*/