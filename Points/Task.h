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
    * Edit title
    * @param newTitle - The new title for the point
    */
    void updateTitle(const std::string newTitle) override;

    /*
    * @return
    *      Title of banner.
    */
    std::string getTitle() const override;

    /*
    * Edit description
    * @param newDescription - The new description
    */
    void updateDescription(const std::string newDescription) override;

    /*
    * @return
    *      Description of banner.
    */
    std::string getDescription() const override;

    /*
    * Edit date
    * @param newMonth - The new month for the point
    * @param newDay - The new day for the point
    */
    void updateDate(const int newMonth, const int newDay,
                    const int arg1 = EMPTY_ARG, const int arg2 = EMPTY_ARG) override;

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

    DateAbstract* getDate() const override;

    ~Task() {}

private:
    std::unique_ptr<DateDeadline> m_date;
    std::shared_ptr<BannerTask> m_banner;
    
};

#endif