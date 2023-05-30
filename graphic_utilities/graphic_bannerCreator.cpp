#include "./graphic_bannerCreator.h"

graphics_banner::ACTION graphics_banner::characterToBannerType(const char& action)
{   
    switch (action) {
        case('e'):
            return graphics_banner::ACTION::EVENT;
        case('r'):
            return graphics_banner::ACTION::REMINDER;
        case('t'):
            return graphics_banner::ACTION::TASK;
        case('x'):
            return graphics_banner::ACTION::RETURN;
        default:
            return graphics_banner::ACTION::NOTHING;
    }
}

bool graphics_banner::mainPointCreationProcess(Calendar& calendar)
{
    system("clear");
    char type = 'x';
    std::string userInput = "";

    // PRINT ACTION BAR
    std::cout << graphics::calendarTitle() << std::endl;
    std::cout << graphics::promptWhichPointToAdd() << std::endl;
    
    // GET INPUT
    std::cin >> userInput;
    userInput = trim(userInput);

    type = userInput[0];

    // APPLY ACTION
    bool success = graphics_banner::chooseBannerCreation(calendar, type);
    system("clear");
    std::cout << graphics::calendarTitle() << std::endl;
    std::cout << graphics::bannerCompletion(success) << std::endl;
    std::cout << "TODO: Actually complete it" << std::endl;
    std::cin >> userInput; // wait for key press to exit

    //
    return false;
}

bool graphics_banner::chooseBannerCreation(Calendar& calendar, const char& action_char)
{
    graphics_banner::ACTION action = graphics_banner::characterToBannerType(action_char);
    if (action == graphics_banner::ACTION::NOTHING) return false;

    switch (action) {
        case(graphics_banner::ACTION::EVENT):
            return graphics_banner::mainBannerCreationProcess(calendar, Banner::TYPE::EVENT);
            break;
        case(graphics_banner::ACTION::REMINDER):
            return graphics_banner::mainBannerCreationProcess(calendar, Banner::TYPE::REMINDER);
            break;
        case(graphics_banner::ACTION::TASK):
            return graphics_banner::mainBannerCreationProcess(calendar, Banner::TYPE::TASK);
            break;
        default: // Return
            return false;
    }

    return true;
}

bool graphics_banner::mainBannerCreationProcess(Calendar& calendar, Banner::TYPE type)
{
    system("clear");
    int year = calendar.getYear();
    std::string b_type = Banner::typeToString(type);
    std::string b_title = "";
    std::string b_description = "";
    std::string b_location = "";
    std::string b_urgencyStr = "";
    //int b_urgency = -1;
    int p_month = 1;
    int p_day = 1;
    int p_timeStart = 0;
    int p_timeEnd = 0;
    int p_deadline = 0;
    
    // Title
    graphics_banner::idleReadString(&graphics::promptPointTitle, &graphics_checks::validText, b_title, b_type, false);
    // Description
    graphics_banner::idleReadString(&graphics::promptPointDescription, &graphics_checks::validText, b_description, b_type, true);
    // Location
    graphics_banner::idleReadString(&graphics::promptPointLocation, &graphics_checks::validText, b_location, b_type, true);
    // Urgency
    graphics_banner::idleReadString(&graphics::promptPointUrgency, &graphics_checks::isNumberInRangeUrgency, b_urgencyStr, b_type, true);
    if (b_urgencyStr.empty()) b_urgencyStr = "-1";
    //b_urgency = stoi(b_urgencyStr);
    // Get Date Inputs 
    graphics_banner::getDateInputs(year, type, p_month, p_day, p_timeStart, p_timeEnd, p_deadline);
    // Create Point
    // TODO

    // Finished Successfully
    return true;
}

bool graphics_banner::getDateInputs(const int year, Banner::TYPE type, int& month, int& day, int& timeStart, int& timeEnd, int& deadline)
{
    std::string typeString = Banner::typeToString(type);
    
    // Get month/day
    graphics_banner::getDate(year, month, day);

    // Get timeStart/timeEnd/deadline depending on type
    graphics_banner::getTime(type, timeStart, timeEnd, deadline);

    return true;
}

void graphics_banner::idleReadString(std::string (*printFunc)(const std::string), bool (*checkFunc)(const std::string, std::string&),
 std::string& str, const std::string type, const bool canBeEmpty)
{
    // TODO: turn from void into bool, when user enters 'x' then exits Point creation process.
    // Or maybe instead just do a throw and have mainPointCreationProcess() catch it

    std::string userInput = "";
    std::string err = "";
    bool goodInput = true;
    int count = 0;
    do {
        // PRINT ACTION BAR
        std::cout << graphics::calendarTitle() << std::endl;
        std::cout << graphics::pointCreatorString() << std::endl;
        
        if (!goodInput && err != "") {
            std::cout << "The input is invalid because "<< err << std::endl;
        }
        std::cout << printFunc(type) << std::endl;
        
        // GET INPUT
        std::getline(std::cin, userInput);
        userInput = trim(userInput);

        // APPLY ACTION
        goodInput = checkFunc(userInput, err);
        count++;
        system("clear");

    }
    while (!goodInput);

    if (canBeEmpty && userInput == "n") {
        str = "";
    } else {
        str = userInput;
    }
    
}

void graphics_banner::getDate(const int year, int& month, int& day)
{

    std::string userInput = "";
    std::string err = "";
    bool goodInput = true;
    int count = 0;
    do {
        // PRINT DATE PROMPT BAR
        std::cout << graphics::calendarTitle() << std::endl;
        std::cout << graphics::pointCreatorString() << std::endl;
        
        if (!goodInput && err != "") {
            std::cout << "The input is invalid because "<< err << std::endl;
        }
        std::cout << graphics::promptPointMonthDay() << std::endl;
        
        // GET INPUT
        std::getline(std::cin, userInput);
        userInput = trim(userInput);

        // GET DATE
        goodInput = graphics_checks::isValidMonthDayFormat(year, userInput, err, month, day);
        count++;
        system("clear");

    }
    while (!goodInput);
    
}

void graphics_banner::getTime(Banner::TYPE type, int& timeStart, int& timeEnd, int& deadline)
{
    std::string typeString = Banner::typeToString(type);
    std::string time_str = "00:00";
    std::string timeStart_str = "00:00";
    if (type == Banner::TYPE::EVENT) {

        graphics_banner::idleReadString(&graphics::promptTimeStart, &graphics_checks::isValidTime, timeStart_str, typeString, false);
        timeStart = graphics_checks::timeToMinutes(timeStart_str);
        timeEnd = 0;
        bool askedForTimeEnd = false;
        do {
            if (askedForTimeEnd) {
                std::cout << "Your time end needs to be equal or bigger than the time start."<< std::endl;
                std::cout << "Your time start value is: "<< timeStart_str << std::endl;
            }
            graphics_banner::idleReadString(&graphics::promptTimeEnd, &graphics_checks::isValidTime, time_str, typeString, false);
            timeEnd = graphics_checks::timeToMinutes(time_str);
            askedForTimeEnd = true;
        } while (timeStart>timeEnd);

    } else if (type == Banner::TYPE::TASK) {

        graphics_banner::idleReadString(&graphics::promptDeadline, &graphics_checks::isValidTime, time_str, typeString, false);
        deadline = graphics_checks::timeToMinutes(time_str);

    }
}





