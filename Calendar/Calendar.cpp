#include "./Calendar.h"

Calendar::Calendar()
{
    std::ifstream data;
    data.open(m_fileName);
    std::string strYear;
    if(data) {
        try {
            getline(data,strYear);
            m_year = std::stoi(strYear);
            if (m_year<getMinYear() || m_year>getMaxYear())
                throw;
        } catch (...) {
            throw InvalidDatabaseFormat_Year(getMinYear(), getMaxYear(), m_year);
        }
    } else {
        m_year = getYear();
        Calendar::createDatabase();
    } 
    data.close();
}

void Calendar::createDatabase() const
{
    std::ofstream data("database.txt");
    data << m_year << "\n" << std::endl;
    data.close();
}


void Calendar::addEvent(std::shared_ptr<BannerEvent> banner, const int month, const int day,
        const int timeStart, const int timeEnd)
{
    m_points.push_back(std::make_unique<Event>(std::move(banner), m_year, month, day,
     timeStart, timeEnd));
}

void Calendar::addTask(std::shared_ptr<BannerTask> banner, const int month, const int day,
    const int deadline)
{
    m_points.push_back(std::make_unique<Task>(std::move(banner), m_year, month, day,
     deadline));
}

void Calendar::addReminder(std::shared_ptr<BannerReminder> banner, const int month, const int day)
{
    m_points.push_back(std::make_unique<Reminder>(std::move(banner), m_year, month, day));
}