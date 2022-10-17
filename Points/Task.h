#ifndef TASK_H
#define TASK_H

#include "./Point.h"
#include "../utilities.h"
#include "../Exception.h"
#include "../Date/DateDeadline.h"
#include "../Banner/Banner.h"
#include "../Banner/BannerTask.h"
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
    Task(std::shared_ptr<BannerTask> banner, const int year, const int month, const int day,
             const int deadline);


    /*
    * Edit date
    * @param newMonth - The new month for the point
    * @param newDay - The new day for the point
    * @param newDeadline - The new deadline for the point
    */
    void updateDate(const int newMonth, const int newDay,
                    const int arg1 = Point::EMPTY_ARG, const int arg2 = Point::EMPTY_ARG) override;

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
    * Get the Date of the Point
    * @return
    *      Date of the Point.
    */
    DateAbstract* getDate() const override;

    /*
    * Get the Month of the Point
    * @return
    *      Month of the Point.
    */
    int getMonth() const override;

    /*
    * Get the Day of the Point
    * @return
    *      Day of the Point.
    */
    int getDay() const override;

    /*
    * Get the Banner of the Point Parsed
    * @return
    *      String of Parsed Banner
    */
    std::string getBannerParsed() const override;

    /*
    * Print Reminder
    */
    std::ostream& print(std::ostream& os) const override;

    ~Task() {}

private:
    std::unique_ptr<DateDeadline> m_date;
    std::shared_ptr<BannerTask> m_banner;
    bool m_complete = false;
    
};

#endif