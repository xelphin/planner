#include "./Calendar.h"

Calendar::Calendar()
{
    std::ifstream data;
    data.open(m_fileName);
    if(data) {
        std::cout<< "file exists" << std::endl;
    } else {
        // TODO: Ask user for year
        m_year = 2022;
        Calendar::createDatabase();
    } 
}

void Calendar::createDatabase() const
{
    std::ofstream data("database.txt");
    data << m_year << "\n" << std::endl;
    data.close();
}


void Calendar::addEvent(const std::string title, const int month, const int day,
    const int timeStart, const int timeEnd, const bool repeat, const std::string repeatArray, 
    const int repeatAmount, const std::string description)
{
    /*
    m_points.push_back(std::make_unique<Event>(title, m_year, month, day,
     timeStart, timeEnd, repeat, repeatAmount, description));
    int jump = Event::DATE_VARIABLE_AMOUNT;
    int arrSize = repeatAmount*jump; // [month, day, start, end]
    int* arrResult = new int[arrSize]();

    for(int i=0; i<repeatAmount; i++) {
        (*m_points.back()).addRepeat(arrResult[i*jump+0], arrResult[i*jump+1], arrResult[i*jump+2], arrResult[i*jump+3]);
    }

    delete[] arrResult;
    */
}


