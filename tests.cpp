
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

bool run_all_tests() {
    std::string success_string = "ALL TESTS SUCCEEDED";
    bool success = true;
    run_test(utilities_amountDaysInMonth, "utilities_amountDaysInMonth", success_string, success);
    run_test(utilities_validDate, "utilities_validDate", success_string, success);
    run_test(utilities_checkValidTime, "utilities_checkValidTime", success_string, success);
    run_test(utilities_checkValidTimeRange, "utilities_checkValidTimeRange", success_string, success);
    run_test(utilities_countElemsInString, "utilities_countElemsInString", success_string, success);
    run_test(utilities_extract, "utilities_extract", success_string, success);
    run_test(date_createDate, "date_createDate", success_string, success);
    run_test(date_updateDate, "date_updateDate", success_string, success);
    run_test(dateDeadline_createDate, "dateDeadline_createDate", success_string, success);
    run_test(dateDeadline_updateDate, "dateDeadline_updateDate", success_string, success);
    run_test(dateDeadline_operators, "dateDeadline_operators", success_string, success);
    run_test(dateRange_createDate, "dateRange_createDate", success_string, success);
    run_test(dateRange_updateDate, "dateRange_updateDate", success_string, success);
    run_test(dateRange_operators, "dateRange_operators", success_string, success);
    run_test(dateAll_operators, "dateAll_operators", success_string, success);
    run_test(event_createEvent, "event_createEvent", success_string, success);
    run_test(reminder_createReminder, "reminder_createReminder", success_string, success);
    run_test(task_createTask, "task_createTask", success_string, success);
    run_test(calendar_createCalendar, "calendar_createCalendar", success_string, success);
    run_test(calendar_getSelectedPoint, "getSelectedPoint", success_string, success);
    run_test(calendar_selectPoint, "calendar_selectPoint", success_string, success);
    run_test(calendar_selectPoint_mixedTypes, "calendar_selectPoint_mixedTypes", success_string, success);
    run_test(calendar_selectEarlierPointFromAPreviousMonth, "calendar_selectEarlierPointFromAPreviousMonth", success_string, success);
    run_test(calendar_selectLaterPointFromAnUpcomingMonth, "calendar_selectLaterPointFromAnUpcomingMonth", success_string, success);
    run_test(calendar_removeSelectedPoint, "calendar_removeSelectedPoint", success_string, success);
    run_test(calendar_parseTextToCalendar_parsingEvent, "calendar_parseTextToCalendar_parsingEvent", success_string, success);
    run_test(calendar_parseTextToCalendar_parsingEvents, "calendar_parseTextToCalendar_parsingEvents", success_string, success);
    run_test(calendar_parseTextToCalendar, "calendar_parseTextToCalendar", success_string, success);
    run_test(calendar_parseCalendarToTextFile, "calendar_parseCalendarToTextFile", success_string, success);
    std::cout << success_string << std::endl;
    return success;
}

void run_test(std::function<bool()> test, std::string test_name, std::string& success_string, bool& success)
{
    if(!test()){
        printFail();
        std::cout << std::endl;
        success_string = "FAILED TEST: " + test_name;
        success = false;
        return;
    }
    printSuccess();
    std::cout << std::endl;
}

void createTextFile(const std::string &filename, const std::string &input)
{
    std::ofstream file(filename);
    if(file){
        file << input;
    }
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

bool utilities_countElemsInString()
{
    int count = 0;
    try {
        countElemsInString("[");
    } catch (const StringIsNotOfArrayFormat&) {
        count++;
    }
    try {
        countElemsInString("[23, 4, 5");
    } catch (const StringIsNotOfArrayFormat&) {
        count++;
    }
    try {
        countElemsInString("[23, 4, ,5]");
    } catch (const MissingElemInArrayString&) {
        count++;
    }
    try {
        countElemsInString("[233, 4, 65c4 ,5]");
    } catch (const InvalidCharacterInString&) {
        count++;
    }
    try {
        countElemsInString("[233, c, 654 ,5]");
    } catch (const InvalidCharacterInString&) {
        count++;
    }
    try {
        countElemsInString("[233, \"hello , 654 ,5]");
    } catch (const StringIsNotOfArrayFormat&) {
        count++;
    }
    try {
        countElemsInString("[233, \"hello \n, 654 ,5]");
    } catch (const StringIsNotOfArrayFormat&) {
        count++;
    }
    try {
        countElemsInString("[233, \"hello \n, - ,5]");
    } catch (const StringIsNotOfArrayFormat&) {
        count++;
    }
    count += countElemsInString("[233,\"cee m\", 654 ,5]") == 4;
    count += countElemsInString("[233,\"cee m\", -654 ,5]") == 4;
    count += countElemsInString("[\"cee m\"]") == 1;
    count += countElemsInString("[\"cee m\" ]") == 1;
    count += countElemsInString("[ \"cee m\"]") == 1;
    count += countElemsInString("[ \"cee m\" ]") == 1;
    count += countElemsInString("[ \"\" ]") == 1;
    count += countElemsInString("[ \"\", 3, 435, \" hello\"   ]") == 4;
    count += countElemsInString("[ 1]") == 1;
    count += countElemsInString("[\"Board Game Night\", \"\", \"Board games and wine night with Micheal and Lara\", 1, 3, 20, 600, 1200]") == 8;


    return count == 18;
}

bool utilities_extract()
{
    int count = 0;
    std::string str1 = "[\"Board Game Night\", \"\"   , \"Board games and wine night with Micheal and Lara\", 1, 3, 20  ,600, 1200 ]";
    count += countElemsInString(str1) == 8;

    int i = 1;
    // std::string title = extractString(str1,i);
    // std::cout << "title: " << title << std::endl;
    if ((extractString(str1,i)).compare("Board Game Night") == 0)
        count++;
    if ((extractString(str1,i)).compare("") == 0)
        count++;
    if ((extractString(str1,i)).compare("Board games and wine night with Micheal and Lara") == 0)
        count++;
    if ((extractInt(str1,i)) == 1)
        count++;
    if ((extractInt(str1,i)) == 3)
        count++;
    if ((extractInt(str1,i)) == 20)
        count++;
    if ((extractInt(str1,i)) == 600)
        count++;
    if ((extractInt(str1,i)) == 1200)
        count++;
    return count == 9;
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
    std::shared_ptr<Banner> banner(new Banner(Banner::TYPE::EVENT,"Picnic", "Bring Cake", "",1));
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
    event1.updateLocation("Edison Park");
    if (event1.getLocation().compare("Edison Park") == 0)
        count++;  
    return count==6;
}

bool task_createTask()
{
    
    int count = 0;
    std::shared_ptr<Banner> banner(new Banner(Banner::TYPE::TASK,"Picnic","Bring cake","",2));
    Task task1(banner, 2022, 7, 24, 600, false);
    Task task2(banner, 2022, 7, 24, 600, false);
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
    task1.updateUrgency(3);
    if (task2.getUrgency() == 3)
        count++; 
    return count==6;
}

bool reminder_createReminder()
{
    int count = 0;
    std::shared_ptr<Banner> banner(new Banner(Banner::TYPE::REMINDER,"Picnic","Bring cake","Leslie Park",1));
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
    rem1.updateLocation("Edison Park");
    if (rem2.getLocation().compare("Edison Park") == 0)
        count++;  
    return count==6;
    
}

bool calendar_createCalendar()
{ 
    Calendar calendar("test_files/database_basic.txt");
    
    std::shared_ptr<Banner> banner1(new Banner(Banner::TYPE::EVENT,"Board Game Night", "bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla", "", 2));
    calendar.addEvent(banner1, 3, 2, 600, 1200);
    calendar.addEvent(banner1, 3, 9, 600, 1200);
    std::shared_ptr<Banner> banner2(new Banner(Banner::TYPE::TASK,"Picnic","Bring cake and wine","",2));
    calendar.addTask(banner2, 7, 26, 1200, false);
    std::shared_ptr<Banner> banner3(new Banner(Banner::TYPE::REMINDER,"Anniversary","Bring cake","Leslie Park",2));
    calendar.addReminder(banner3, 7, 22);
    
    // std::cout << calendar;

    return true;
}

bool calendar_getSelectedPoint()
{
    int count = 0;
    Calendar calendar("test_files/database_basic.txt");

    calendar.createNewBannerEvent("Board Game Night","","Board games and wine night with Micheal and Lara",1, 3, 2, 600, 1200);
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night") == 0)
        count++;
    if (( (*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 2)
        count++;
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 2, 600, 1200);
    ( *(calendar.getSelectedPoint()) ).updateTitle("Board Game Night with Wine");
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 10, 600, 1200);
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 7, 600, 1200);
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night with Wine") == 0)
        count++;
    if (((*(calendar.getSelectedPoint())).getDescription()).compare("Board games and wine night with Micheal and Lara") == 0)
        count++;
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 7)
        count++; 
    

    calendar.createNewBannerTask("Finish Art Assignment","","Renaissance Inspired Portrait",1, 4, 2, 800, false);
    ( *(calendar.getSelectedPoint()) ).updateTitle("Finish Renaissance Art Assignment");
    calendar.addTask( ( *(calendar.getSelectedPoint()) ).getBanner(), 1, 7, 600, false);
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Finish Renaissance Art Assignment") == 0)
        count++;  

    return count == 6;

    // TODO:
        // Update README_DEVELOPER and implement parse into txt
        // Implement parse from txt to Calendar
        // Implement Graphics
        // (Notice when editing different Points not all editing options are available
        //   depending on what Point it is -> this creates a "difference" of Banners)
    
}

bool calendar_selectPoint()
{
    int count = 0;
    Calendar calendar("test_files/database_basic.txt");

    calendar.createNewBannerEvent("Board Game Night","","Board games and wine night with Micheal and Lara",1, 3, 1, 600, 1200); // 1/3
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night") == 0)
        count++;
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 2, 600, 1200); // 2/3
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 8, 600, 1200); // 8/3
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 4, 600, 1200); // 4/3
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 4)
        count++;
    calendar.selectEarlierPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 2)
        count++;
    calendar.selectEarlierPoint();
    // std::cout << "selected: " << ((*(calendar.getSelectedPoint())).getDay()) << std::endl;
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 1)
        count++;
    calendar.selectEarlierPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 1)
        count++;
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 6, 600, 1200); // 6/3
    calendar.selectLaterPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 8)
        count++;
    calendar.selectEarlierPoint();
    calendar.selectEarlierPoint();
    calendar.selectEarlierPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 2)
        count++;
    calendar.selectLaterPoint();
    calendar.selectLaterPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 6)
        count++;

    return count == 8;    
}

bool calendar_selectPoint_mixedTypes()
{
    int count = 0;
    Calendar calendar("test_files/database_basic.txt");

    calendar.createNewBannerEvent("Board Game Night","","Board games and wine night with Micheal and Lara",1, 3, 20, 600, 1200); // 20/3
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night") == 0)
        count++;
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 10, 720, 1200); // 10/3 : 12:00
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 10, 300, 1200); // 10/3 : 05:00
    calendar.createNewBannerTask("Finish Art Assignment","","",1, 3, 16, 600, false); // 16/3
    calendar.addTask( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 12, 300, false); // 12/3
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 14, 300, 1200); // 14/3
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 14)
        count++; 
    calendar.selectLaterPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 16)
        count++;
    calendar.selectLaterPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 20)
        count++;
    calendar.selectEarlierPoint();
    calendar.selectLaterPoint();
    calendar.selectLaterPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 20)
        count++;
    calendar.selectEarlierPoint();
    calendar.selectEarlierPoint();
    calendar.selectEarlierPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 12)
        count++;
    calendar.selectEarlierPoint();
    if (( (*(*(calendar.getSelectedPoint())).getDate()).getTime()) == 720)
        count++;

    return count == 7;    
}

bool calendar_selectEarlierPointFromAPreviousMonth()
{
    int count = 0;
    Calendar calendar("test_files/database_basic.txt");

    calendar.createNewBannerEvent("Board Game Night","","Board games and wine night with Micheal and Lara",1, 3, 20, 600, 1200); // 20/3
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night") == 0)
        count++;
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 2, 10, 720, 1200); // 10/2 : 12:00
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 5, 11, 300, 1200); // 11/5 : 05:00
    calendar.createNewBannerTask("Finish Art Assignment","","",1, 3, 16, 600, false); // 16/3
    calendar.addTask( ( *(calendar.getSelectedPoint()) ).getBanner(), 5, 12, 300, false); // 12/5
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 5, 14, 300, 1200); // 14/5
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 14)
        count++; 

    calendar.selectEarlierPointFromAPreviousMonth();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 20)
        count++; 
    calendar.selectEarlierPointFromAPreviousMonth();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 10)
        count++; 
    calendar.selectEarlierPointFromAPreviousMonth();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 10)
        count++; 

    return count == 5;    
}

bool calendar_selectLaterPointFromAnUpcomingMonth()
{
    int count = 0;
    Calendar calendar("test_files/database_basic.txt");

    calendar.createNewBannerEvent("Board Game Night","","Board games and wine night with Micheal and Lara",1, 3, 20, 600, 1200); // 20/3
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night") == 0)
        count++;
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 2, 15, 720, 1200); // 15/2 : 12:00
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 5, 11, 300, 1200); // 11/5 : 05:00
    calendar.createNewBannerTask("Finish Art Assignment","","",1, 3, 16, 600, false); // 16/3
    calendar.addTask( ( *(calendar.getSelectedPoint()) ).getBanner(), 5, 12, 300, false); // 12/5
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 2, 14, 300, 1200); // 14/2
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 14)
        count++; 

    calendar.selectLaterPointFromAnUpcomingMonth();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 16)
        count++; 
    calendar.selectLaterPointFromAnUpcomingMonth();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 11)
        count++; 
    calendar.selectLaterPointFromAnUpcomingMonth();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 12)
        count++; 
    calendar.selectLaterPointFromAnUpcomingMonth();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 12)
        count++; 

    return count == 6;    
}

bool calendar_removeSelectedPoint()
{
    int count = 0;
    Calendar calendar("test_files/database_basic.txt");

    calendar.createNewBannerEvent("Board Game Night","","Board games and wine night with Micheal and Lara",1, 3, 20, 600, 1200); // 20/3
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night") == 0)
        count++;
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 9, 720, 1200); // 9/3 : 12:00
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 10, 300, 1200); // 10/3 : 05:00
    calendar.createNewBannerTask("Finish Art Assignment","","",1, 3, 16, 600, false); // 16/3
    calendar.addTask( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 12, 300, false); // 12/3
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 14, 300, 1200); // 14/3
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 14)
        count++;
    
    calendar.removeSelectedPoint(); // remove 14/3
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 12)
        count++;
    calendar.selectLaterPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 16)
        count++;
    calendar.selectLaterPoint();
    calendar.removeSelectedPoint(); // remove 20/3
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 16)
        count++;
    calendar.selectEarlierPoint();
    calendar.selectEarlierPoint();
    calendar.selectEarlierPoint();
    calendar.removeSelectedPoint(); // remove 9/3 
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 10)
        count++;
    calendar.selectEarlierPoint();
    calendar.removeSelectedPoint(); // remove 10/3 
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 12)
        count++;
    calendar.selectLaterPoint();
    calendar.selectLaterPoint();
    calendar.removeSelectedPoint(); // remove 16/3 
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 12)
        count++;
    calendar.removeSelectedPoint(); // remove 12/3
    try {
        calendar.getSelectedPoint();
    } catch (const NoSelectedPoint&) {
        count++;
    }
    try {
        calendar.removeSelectedPoint();
    } catch (const AttemptToRemoveFromEmptyCalendar&) {
        count++;
    }
        
    return count == 10;    
}


bool calendar_parseTextToCalendar_parsingEvent() {
    Calendar calendar("test_files/database_parseTextToCalendar_parsingEvent.txt");
    int count = 0;
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night") == 0)
        count++;
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 12)
        count++;
    calendar.selectEarlierPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 9)
        count++;
    calendar.selectEarlierPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 2)
        count++;
    calendar.selectEarlierPoint();
    if (((*((*(calendar.getSelectedPoint())).getDate())).getDay()) == 2)
        count++;
    return count == 5;
}

bool calendar_parseTextToCalendar_parsingEvents() {
    Calendar calendar("test_files/database_parseTextToCalendar_parsingEvents.txt");
    int count = 0;
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Movie Night") == 0)
        count++;
    calendar.selectEarlierPoint();
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night") == 0)
        count++;
    calendar.selectEarlierPoint();
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Movie Night") == 0)
        count++;
    calendar.selectEarlierPoint();
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Alice's Birthday") == 0)
        count++;
    calendar.selectEarlierPoint();
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night") == 0)
        count++;
    return count == 5;
}

bool calendar_parseTextToCalendar() {
    Calendar calendar("test_files/database_parseTextToCalendar.txt");
    int count = 0;
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Movie Night") == 0)
        count++;
    calendar.selectEarlierPoint();
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night") == 0)
        count++;
    calendar.selectEarlierPoint();
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Will Rain") == 0)
        count++;
    calendar.selectEarlierPoint();
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Will Rain") == 0)
        count++;
    calendar.selectEarlierPoint();
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Movie Night") == 0)
        count++;
    calendar.selectEarlierPoint();
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Alice's Birthday - Make Cake") == 0)
        count++;
    calendar.selectEarlierPoint();
    if (((*(calendar.getSelectedPoint())).getTitle()).compare("Board Game Night") == 0)
        count++;
    return count == 7;
}

bool calendar_parseCalendarToTextFile()
{
    Calendar calendar("test_files/database_basic.txt");

    calendar.createNewBannerEvent("Board Game Night","","Board games and wine night with Micheal and Lara",-1, 3, 5, 600, 1200); // 5/3
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 2, 600, 1200); // 2/3
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 8, 600, 1200); // 8/3
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 4, 600, 1200); // 4/3
    calendar.addEvent( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 6, 600, 1200); // 6/3

    calendar.createNewBannerReminder("Remember to buy cake","","Carrot cake", -1,3,1); // 1/3
    calendar.addReminder( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 3); // 3/3

    calendar.createNewBannerTask("Finish art assignemnt","","",2, 3, 5, 800, 1); // 5/3
    calendar.addTask( ( *(calendar.getSelectedPoint()) ).getBanner(), 3, 12, 600, 1); // 12/3

    // PARSE
    std::string createPath = "test_files/database_parseCalendarToTextFile_created.txt";
    calendar.parseCalendarToTextFile(createPath);

    // CHECK
    Calendar calendar2(createPath);

    // COMPARE
    std::string comparePath = "test_files/database_parseCalendarToTextFile_compare.txt";
    return compareFiles(createPath, comparePath);    
}

// TODO: Make that a banner of type Task can only accept .addTask() and likewise for the other types