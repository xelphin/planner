#ifndef REMINDER_H
#define REMINDER_H

#include "./Point.h"
#include "../utilities.h"
#include "../Exception.h"
#include "../Date/DateDeadline.h"
#include "../Banner/Banner.h"
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
    Reminder(std::shared_ptr<Banner> banner, const int year, const int month, const int day,
             const int deadline);

    /*
    * Edit date
    * @param newMonth - The new month for the point
    * @param newDay - The new day for the point
    * @param newDeadline - The new deadline for the point
    */
    void updateDate(const int newMonth, const int newDay,
                    const int newDeadline, const int arg2 = Point::EMPTY_ARG) override;

    ~Reminder() {}

private:
    std::unique_ptr<DateDeadline> m_date;
    
};

#endif