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
    * Returns string of Banner completion
    * @param success - success is true if the banner was completed successfully
    */
    std::string bannerCompletion(const bool success);

    /*
    * Returns string of invalid point selection
    */
    std::string invalidPointSelection();

    /*
    * Returns string of Point Creator
    */
    std::string pointCreatorString();

    /*
    * Returns string of Point Editor
    */
    std::string pointEditorString();

    /*
    * Returns string asking to enter title
    * @param pointType - Type of point: Event, Reminder or Task
    */
    std::string promptPointTitle(const std::string pointType);

    /*
    * Returns string asking to enter description
    * @param pointType - Type of point: Event, Reminder or Task
    */
    std::string promptPointDescription(const std::string pointType);

    /*
    * Returns string asking to enter location
    * @param pointType - Type of point: Event, Reminder or Task
    */
    std::string promptPointLocation(const std::string pointType);

    /*
    * Returns string asking to enter urgency
    * @param pointType - Type of point: Event, Reminder or Task
    */
    std::string promptPointUrgency(const std::string pointType);

    /*
    * Returns string asking to enter month/day
    * @param pointType - Type of point: Event, Reminder or Task
    */
    std::string promptPointMonthDay();

    /*
    * Returns string asking to enter time
    * @param pointType - Type of point: Event, Reminder or Task
    * @param type - Type of time: time start, time end, deadline
    */
    enum class TIME_TYPE {TIMESTART, TIMEEND, DEADLINE};
    std::string promptPointTime(const std::string pointType, const graphics::TIME_TYPE type);

    /*
    * Returns string asking to enter time start
    * @param pointType - Type of point: Event, Reminder or Task
    */
   std::string promptTimeStart(const std::string pointType);

    /*
    * Returns string asking to enter time end
    * @param pointType - Type of point: Event, Reminder or Task
    */
   std::string promptTimeEnd(const std::string pointType);

    /*
    * Returns string asking to enter deadline
    * @param pointType - Type of point: Event, Reminder or Task
    */
   std::string promptDeadline(const std::string pointType);

    /*
    * Returns string asking for repetition date or 'n' for disinterested
    */
   std::string promptRepetitions();

    /*
    * Returns string asking for index for attribute
    * @param maxIndex - max index available for attribute
    */
   std::string promptIndexOfAttribute(const int maxIndex);

    /*
    * Returns string showing current version of type
    * @param type - type of value
    * @param currValue - the current value
    */
    std::string strCurrentVersion(const std::string type, const std::string currValue);


    /*
    * Returns string notifying that the process stopped without midway
    * @param processName - Name of process stopped (example: "editing", "creating")
    */
    std::string strStoppedProcess(const std::string processName);
}




#endif