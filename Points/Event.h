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
    * Edit date
    * @param newMonth - The new month for the point
    * @param newDay - The new day for the point
    * @param newStart - The new timeStart for the point
    * @param newEnd - The new timeEnd for the point
    */
    void updateDate(const int newMonth, const int newDay,
                    const int newStart = Point::EMPTY_ARG, const int newEnd= Point::EMPTY_ARG) override;

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
    * Print Event
    */
    std::ostream& print(std::ostream& os) const override;

    ~Event() {}

private:
    std::unique_ptr<DateRange> m_date;
    std::shared_ptr<BannerEvent> m_banner;
    
    
};

#endif