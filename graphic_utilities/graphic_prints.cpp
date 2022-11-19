#include "./graphic_prints.h"

#define LENGTH_OF_BAR 28
#define REMOVE 'r'
#define EDIT 'e'

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

    text += "Move:   w      Edit: e    Add: a    Remove: r    Save and Exit: x      \n";
    text += "      a s d                                                            \n";

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

std::string graphics::invalidPointSelection()
{
    std::string text = "";

    text += "You have selected an invalid type. Please select one of the following:\n";
    text +=  graphics::pointOptions();
    text += "And press ENTER\n";

    return text;
}

// TODO: Add to makefile