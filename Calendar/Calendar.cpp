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
        m_year = askUserYear();
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
    int prevMonth = 0;
    int prevDay = 0;
    int currMonth = getMaxMonth();
    int currDay = amountDaysInMonth(m_year,currMonth);
    for (it = m_points.begin(); it != m_points.end(); ++it){
        // MONTHS
        currMonth = (*(*it)).getMonth();
        if(currMonth != prevMonth) {
            if (prevMonth!=0)
                printEmptyDayRanges(os, prevDay, amountDaysInMonth(m_year,prevMonth)+1, prevMonth);
            printMonthTitles(os, prevMonth, currMonth);
            prevMonth = currMonth;
            prevDay = 0;
        }
        // DAYS
        currDay = (*(*it)).getDay();
        printEmptyDayRanges(os, prevDay, currDay, currMonth);
        prevDay = currDay;
        // POINTS
        os << *(*it);
    }
    // REST OF THE MONTHS
    printEmptyDayRanges(os, prevDay, amountDaysInMonth(m_year,currMonth)+1, currMonth);
    printMonthTitles(os, prevMonth, getMaxMonth());
    if(prevMonth!=12)
        printEmptyDayRanges(os, 0, amountDaysInMonth(m_year,12)+1, 12);
}

/*
void Calendar::print(std::ostream& os) const
{
    // TODO: Check if empty and then dont do anything
    int prevMonth = 0;
    int prevDay = 0;
    std::list<std::unique_ptr<Point>>::const_iterator it = m_points.begin();

    for (int m = getMinMonth(); m < getMaxMonth(); m++) {
        int currMonth = (*(*m_points.begin())).getMonth();
        int currDay = (*(*m_points.begin())).getDay();
        Calendar::printMonthTitles(os,m-1,m); // TODO: edit
        if (m!=currMonth) {
            printEmptyDayRanges(os, prevDay, amountDaysInMonth(m_year,m), m);
        }
    }
}
*/
std::ostream& operator<<(std::ostream& os, const Calendar& toPrint)
{
    toPrint.print(os);
    return os;
}

void Calendar::printMonthTitles(std::ostream& os, const int prev, const int curr) const
{
    for(int m = prev; m<curr; m++) {
        os << "=== "<< numToMonthName(m+1) << " ===" << std::endl << std::endl;
        if (m+1!=curr)
            printEmptyDayRanges(os, 0, amountDaysInMonth(m_year,m+1)+1, m+1);
    }
}

void Calendar::printEmptyDayRanges(std::ostream& os, const int prev, const int curr, const int month) const
{
    if(prev+1 < curr-1)
        os << " (" << numToMonthName(month).substr(0,3) << " " << prev+1 <<
         " - " << curr-1 << ")" << std::endl << std::endl;
}