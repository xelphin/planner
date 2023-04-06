#ifndef GRAPHIC_BANNER_CREATOR_H
#define GRAPHIC_BANNER_CREATOR_H

#include <string>
#include <iostream>
#include <cmath>
#include <array>
#include "../Calendar/Calendar.h"
#include "./graphic_prints.h"

namespace graphics {
    /*
    * Start process for new Banner creation.
    * @param calendar - reference to Calendar
    * @return: true: successfully created banner | false: process incomplete
    */
    bool mainBannerCreationProcess(Calendar& calendar);
}




#endif