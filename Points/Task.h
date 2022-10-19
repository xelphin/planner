#ifndef TASK_H
#define TASK_H

#include "./Point.h"
#include "../utilities.h"
#include "../Exception.h"
#include "../Date/DateDeadline.h"
#include "../Banner/Banner.h"
#include <iostream>
#include <string>
#include <memory>
#include <list>

class Task : public Point {
public:
    /*
     * C'tor of Task class
     *
     * @param name - Task's name.
     * @return
     *      A new instance of Task.
    */
    Task(std::shared_ptr<Banner> banner, const int year, const int month, const int day,
             const int deadline, const bool completed);

    
    /*
    * Edit date
    * @param newMonth - The new month for the point
    * @param newDay - The new day for the point
    * @param newDeadline - The new deadline for the point
    */
    void updateDate(const int newMonth, const int newDay,
                    const int arg1 = Point::EMPTY_ARG, const int arg2 = Point::EMPTY_ARG) override;




    /*
    * Get the Date of the Point
    * @return
    *      Date of the Point.
    */
    DateAbstract* getDate() const override;
    
    /*
    * Print Reminder
    */
    std::ostream& print(std::ostream& os) const override;

    ~Task() {}

private:
    std::unique_ptr<DateDeadline> m_date;
    
};

#endif