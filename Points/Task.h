#ifndef TASK_H
#define TASK_H

#include "./Point.h"
#include "../utilities.h"
#include "../Date/Date.h"
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
    Task(const std::string title, const int year, const int month, const int day,
         const bool repeat, const std::string repeatArray, 
         const int repeatAmount, const std::string description);

    /*
    * Edit date
    * @param newMonth - The new month for the point
    * @param newDay - The new day for the point
    */
    void updateDate(const int newMonth, const int newDay,
                    const int arg1 = EMPTY_ARG, const int arg2 = EMPTY_ARG) override;

    /*
    * Add date where Task will be repeated
    * @param times - Array with data of new date
    */
    void addRepeat(const int times[]) override;

    ~Task() {}

private:
    std::unique_ptr<Date> m_date;
    
};

#endif