#ifndef BANNER_H
#define BANNER_H

#include <string>
#include <iostream>
#include <memory>
#include <list>
#include "../Exception.h"

class Banner {

    public:
        /*
        * C'tor of Banner class
        *
        * @return
        *      A new instance of Banner.
        */
        Banner(const std::string title, const std::string description, const std::string location, const int urgency);

        /*
        * Edit title
        * @param newTitle - The new title for the point
        */
       void updateTitle(const std::string newTitle);

        /*
        * @return
        *      Title of banner.
        */
       std::string getTitle() const;

        /*
        * Edit description
        * @param newDescription - The new description
        */
       void updateDescription(const std::string newDescription);

        /*
        * @return
        *      Description of banner.
        */
       std::string getDescription() const;

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
        * Edit urgency
        * @param newUrgency - The new urgency for the point
        */
       void updateUrgency(const int newUrgency);

        /*
        * @return
        *      urgency
        */
       int getUrgency() const;

        /*
        * @return
        *      Banner in the format expected for database.txt
        */
       std::string getBannerParsed() const;

        // D'tor
        ~Banner() {}


    private:
        std::string m_title;
        std::string m_description;
        std::string m_location;
        int m_urgency;

        static const int MIN_TITLE_LENGTH = 1;
        static const int MAX_TITLE_LENGTH = 40;
        static const int MIN_DESCRIPTION_LENGTH = 0;
        static const int MAX_DESCRIPTION_LENGTH = 400;
        static const int MIN_BANNER_EVENT_LOCATION_LENGTH = 0; // TODO: change name
        static const int MAX_BANNER_EVENT_LOCATION_LENGTH = 60;
        static const int MIN_URGENCY = 1;
        static const int MAX_URGENCY = 5;
        static const int UNDEFINED_URGENCY = 0;

};

#endif