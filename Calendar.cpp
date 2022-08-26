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


void Calendar::addEvent(std::shared_ptr<Banner> banner, const int month, const int day,
        const int timeStart, const int timeEnd)
{
    m_points.push_back(std::make_unique<Event>(std::move(banner), m_year, month, day,
     timeStart, timeEnd));
}

void Calendar::addTask(std::shared_ptr<Banner> banner, const int month, const int day,
    const int deadline)
{
    m_points.push_back(std::make_unique<Task>(std::move(banner), m_year, month, day,
     deadline));
}

void Calendar::addReminder(std::shared_ptr<Banner> banner, const int month, const int day)
{
    m_points.push_back(std::make_unique<Reminder>(std::move(banner), m_year, month, day));
}