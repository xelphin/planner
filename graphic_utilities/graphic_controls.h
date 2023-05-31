#ifndef GRAPHIC_CONTROLS_H
#define GRAPHIC_CONTROLS_H

#include <string>
#include <iostream>
#include <cmath>
#include <array>
#include "../Calendar/Calendar.h"
#include "./graphic_prints.h"
#include "./graphic_bannerCreator.h"
#include "./graphic_bannerEdit.h"

// TODO: Most likely turn all of graphic_ into one class. 
// ALTHOUGH, it's kinda like my 'main' is the class and graphics are its function because graphics is so high.
// So, unsure of which way to go

namespace graphics {

    enum class ACTION {L,R,U,D, NONE, EDIT, CREATE, REMOVE, SAVE_AND_EXIT};

    /*
    * Translate from action character to enum
    * @param action - 'a', 'd' , 'w', 's', 'e', 'c', 'r', 'x'
    */
    graphics::ACTION characterToAction(const char& action);

    /*
    * Waits idly for action and then when received redirects to act accordingly
    */
    void idleReadAction(Calendar& calendar);

    /*
    * Select closest Point that is in requested action
    * @param calendar - reference to Calendar
    * @param action - 'a', 'd' , 'w', 's'
    * @return: true: valid action | false: invalud action
    */
    bool apllyAction(Calendar& calendar, const char& action_char);
}




#endif