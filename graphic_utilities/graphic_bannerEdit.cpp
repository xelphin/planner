#include "./graphic_bannerEdit.h"

void graphics_edit::mainBannerEditor(Calendar &calendar)
{
    pointsInfo::EDIT attr = graphics_edit::idleReadIndex(calendar);
    if (attr == pointsInfo::EDIT::OUT_OF_RANGE) {
        return;
    }
    system("clear");

    // TODO: depending on attr value, edit point accordingly

    // Wait for key press to exit
    std::cout << "Press a letter and then ENTER to exit\n";
    std::string tmp;
    std::cin >> tmp; // wait for key press to exit
}

pointsInfo::EDIT graphics_edit::idleReadIndex(Calendar &calendar)
{
    system("clear");
    std::string userInput = "";
    std::string err = "";
    int maxAvailable = 0;
    pointsInfo::TYPE pointType;
    std::string attributeStr = ( *(calendar.getSelectedPoint()) ).printInfo_editingFormat(maxAvailable, pointType);

    // PRINT ACTION BAR
    std::cout << graphics::calendarTitle() << std::endl;
    std::cout << graphics::pointEditorString() << std::endl;
    std::cout << graphics::promptIndexOfAttribute(maxAvailable) << std::endl;
    std::cout << attributeStr;
    
    // GET INPUT
    std::cin >> userInput;
    userInput = trim(userInput);

    // RETURN ATTRIBUTE REQUESTED
    bool isNum = graphics_checks::isNumber(userInput, err); // non-negative whole number
    if (isNum && userInput.length() > 0) {
        int index = std::stoi(userInput);
        if (index >=0 || index <= maxAvailable) {
            return ( *(calendar.getSelectedPoint()) ).getAttribute_editingFormat(index);
        }
    }

    return pointsInfo::EDIT::OUT_OF_RANGE;
}