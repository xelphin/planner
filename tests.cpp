
#include "./tests.h"

/* Avoids Console Printing If Not Debugging */

#ifdef NDEBUG // I DONT want to debug
void printFail ();
void printSuccess ();
#define printFail() ((void)0)
#define printSuccess() ((void)0)
#else // I DO want to debug
#define printFail() (std::cout<< test_name <<" FAILED."<<std::endl)
#define printSuccess() (std::cout<< test_name <<" SUCCESS."<<std::endl)
#endif

void run_all_tests() {
    run_test(utilities_amountDaysInMonth, "utilities_amountDaysInMonth");
    run_test(utilities_validDate, "utilities_validDate");
    run_test(utilities_checkValidTime, "utilities_checkValidTime");
    run_test(utilities_checkValidTimeRange, "utilities_checkValidTimeRange");
    run_test(date_createDate, "date_createDate");
    run_test(date_updateDate, "date_updateDate");
    run_test(dateDeadline_createDate, "dateDeadline_createDate");
    run_test(dateDeadline_updateDate, "dateDeadline_updateDate");
    run_test(dateRange_createDate, "dateRange_createDate");
    run_test(dateRange_updateDate, "dateRange_updateDate");
    run_test(date_operators, "date_operators");
}

void run_test(std::function<bool()> test, std::string test_name)
{
    if(!test()){
        printFail();
        std::cout << std::endl;
        return;
    }
    printSuccess();
    std::cout << std::endl;
}

bool compareFiles(const std::string &filename1, const std::string &filename2)
{
    std::string line1,line2;
    std::fstream file1(filename1),file2(filename2);
    if( !file2){
         std::cerr<<"Error opening file 2" << std::endl;
         return false;
    }
	if(!file1 ){
         std::cerr << "Error opening file 1" << std::endl;
         return false;
    }
    while(!file1.eof()){ //read file until you reach the end
        getline(file1,line1);
        getline(file2,line2);
        if(!(line1==line2))
        {
            return false;
        }
    }
    if(!file2.eof()){
        return false;
    }
    return true;
}

void deleteTextFile(const std::string &filename)
{
    std::remove(filename.c_str());
}

// ----------------------------- TESTS -----------------------------


bool utilities_amountDaysInMonth()
{
    int count = 0;
    count += amountDaysInMonth(2022,1) == 31;
    count += amountDaysInMonth(2022,2) == 28;
    count += amountDaysInMonth(2024,2) == 29;
    count += amountDaysInMonth(2022,3) == 31;
    count += amountDaysInMonth(2022,4) == 30;
    count += amountDaysInMonth(2022,5) == 31;
    count += amountDaysInMonth(2022,6) == 30;
    count += amountDaysInMonth(2022,7) == 31;
    count += amountDaysInMonth(2022,8) == 31;
    count += amountDaysInMonth(2022,9) == 30;
    count += amountDaysInMonth(2022,10) == 31;
    count += amountDaysInMonth(2022,11) == 30;
    count += amountDaysInMonth(2022,12) == 31;
    return count == 13;
}

bool utilities_validDate()
{
    int count = 0;
    count += validDate(2022,12,1) == true;
    count += validDate(2022,13,1) == false;
    count += validDate(2022,-1,1) == false;
    count += validDate(2022,12,32) == false;
    count += validDate(2022,12,31) == true;
    count += validDate(2022,11,31) == false;
    count += validDate(2024,2,29) == true;
    count += validDate(2023,2,29) == false;
    count += validDate(2023,0,2) == false;
    count += validDate(2023,1,2) == true;
    return count == 10;
}

bool utilities_checkValidTime()
{
    int count = 0;
    count += checkValidTime(1220) == true;
    count += checkValidTime(0) == true;
    count += checkValidTime(1440) == true;
    count += checkValidTime(1441) == false;
    count += checkValidTime(-1) == false;
    return count == 5;
}

bool utilities_checkValidTimeRange()
{
    int count = 0;
    count += checkValidTimeRange(1220, 1225) == true;
    count += checkValidTimeRange(1225, 1220) == false;
    count += checkValidTimeRange(1220, 1440) == true;
    count += checkValidTimeRange(1220, 1441) == false;
    count += checkValidTimeRange(0, 0) == true;
    count += checkValidTimeRange(20, 20) == true;
    count += checkValidTimeRange(-1, 1225) == false;
    count += checkValidTimeRange(10, 100) == true;
    return count == 8;
}

bool date_createDate()
{
    Date date(2022,12,4);
    Date date2(2024,2,29);
    try {
        Date date3(2023,2,29);
    } catch(const InvalidDate&) {
        return true;
    }
    return false;
}

bool date_updateDate()
{
    Date date(2022,12,4);
    date.updateDate(3,23);
    int count = 0;
    try {
        date.updateDate(3,32);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        date.updateDate(4,31);
    } catch(const InvalidDate&) {
        count++;
    }
    return count == 2;
}

bool date_operators()
{
    int year = 2022;
    Date date1(year,3,14);
    Date date2(year,5,14);
    Date date3(year,2,16);
    Date date4(year,8,2);
    Date date5(year,5,14);
    int count = 0;
    count += (date2==date5) == true;
    count += (date2==date1) == false;
    count += (date2 < date1) == false;
    count += (date2 > date1) == true;
    count += (date1 < date2) == true;
    count += (date1 > date2) == false;
    count += (date4 != date2) == true;
    count += (date4 != date3) == true;
    count += (date2 <= date5) == true;
    count += (date5 <= date2) == true;
    count += (date5 >= date2) == true;
    count += (date5 >= date4) == false;
    return count == 12;
}

bool dateDeadline_createDate()
{
    DateDeadline date(2022,12,4,1200);
    DateDeadline date2(2024,2,29,60);
    int count = 0;
    try {
        DateDeadline date3(2023,2,29,100);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        DateDeadline date4(2023,2,28,1441);
    } catch(const InvalidDate&) {
        count++;
    }
    return count == 2;
}

bool dateDeadline_updateDate()
{
    DateDeadline date(2022,12,4, 600);
    date.updateDate(3,23,500);
    int count = 0;
    try {
        date.updateDate(3,32,500);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        date.updateDate(4,31,500);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        date.updateDate(4,3,1600);
    } catch(const InvalidDate&) {
        count++;
    }
    return count == 3;
}

bool dateRange_createDate()
{
    DateRange date(2022,12,4,1200,1250);
    DateRange date2(2024,2,29,60,60);
    int count = 0;
    try {
        DateRange date3(2023,2,29,100,100);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        DateRange date4(2023,2,28,1441,1442);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        DateRange date4(2023,2,28,80,60);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        DateRange date4(2023,2,28,-1,60);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        DateRange date4(2023,2,28,100,1600);
    } catch(const InvalidDate&) {
        count++;
    }
    return count == 5;
}

bool dateRange_updateDate()
{
    DateRange date(2022,12,4, 600, 800);
    date.updateDate(3,23,500,600);
    int count = 0;
    try {
        date.updateDate(3,32,500, 600);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        date.updateDate(4,31,500, 600);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        date.updateDate(4,3,1600, 1700);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        date.updateDate(4,3,1400, 1700);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        date.updateDate(4,3,-1, 500);
    } catch(const InvalidDate&) {
        count++;
    }
    try {
        date.updateDate(4,3, 500, 400);
    } catch(const InvalidDate&) {
        count++;
    }
    return count == 6;
}