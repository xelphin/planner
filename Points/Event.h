#ifndef EVENT_H
#define EVENT_H

#include "./Point.h"
#include "../utilities.h"
#include "../Exception.h"
#include "../Date/DateRange.h"
#include "../Banner/Banner.h"
#include "../Banner/BannerEvent.h"
#include <iostream>
#include <string>
#include <memory>
#include <list>

class Event : public Point {
public:

    static const int DATE_VARIABLE_AMOUNT = 4;
    /*
     * C'tor of Event class
     *
     * @param name - Event's name.
     * @return
     *      A new instance of Event.
    */
    Event(std::shared_ptr<BannerEvent> banner, const int year, const int month, const int day,
        const int timeStart, const int timeEnd);

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
    * @param newStart - The new timeStart for the point
    * @param newEnd - The new timeEnd for the point
    */
    void updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd) override;

    DateAbstract* getDate() const override;

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
    * Print Event
    */
    std::ostream& print(std::ostream& os) const override;

    ~Event() {}

private:
    std::unique_ptr<DateRange> m_date;
    std::shared_ptr<BannerEvent> m_banner;
    
    
};

#endif