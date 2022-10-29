#include "./tests.h"
#include "./utilities.h"
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

    std::string myString = "";
    do {
        std::cout << "Press ENTER to continue" << std::endl;
        std::getline(std::cin, myString);
    } while (myString.length() != 0);
    system("clear");
    // START
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int day = aTime->tm_mday;
    int month = aTime->tm_mon; // 0 <--> January
    calendar.selectFirstPointAfterDate(3, 6); // TODO: Test
    //
    // std::cout << calendar << std::endl;
    //

    std::cout << "\n day" << day << " month: "<< month << std::endl;
    std::cout << calendar.printMonthSimplified();

    return 0;
}