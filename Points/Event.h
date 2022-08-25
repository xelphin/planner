#ifndef EVENT_H
#define EVENT_H

#include "./Event.h"
#include "./Point.h"
#include "../utilities.h"
#include "../Date/DateRange.h"
#include <iostream>
#include <string>
#include <memory>
#include <list>

class Event : public Point {
public:
    /*
     * C'tor of Event class
     *
     * @param name - Event's name.
     * @return
     *      A new instance of Event.
    */
    Event(const std::string title, const int year, const int month, const int day,
        const int timeStart, const int timeEnd, const bool repeat, const std::string repeatArray, 
        const int repeatAmount, const std::string description);

    /*
    * Edit date
    * @param newMonth - The new month for the point
    * @param newDay - The new day for the point
    * @param newStart - The new timeStart for the point
    * @param newEnd - The new timeEnd for the point
    */
    void updateDate(const int newMonth, const int newDay, const int newStart, const int newEnd) override;

    /*
    * Add date where Event will be repeated
    * @param times - Array with data of new date
    */
    void addRepeat(const int times[]) override;

    ~Event() {}

private:
    std::unique_ptr<DateRange> m_date;
    
};

#endif