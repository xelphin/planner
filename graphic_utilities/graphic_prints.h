#ifndef GRAPHIC_PRINTS_H
#define GRAPHIC_PRINTS_H

#include <string>
#include <iostream>
#include <cmath>
#include <array>

namespace graphics {
    /*
    * Returns string of bar and new line
    */
    std::string decorativeBar();

    /*
    * Waits till user presses ENTER and clears screen
    */
    void action_pressEnterToContinue();

    /*
    * Returns string of spaces
    */
    std::string spaces(const int amount);

    /*
    * Returns string of a Calendar title
    */
    std::string calendarTitle();

    /*
    * Returns string of action bar
    */
    std::string actionBar();


    /*
    * Returns string of instruction 
    */
    std::string instructions();

    /*
    * Returns string of selection between which Point to add 
    */
    std::string promptWhichPointToAdd();

    /*
    * Returns string of Point options
    */
    std::string pointOptions();

    /*
    * Returns string of invalid point selection
    */
    std::string invalidPointSelection();
}




#endif