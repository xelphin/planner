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

std::string graphics::promptPointTime(const std::string pointType)
{
    std::string text = "";

    text += "Please write the time for your ";
    text +=  pointType;
    text += ".\n It should be written in the format of '<hour>:<minutes>'. Examples: 04:30, 18:00, 23:04.\n";

    return text;  
}

// TODO: Add to makefile