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

void Calendar::addBannerEvent(const std::string title, const std::string location, const std::string description)
{
    m_banners.push_back(std::make_unique<BannerEvent>(title, location, description));
}

void Calendar::addBannerTask(const std::string title, const int urgency, const std::string description)
{
    m_banners.push_back(std::make_unique<BannerTask>(title, urgency, description));
}

void Calendar::addBannerReminder(const std::string title, const std::string location, const std::string description)
{
    m_banners.push_back(std::make_unique<BannerReminder>(title, location, description));
}

void Calendar::addEvent(std::shared_ptr<BannerEvent> banner, const int month, const int day,
        const int timeStart, const int timeEnd)
{
    m_points.push_back(std::make_unique<Event>(std::move(banner), m_year, month, day,
     timeStart, timeEnd));
    m_points.sort(pointCompare);
}

void Calendar::addTask(std::shared_ptr<BannerTask> banner, const int month, const int day,
    const int deadline)
{
    m_points.push_back(std::make_unique<Task>(std::move(banner), m_year, month, day,
     deadline));
    m_points.sort(pointCompare);
}

void Calendar::addReminder(std::shared_ptr<BannerReminder> banner, const int month, const int day)
{
    m_points.push_back(std::make_unique<Reminder>(std::move(banner), m_year, month, day));
    m_points.sort(pointCompare);
}

void Calendar::print(std::ostream& os) const
{
    std::list<std::unique_ptr<Point>>::const_iterator it;
    for (it = m_points.begin(); it != m_points.end(); ++it){
        os << *(*it);
    }
    // TODO: Print with month dates (and so on)
}

std::ostream& operator<<(std::ostream& os, const Calendar& toPrint)
{
    toPrint.print(os);
    return os;
}