#ifndef REMINDER_H
#define REMINDER_H

#include "./Point.h"
#include "../utilities.h"
#include "../Exception.h"
#include "../Date/Date.h"
#include "../Banner/Banner.h"
#include "../Banner/BannerReminder.h"
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
    Reminder(std::shared_ptr<BannerReminder> banner, const int year, const int month, const int day);

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
    * Edit location
    * @param newLocation - The new location
    */
    void updateLocation(const std::string newLocation);

    /*
    * @return
    *      title of banner.
    */
    std::string getLocation() const;

    /*
    * Print Reminder
    */
    std::ostream& print(std::ostream& os) const override;

    ~Reminder() {}

private:
    std::unique_ptr<Date> m_date;
    std::shared_ptr<BannerReminder> m_banner;
    
};

#endif