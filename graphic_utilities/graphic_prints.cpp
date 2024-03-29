#include "./graphic_prints.h"

#define LENGTH_OF_BAR 28

std::string graphics::decorativeBar()
{   
    std::string text = "";
    for(int i=0; i<LENGTH_OF_BAR; i++)
        text += "=";
    return text;
}

void graphics::action_pressEnterToContinue()
{
    std::string myString = "";
    do {
        std::cout << "Press ENTER to continue" << std::endl;
        std::getline(std::cin, myString);
    } while (myString.length() != 0);
    system("clear");
}

std::string graphics::spaces(const int amount)
{
    std::string text = "";
    for(int i=0; i<amount; i++)
        text += " ";
    return text; 
}

std::string graphics::calendarTitle()
{
    std::string text = "";
    int amountSpaces = LENGTH_OF_BAR - 4 - 8;

    text += graphics::decorativeBar();
    text += "==";
    text += graphics::spaces(amountSpaces);
    text +="CALENDAR";
    text += graphics::spaces(amountSpaces);
    text += "==";
    text +=  graphics::decorativeBar();

    return text;
}

std::string graphics::actionBar()
{
    std::string text = "";

    text += "Move:   w      Edit: e    Create: c    Remove: r    Save and Exit: x      \n";
    text += "      a s d                                                               \n";

    return text;
}

std::string graphics::instructions()
{
    std::string text = "";

    text += "Welcome to your terminal run Calendar!\n";
    text += "You can add Events, Tasks and Reminders.\n";
    text += "Press ENTER to Continue\n";

    return text;
}

std::string graphics::promptWhichPointToAdd()
{
    std::string text = "";

    text += "Which type will you like to add?\n";
    text +=  graphics::pointOptions();
    text += "Select the Letter and press ENTER\n";

    return text;
}

std::string graphics::pointOptions()
{
    return "e - Event | t - Task | r -Reminder | x - return\n\n";
}

std::string graphics::bannerCompletion(const bool success)
{
    std::string text = "";
    if (success) {
        text += "You have completed the process successfully\nPress any key to return to calendar.\n";
    } else {
        text += "The process was left uncompleted\nStopping Proccess\nPress any letter and then press ENTER to return.\n";
    }

    return text; 
}

std::string graphics::invalidPointSelection()
{
    std::string text = "";

    text += "You have selected an invalid type. Please select one of the following:\n";
    text +=  graphics::pointOptions();
    text += "Press ENTER\n";

    return text;
}

std::string graphics::pointCreatorString()
{
    std::string text = "";
    int amountSpaces = LENGTH_OF_BAR - 4 - 13;

    text += graphics::decorativeBar();
    text += "==";
    text += graphics::spaces(amountSpaces);
    text +="POINT CREATOR";
    text += graphics::spaces(amountSpaces);
    text += "==";
    text += graphics::decorativeBar();
    text += "\n Press 'x' and ENTER to return to Calendar (may not save changes)";

    return text;
}

std::string graphics::pointEditorString()
{
    std::string text = "";
    int amountSpaces = LENGTH_OF_BAR - 4 - 13;

    text += graphics::decorativeBar();
    text += "==";
    text += graphics::spaces(amountSpaces);
    text +="POINT EDITOR";
    text += graphics::spaces(amountSpaces);
    text += "==";
    text += graphics::decorativeBar();
    text += "\n Press 'x' and ENTER to return to Calendar (may not save changes)";

    return text;
}

std::string graphics::promptPointTitle(const std::string pointType)
{
    std::string text = "";

    text += "Please write the title for your ";
    text +=  pointType;
    text += "\n";

    return text;
}

std::string graphics::promptPointDescription(const std::string pointType)
{
    std::string text = "";

    text += "Please write the description for your ";
    text +=  pointType;
    text += "\n If it's not important simply write 'n'\n";

    return text;
}

std::string graphics::promptPointLocation(const std::string pointType)
{
    std::string text = "";

    text += "Please write the location for your ";
    text +=  pointType;
    text += "\n If it's not important simply write 'n'\n";

    return text;  
}

std::string graphics::promptPointUrgency(const std::string pointType)
{
    std::string text = "";

    text += "Please write the urgency of your ";
    text +=  pointType;
    text += ". It should be between 1-5; 5 being the most urgent.\n If it's not important simply write 'n'\n";

    return text;  
}

std::string graphics::promptPointMonthDay()
{
    std::string text = "";

    text += "Please write the month and day\n";
    text += "The should be between 1-12.\n[1] January, [2] February, ..., [12] December\n";
    text += "You should write it as '<month>/<day>'\n";
    text += "Example: March 12th is: '3/12'\n";

    return text;
}

std::string graphics::promptPointTime(const std::string pointType, const graphics::TIME_TYPE type)
{
    std::string typeName;
    switch (type) {
        case(graphics::TIME_TYPE::TIMESTART):
            typeName = "time start";
            break;
        case(graphics::TIME_TYPE::TIMEEND):
            typeName = "time end";
            break;
        case(graphics::TIME_TYPE::DEADLINE):
            typeName = "deadline";
            break;
    }
    std::string text = "";

    text += "Please write the "+ typeName +" for your ";
    text +=  pointType;
    text += ".\n It should be written in the format of '<hour>:<minutes>'. Examples: 04:30, 18:00, 23:04.\n";

    return text;  
}

std::string graphics::promptTimeStart(const std::string pointType)
{
    return promptPointTime(pointType,graphics::TIME_TYPE::TIMESTART);
}

std::string graphics::promptTimeEnd(const std::string pointType)
{
    return promptPointTime(pointType,graphics::TIME_TYPE::TIMEEND);
}

std::string graphics::promptDeadline(const std::string pointType)
{
    return promptPointTime(pointType,graphics::TIME_TYPE::DEADLINE);
}

std::string graphics::promptRepetitions()
{
    std::string text = "";

    text += "You can add a repetition.\n If you're not interested, simply write 'n'\n";
    text += "Otherwise, please write the month and day in the following format:\n";
    text += "The month should be between 1-12.\n[1] January, [2] February, ..., [12] December\n";
    text += "You should write it as '<month>/<day>'\n";
    text += "Example: March 12th is: '3/12'\n";
    return text;
}

std::string graphics::promptIndexOfAttribute(const int maxIndex)
{
    std::string text = "";

    text += "Please select an index for one of the attribute below, so between 0 and "+ std::to_string(maxIndex) +"\n";

    return text;
}

std::string graphics::strCurrentVersion(const std::string type, const std::string currValue)
{
    std::string text = "";

    text += "Current " + type + ": " + currValue;
    text += "\n";

    return text;
}

std::string graphics::strStoppedProcess(const std::string processName)
{
    std::string text = "";

    text += "You have written 'x'\n";
    text += "Process: \"" + processName + "\" stopped midway. Your changes may have not been saved.";
    text += "Press any letter and then ENTER to return to the Calendar\n";

    return text;
}