#include "./tests.h"
#include "./utilities.h"
#include "./graphic_utilities/graphic_prints.h"
#include "./graphic_utilities/graphic_controls.h"
#include "./Exception.h"
#include "./Date/DateAbstract.h"
#include "./Date/Date.h"
#include "./Date/DateDeadline.h"
#include "./Date/DateRange.h"
#include "./Points/Point.h"
#include "./Points/Event.h"
#include "./Points/Reminder.h"
#include "./Points/Task.h"
#include "./Banner/Banner.h"
#include "./Calendar/Calendar.h"

#include <iostream>
#include <time.h>

int main() {
    if(!run_all_tests()) {
        std::cout << "Files have been corrupted" << std::endl;
        return 0;
    }
    system("clear");

    std::cout << "Creating Calendar:" << std::endl;
    Calendar calendar("database.txt");
    std::cout << "Done." << std::endl;

    graphics::action_pressEnterToContinue();
    // START
    int day=1;
    int month=0;
    getCurrMonthDay(month,day);
    calendar.selectFirstPointFromDate(month, day);


    // TODO:  graphic_selections
    // controls calendar selections (includes: Calendar, graphic_prints)
    // call it from here
    // std::cout << calendar.printMonthSimplified();
    graphics::idleReadAction(calendar);
    std::cout << "DONE" << std::endl;

    return 0;
}