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
#include "./Banner/BannerEvent.h"
#include "./Banner/BannerTask.h"
#include "./Banner/BannerReminder.h"
#include "./Calendar/Calendar.h"

#include <iostream>

int main() {
    run_all_tests();
    return 0;
}