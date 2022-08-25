#ifndef REMINDER_H
#define REMINDER_H

#include "./Point.h"
#include "../utilities.h"
#include "../Date/DateDeadline.h"
#include <iostream>
#include <string>
#include <memory>
#include <list>

class Reminder : public Point {
public:
    /*
     * C'tor of Reminder class
     *
     * @param name - Reminder's name.
     * @return
     *      A new instance of Reminder.
    */
    Reminder(const std::string title, const int year, const int month, const int day,
        const int deadline, const bool repeat, const std::string repeatArray, 
        const int repeatAmount, const std::string description);

    /*
    * Edit date
    * @param newMonth - The new month for the point
    * @param newDay - The new day for the point
    * @param newDeadline - The new deadline for the point
    */
    void updateDate(const int newMonth, const int newDay,
                    const int newDeadline, const int arg2 = Point::EMPTY_ARG) override;

    /*
    * Add date where Event will be repeated
    * @param times - Array with data of new date
    */
    void addRepeat(const int times[]) override;

    ~Reminder() {}

private:
    std::unique_ptr<DateDeadline> m_date;
    
};

#endif