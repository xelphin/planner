#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <random>
#include <array>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <functional>

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


// --RUN TESTS
void run_all_tests();

// --UTILITIES
void run_test(std::function<bool()> test, std::string test_name);
bool compareFiles(const std::string &filename1, const std::string &filename2);
void deleteTextFile(const std::string &filename);
std::string readFileIntoString(const std::string& path);

// --TESTS

// UTILITIES
bool utilities_amountDaysInMonth();
bool utilities_validDate();
bool utilities_checkValidTime();
bool utilities_checkValidTimeRange();
bool utilities_checkParseStringToArray();

// DATE
bool date_createDate();
bool date_updateDate();
bool date_operators();
// DATE_DEADLINE
bool dateDeadline_createDate();
bool dateDeadline_updateDate();
bool dateDeadline_operators();
// DATE_RANGE
bool dateRange_createDate();
bool dateRange_updateDate();
bool dateRange_operators();
// DATE COMPARISONS
bool dateAll_operators();

// POINT
// EVENT
bool event_createEvent();
// REMINDER
bool reminder_createReminder();
// TASK
bool task_createTask();

// CALENDAR
bool calendar_createCalendar();
bool calendar_createNewBannerType();
bool calendar_parseCalendarToDatabase();

#endif