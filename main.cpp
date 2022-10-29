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
    std::cout << calendar << std::endl;

    return 0;
}