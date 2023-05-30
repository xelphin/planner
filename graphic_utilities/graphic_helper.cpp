#include "./graphic_helper.h"

bool graphics_helper::getDateInputs(const int year, Banner::TYPE type, int& month, int& day, int& timeStart, int& timeEnd, int& deadline)
{
    std::string typeString = Banner::typeToString(type);
    
    // Get month/day
    graphics_helper::getDate(year, month, day);

    // Get timeStart/timeEnd/deadline depending on type
    graphics_helper::getTime(type, timeStart, timeEnd, deadline);

    return true;
}

void graphics_helper::idleReadString(std::string (*printFunc)(const std::string), bool (*checkFunc)(const std::string, std::string&),
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

void graphics_helper::getDate(const int year, int& month, int& day)
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

void graphics_helper::getTime(Banner::TYPE type, int& timeStart, int& timeEnd, int& deadline)
{
    std::string typeString = Banner::typeToString(type);
    std::string time_str = "00:00";
    std::string timeStart_str = "00:00";
    if (type == Banner::TYPE::EVENT) {

        graphics_helper::idleReadString(&graphics::promptTimeStart, &graphics_checks::isValidTime, timeStart_str, typeString, false);
        timeStart = graphics_checks::timeToMinutes(timeStart_str);
        timeEnd = 0;
        bool askedForTimeEnd = false;
        do {
            if (askedForTimeEnd) {
                std::cout << "Your time end needs to be equal or bigger than the time start."<< std::endl;
                std::cout << "Your time start value is: "<< timeStart_str << std::endl;
            }
            graphics_helper::idleReadString(&graphics::promptTimeEnd, &graphics_checks::isValidTime, time_str, typeString, false);
            timeEnd = graphics_checks::timeToMinutes(time_str);
            askedForTimeEnd = true;
        } while (timeStart>timeEnd);

    } else if (type == Banner::TYPE::TASK) {

        graphics_helper::idleReadString(&graphics::promptDeadline, &graphics_checks::isValidTime, time_str, typeString, false);
        deadline = graphics_checks::timeToMinutes(time_str);

    }
}
