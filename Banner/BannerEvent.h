#ifndef BANNER_EVENT_H
#define BANNER_EVENT_H

#include <string>
#include <iostream>
#include <memory>
#include <list>
#include "../Exception.h"
#include "./Banner.h"

class BannerEvent : public Banner {

    public:
        /*
        * C'tor of BannerEvent class
        *
        * @return
        *      A new instance of BannerEvent.
        */
        BannerEvent(const std::string title, const std::string location, const std::string description);

        /*
        * Edit location
        * @param newLocation - The new location for the point
        */
       void updateLocation(const std::string newLocation);

        /*
        * @return
        *       location
        */
       std::string getLocation() const;

        /*
        * @return
        *      BannerEvent in the format expected for database.txt
        */
       std::string getBannerParsed() const override;

        // D'tor
        ~BannerEvent() {}


    private:
        std::string m_location;
        static const int MIN_BANNER_EVENT_LOCATION_LENGTH = 0;
        static const int MAX_BANNER_EVENT_LOCATION_LENGTH = 60;

};

#endif