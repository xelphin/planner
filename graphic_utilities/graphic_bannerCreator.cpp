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

    // Finished Successfully
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