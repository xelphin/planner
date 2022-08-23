#include "./Calendar.h"

Calendar::Calendar()
{
    std::ifstream data;
    data.open(m_fileName);
    if(data) {
        std::cout<< "file exists" << std::endl;
    } else {
        Calendar::createDatabase();
    } 
}

void Calendar::createDatabase() const
{
    std::time_t t = std::time(nullptr);
    std::tm *const pTInfo = std::localtime(&t);
    int year = 1900 + pTInfo->tm_year;

    std::ofstream data("database.txt");
    data << year << "\n" << std::endl;
    data.close();
}