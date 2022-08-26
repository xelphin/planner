
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
    run_test(utilities_checkParseStringToArray, "utilities_checkParseStringToArray");
    run_test(date_createDate, "date_createDate");
    run_test(date_updateDate, "date_updateDate");
    run_test(dateDeadline_createDate, "dateDeadline_createDate");
    run_test(dateDeadline_updateDate, "dateDeadline_updateDate");
    run_test(dateDeadline_operators, "dateDeadline_operators");
    run_test(dateRange_createDate, "dateRange_createDate");
    run_test(dateRange_updateDate, "dateRange_updateDate");
    run_test(dateRange_operators, "dateRange_operators");
    run_test(dateAll_operators, "dateAll_operators");
    run_test(event_createEvent, "event_createEvent");
    run_test(reminder_createReminder, "reminder_createReminder");
    run_test(task_createTask, "task_createTask");
    run_test(calendar_createCalendar, "calendar_createCalendar");
    
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

bool utilities_checkParseStringToArray()
{
    int count = 0;
    
    std::string str1 = "[1,2,3]";
    int arr1[3] = {1,2,3};
    int size = 3;
    int* arr1Result = new int[size]();
    parseStringToArray(arr1Result, size, str1);
    if(checkEquivalence(arr1,arr1Result,size))
        count++;
    delete[] arr1Result;
    
    std::string str2 = "[23, 400, 2000,    21,1,3,11,  4]";
    int arr2[8] = {23,400,2000,21,1,3,11,4};
    size = 8;
    int* arr2Result = new int[size]();
    parseStringToArray(arr2Result, size, str2);
    if(checkEquivalence(arr2,arr2Result,size))
        count++;
    delete[] arr2Result;
    

    size = 0;
    int* arr3Result = new int[size]();
    delete[] arr3Result;
    /*
    try {
        std::array<int, 3> arr4Result;
        parseStringToArray(arr4Result, "[1, 20000, 24]"); 
    } catch (ArrayValueIsTooLarge&){
        count++;
    }

    try {
        std::array<int, 3> arr4Result;
        parseStringToArray(arr4Result, "1, 2000, 24]"); 
    } catch (InvalidFormatOfRepetitionArray&){
        count++;
    }

    try {
        std::array<int, 3> arr4Result;
        parseStringToArray(arr4Result, "[1, 2000,y24]"); 
    } catch (InvalidFormatOfRepetitionArray&){
        count++;
    }

    try {
        std::array<int, 3> arr4Result;
        parseStringToArray(arr4Result, "[1, 2000,24,33]"); 
    } catch (TooManyValuesInString&){
        count++;
    }

    try {
        std::array<int, 3> arr4Result;
        parseStringToArray(arr4Result, "[1, 2000]"); 
    } catch (TooLittleValuesInString&){
        count++;
    }

    try {
        std::array<int, 3> arr4Result;
        parseStringToArray(arr4Result, "[1,, 2000, 30]"); 
    } catch (InvalidFormatOfRepetitionArray&){
        count++;
    }

    try {
        std::array<int, 3> arr4Result;
        parseStringToArray(arr4Result, "[,1, 2000, 30]"); 
    } catch (InvalidFormatOfRepetitionArray&){
        count++;
    }

    try {
        std::array<int, 3> arr4Result;
        parseStringToArray(arr4Result, "[1,   , , 30]"); 
    } catch (InvalidFormatOfRepetitionArray&){
        count++;
    }

    try {
        std::array<int, 3> arr4Result;
        parseStringToArray(arr4Result, "[1, 2 , 30,]"); 
    } catch (InvalidFormatOfRepetitionArray&){
        count++;
    }
    */
    
    return count == 2;
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
    
   return true;
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

bool dateDeadline_operators()
{
    int year = 2022;
    DateDeadline date1(year,3,14, 1400);
    DateDeadline date2(year,3,14, 1400);
    DateDeadline date3(year,3,12, 1400);
    DateDeadline date4(year,3,14, 400);
    DateDeadline date5(year,3,15, 1400);
    DateDeadline date6(year,3,12, 1420);
    DateDeadline date7(year,3,16, 400);
    int count = 0;
    count += (date1 == date2) == true;
    count += (date1 <= date2) == true;
    count += (date1 == date3) == false;
    count += (date1 == date4) == false;
    count += (date3 != date6) == true;
    count += (date1 != date3) == true;
    count += (date1 >  date3) == true;
    count += (date1 >= date3) == true;
    count += (date1 >  date4) == true; 
    count += (date1 <  date4) == false; 
    count += (date1 >  date5) == false; 
    count += (date1 >  date6) == true; 
    count += (date1 >= date6) == true; 
    count += (date1 >  date7) == false; 
    return count == 14;
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

bool dateRange_operators()
{
    int year = 2022;
    DateRange date1(year,3,14, 1400, 1440);
    DateRange date2(year,3,14, 1400, 1440);
    DateRange date3(year,3,12, 1400, 1440);
    DateRange date4(year,3,14, 400, 1200);
    DateRange date5(year,3,15, 1400, 1440);
    DateRange date6(year,3,12, 1420, 1440);
    DateRange date7(year,3,16, 400, 1200);
    DateRange date8(year,3,14, 1400, 1420);
    int count = 0;
    count += (date1 == date2) == true;
    count += (date1 <= date2) == true;
    count += (date1 == date3) == false;
    count += (date1 == date4) == false;
    count += (date3 != date6) == true;
    count += (date1 != date3) == true;
    count += (date1 >  date3) == true;
    count += (date1 >= date3) == true;
    count += (date1 >  date4) == true; 
    count += (date1 <  date4) == false; 
    count += (date1 >  date5) == false; 
    count += (date1 >  date6) == true; 
    count += (date1 >= date6) == true; 
    count += (date1 >  date7) == false; 
    count += (date1 >  date8) == true;   
    count += (date1 ==  date8) == false;
    return count == 16;
}

bool dateAll_operators()
{
    int year = 2022;
    DateRange date1(year, 3, 14, 1200, 1400);
    DateDeadline date2(year, 3, 14, 1400);
    DateDeadline date3(year, 3, 14, 1200);
    Date date4(year, 3, 14);
    int count = 0;
    count += (date1 == date2) == false;
    count += (date1 == date3) == false;
    count += (date1 == date4) == false;
    count += (date1 < date2) == true;
    count += (date1 < date3) == false;
    count += (date1 < date4) == false;
    count += (date2 < date4) == false;
    count += (date2 > date4) == true;
    return count==8;
}

bool event_createEvent()
{
    int count = 0;
    std::shared_ptr<Banner> banner(new Banner("Picnic","Bring cake"));
    Event event1(banner, 2022, 7, 24, 600, 1200);
    Event event2(banner, 2022, 7, 24, 600, 1200);
    if(event1 == event2)
        count++;
    event1.updateDate(7,24,1200,1400);
    if(event1 > event2)
        count++;
    if (event2.getTitle().compare("Picnic") == 0)
        count++;
    event2.updateTitle("Berry Themed Picnic");
    if (event2.getTitle().compare("Berry Themed Picnic") == 0)
        count++;
    if (event1.getTitle().compare(event2.getTitle()) == 0)
        count++;
    return count==5;
}

bool task_createTask()
{
    int count = 0;
    std::shared_ptr<Banner> banner(new Banner("Picnic","Bring cake"));
    Task task1(banner, 2022, 7, 24, 600);
    Task task2(banner, 2022, 7, 24, 600);
    if(task1 == task2)
        count++;
    task1.updateDate(7,24,1200);
    if(task1 > task2)
        count++;
    if (task2.getTitle().compare("Picnic") == 0)
        count++;
    task2.updateTitle("Berry Themed Picnic");
    if (task2.getTitle().compare("Berry Themed Picnic") == 0)
        count++;
    if (task1.getTitle().compare(task2.getTitle()) == 0)
        count++;
    return count==5;
}

bool reminder_createReminder()
{
    int count = 0;
    std::shared_ptr<Banner> banner(new Banner("Picnic","Bring cake"));
    Reminder rem1(banner, 2022, 7, 24);
    Reminder rem2(banner, 2022, 7, 24);
    if(rem1 == rem2)
        count++;
    rem1.updateDate(7,25);
    if(rem1 > rem2)
        count++;
    if (rem1.getTitle().compare("Picnic") == 0)
        count++;
    rem1.updateTitle("Berry Themed Picnic");
    if (rem1.getTitle().compare("Berry Themed Picnic") == 0)
        count++;
    if (rem1.getTitle().compare(rem1.getTitle()) == 0)
        count++;
    return count==5;
    return true;
}

bool calendar_createCalendar()
{
    Calendar calendar;
    std::shared_ptr<Banner> banner1(new Banner("Picnic","Bring cake"));
    Event event1(banner1, 2022, 7, 24, 600, 1200);
    calendar.addEvent(banner1, 7, 24, 600, 1200);
    std::shared_ptr<Banner> banner2(new Banner("Finish Art Assignment","Sketching plants"));
    calendar.addTask(banner2, 7, 24, 1200);
    std::shared_ptr<Banner> banner3(new Banner("Theatre show in 2 days",""));
    calendar.addReminder(banner3, 7, 24);
    return true;
}