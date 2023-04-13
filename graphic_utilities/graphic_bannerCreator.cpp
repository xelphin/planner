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
    graphics_banner::idleReadString(calendar, &graphics::promptPointTitle, &graphics_banner::validText, b_title, b_type, false);
    // Description
    graphics_banner::idleReadString(calendar, &graphics::promptPointDescription, &graphics_banner::validText, b_description, b_type, true);
    // Location
    graphics_banner::idleReadString(calendar, &graphics::promptPointLocation, &graphics_banner::validText, b_location, b_type, true);
    // Urgency
    graphics_banner::idleReadString(calendar, &graphics::promptPointUrgency, &graphics_banner::isNumberInRangeUrgency, b_urgencyStr, b_type, true);
    if (b_urgencyStr.empty()) b_urgencyStr = "-1";
    //b_urgency = stoi(b_urgencyStr);
    // Get Date Inputs TODO
    graphics_banner::getDateInputs(calendar, type, p_month, p_day, p_timeStart, p_timeEnd, p_deadline);
    // Finished Successfully
    return true;
}

bool graphics_banner::getDateInputs(Calendar& calendar, Banner::TYPE type, int& month, int& day, int& timeStart, int& timeEnd, int& deadline)
{
    int year = calendar.getYear();
    std::string typeString = Banner::typeToString(type);
    
    // Get month/day
    graphics_banner::getDate(year, month, day);

    // Get timeStart/timeEnd/deadline depending on type
    //std::string timeStart_str = "00:00";
    //graphics_banner::idleReadString(calendar, &graphics::promptPointTime, &graphics_banner::isValidTime, timeStart_str, typeString, false);
    
    

    return true;
}

void graphics_banner::idleReadString(Calendar& calendar, std::string (*printFunc)(const std::string), bool (*checkFunc)(const std::string, std::string&),
 std::string& str, const std::string type, const bool canBeEmpty)
{

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





// CHECKS

bool graphics_banner::validText(const std::string str, std::string& err)
{
    if (!graphics_banner::isNotEmpty(str,err)) return false;
    if (graphics_banner::startsWithLetter(str,err) ){
        if (graphics_banner::hasOnlyLettersAndNumbers(str,err)) {
            return true;
        }
    }
    return false;
}

bool graphics_banner::isNotEmpty(const std::string str, std::string& err)
{
    if (str.empty()) {
        err = "";
        return false;
    }
    return true;
}

bool graphics_banner::startsWithLetter(const std::string str, std::string& err)
{
    if (isalpha(str[0]) == false){
        err = " it doesn't start with a letter.\n";
        return false;
    }
    return true;
}

bool graphics_banner::hasOnlyLettersAndNumbers(const std::string str, std::string& err)
{
    int N = str.length();
    for(int i=0; i<N; i++) {
        if (!isalpha(str[i]) && !isdigit(str[i]) && !isspace(str[i])) {
            err = " there's a non letter/digit/space inside of: "+ str +"\n";
            return false;
        }
    }
    return true;
}

bool graphics_banner::isNumberInRangeUrgency(const std::string str, std::string& err)
{
    if (str.length() > 1) {
        err = " you wrote an input larger than size of one, when the options were 1 to 5 and 'n'\n";
        return false;
    }
        
    if(str[0] == 'n' || str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5') {
        return true;
    }
    err = " you didn't select a number from 1 to 5 or 'n'\n";
    return false;
}

bool graphics_banner::isNumber(const std::string str, std::string& err)
{
    int N = str.length();
    for( int i = 0; i < N; i++ ) {
      if( !isdigit( str[i] )) {
        err = "is not a number.";
        return false;
      }
    }
    return true;
}

bool graphics_banner::isValidTime(const std::string str, std::string& err)
{
    // CHECK FORMAT
    int N = str.length();
    if (N != 5) {
        err = "the time should be represented by 5 characters. Example: 04:32. You haven't put 5 characters.";
        return false;  
    }
    // CHECK VALID HOUR
    int hour = stoi(str.substr(0, 2));
    int minutes = stoi(str.substr(3, 2));
    if (hour>23 || hour < 0) {
        err = "the hour is not between 00 and 23.";
        return false; 
    }
    if (minutes>59 || minutes < 0) {
        err = "the hour is not between 00 and 59.";
        return false; 
    }
    return true;
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
        goodInput = graphics_banner::isValidMonthDayFormat(year, userInput, err, month, day);
        count++;
        system("clear");

    }
    while (!goodInput);
    
}


bool graphics_banner::isValidMonthDayFormat(const int year,const std::string userInput, std::string& err, int& month, int& day)
{

    bool passedSlash = false;
    int slashIndex = 0;


    // CHECK CORRECT FORMAT
    int N = userInput.length();
    if (N<3) {
        err = "is not long enough. Has to have at least three characters. '<month>/<day>'.";
        return false;
    }
    for( int i = 0; i < N; i++ ) {
        if( userInput[i] == '/' && passedSlash == true) {
            err = "is not in correct format. You can only have one slash";
            return false;
        } else if (userInput[i] == '/') {
            passedSlash = true;
            slashIndex = i;
        } else if (!isdigit( userInput[i] )) {
            err = "has non-digit and non-slash character";
            return false;
        }
    }
    if(userInput[0] == '/') {
        err = "there is no month number before the '/'";
        return false;
    }
    if(userInput[N-1] == '/') {
        err = "there is no day number after the '/'";
        return false;
    }
    if (passedSlash == false) {
        err = "is wrong format. No slash present.";
        return false;
    }

    // CHECK CORRECT DATE
    if (!validDate(year, stoi(userInput.substr(0, slashIndex)), stoi(userInput.substr(slashIndex+1, N - slashIndex)))) {
        err = "the date is not logical. There is no such combination for the month/day.";
        return false;
    } 
    // Correct format and data
    month = stoi(userInput.substr(0, slashIndex));
    day = stoi(userInput.substr(slashIndex+1, N - slashIndex));
    return true;

}



