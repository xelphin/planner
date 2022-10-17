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
        Banner(const std::string title, const std::string description);

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
        * @return
        *      Banner in the format expected for database.txt
        */
       virtual std::string getBannerParsed() const = 0;

        // D'tor
        virtual ~Banner() {}


    protected:
        std::string m_title;
        std::string m_description;

        static const int MIN_TITLE_LENGTH = 1;
        static const int MAX_TITLE_LENGTH = 40;
        static const int MIN_DESCRIPTION_LENGTH = 0;
        static const int MAX_DESCRIPTION_LENGTH = 400;

};

#endif