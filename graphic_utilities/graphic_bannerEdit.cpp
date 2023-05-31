#include "./graphic_bannerEdit.h"


void graphics_edit::mainBannerEditor(Calendar &calendar)
{
    graphics_edit::queryForEdit(calendar);
}

bool graphics_edit::queryForEdit(Calendar &calendar)
{
    system("clear");
    std::cout << ( *(calendar.getSelectedPoint()) ).printInfo_editingFormat();


    // Wait for key press to exit
    std::cout << "Press any key to exit\n";
    std::string tmp;
    std::cin >> tmp; // wait for key press to exit

    return true;
}