#ifndef BANNER_TASK_H
#define BANNER_TASK_H

#include <string>
#include <iostream>
#include <memory>
#include <list>
#include "../Exception.h"
#include "./Banner.h"

class BannerTask : public Banner {

    public:
        /*
        * C'tor of BannerEvent class
        *
        * @return
        *      A new instance of BannerEvent.
        */
        BannerTask(const std::string title, const int urgency,  const std::string description);

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

        // D'tor
        ~BannerTask() {}


    private:
        int m_urgency;
        static const int MIN_URGENCY = 1;
        static const int MAX_URGENCY = 5;
        static const int UNDEFINED_URGENCY = 0;

};

#endif