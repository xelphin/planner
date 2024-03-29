#ifndef BANNER_H
#define BANNER_H

#include <string>
#include <iostream>
#include <memory>
#include <list>
#include "../Exception.h"

/**
 * WHAT
 * A Banner represents the shared data of its various Points. 
 * It is a representation of an occassion, an example is a Volleyball game.
 * It will hold the title, description, location...
 * The Points of it will represent the actual instances in the Calendar of it,
 * for example, if it repeats every week, then there will be a Point for each week.
*/

class Banner {

    public:

        enum class TYPE {EVENT, TASK, REMINDER, INVALID};

        /*
        * Turns Banner::TYPE as string
        * @param type - type as enum
        * @return
        *   type as string
        */
        static std::string typeToString(Banner::TYPE type);

        /*
        * C'tor of Banner class
        *
        * @return
        *      A new instance of Banner.
        */
        Banner(const Banner::TYPE type, const std::string title, const std::string description, const std::string location, const int urgency);

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

        /*
        * @return
        *      Banner type as text
        */
       std::string getBannerTypeString() const;

        // D'tor
        ~Banner() {}


    private:
        TYPE m_type;
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