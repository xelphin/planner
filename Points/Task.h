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

    static const int DATE_VARIABLE_AMOUNT = 4;
    static const int FULL_AMOUNT_BANNER_WITH_BASE_DATE = 8;
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
    * Print Point's info in editing format
    * (editing format: format used by graphic_bannerEdit)
    * @param maxAvailable - The max available index for editing
    * @param pointType - The max available index for editing
    */
    std::string printInfo_editingFormat(int& maxAvailable, pointsInfo::TYPE& pointType) const override;

    /*
    * Get Attribute that matches index in printInfo_editingFormat()
    * (editing format: format used by graphic_bannerEdit)
    * @param index - Index selected from printInfo_editingFormat()
    */
    pointsInfo::EDIT getAttribute_editingFormat(const int index) const override;
    
    /*
    * Print Reminder
    */
    std::ostream& print(std::ostream& os) const override;
    std::string printToString(const bool withArrow) const override;

    /*
    * Parse point fully with banner, date and other unique date
    */
    std::string parsePointToTextFull() const override;

    /*
    * Parse point fully with date and other unique date
    */
    std::string parsePointToText() const override;

    ~Task() {}

private:
    std::unique_ptr<DateDeadline> m_date;
    
};

#endif