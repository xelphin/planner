#include "./Calendar.h"

Calendar::Calendar()
{
    m_selectedPoint = *m_points.begin();
    std::ifstream data;
    data.open(m_fileName);
    std::string strYear;
    if(data) {
        try {
            getline(data,strYear);
            m_year = std::stoi(strYear);
            if (m_year<getMinYear() || m_year>getMaxYear())
                throw;
            // parseTextFileToCalendar(data);
        } catch (...) {
            throw InvalidDatabaseFormat_Year(getMinYear(), getMaxYear(), m_year);
        }
        // TODO: Read rest of Calendar and create it
    } else {
        m_year = askUserYear();
        Calendar::createDatabase();
    } 
    data.close();
}

void Calendar::createDatabase() const
{
    std::ofstream data("database.txt");
    data << m_year << "\n";
    data.close();
}

void Calendar::createNewBannerEvent(const std::string title, const std::string location, const std::string description, const int urgency,
    const int month, const int day, const int timeStart, const int timeEnd)
{
    std::shared_ptr<Banner> newBanner = std::make_shared<Banner>(Banner::TYPE::EVENT, title, description, location, urgency);
    this -> addEvent(newBanner, month, day, timeStart, timeEnd);
}

void Calendar::createNewBannerTask(const std::string title, const std::string location, const std::string description, const int urgency,
    const int month, const int day, const int deadline, const bool completed)
{
    std::shared_ptr<Banner> newBanner = std::make_shared<Banner>(Banner::TYPE::TASK, title, description, location, urgency);
    this -> addTask(newBanner, month, day, deadline, completed);
}

void Calendar::createNewBannerReminder(const std::string title, const std::string location, const std::string description, const int urgency,
    const int month, const int day)
{
    std::shared_ptr<Banner> newBanner = std::make_shared<Banner>(Banner::TYPE::REMINDER, title, description, location, urgency);
    this -> addReminder(newBanner, month, day);
}

void Calendar::addEvent(std::shared_ptr<Banner> banner, const int month, const int day,
        const int timeStart, const int timeEnd)
{
    std::shared_ptr<Event> newElem = std::make_shared<Event>(std::move(banner), m_year, month, day,
     timeStart, timeEnd);
    m_points.push_back(newElem);
    m_selectedPoint = m_points.back();
    m_points.sort(pointCompare);
    
}

void Calendar::addTask(std::shared_ptr<Banner> banner, const int month, const int day,
    const int deadline, const bool completed)
{
    std::shared_ptr<Task> newElem = std::make_shared<Task>(std::move(banner), m_year, month, day,
     deadline, completed);
    m_points.push_back(newElem);
    m_selectedPoint = m_points.back();
    m_points.sort(pointCompare);
}

void Calendar::addReminder(std::shared_ptr<Banner> banner, const int month, const int day)
{
    std::shared_ptr<Reminder> newElem = std::make_shared<Reminder>(std::move(banner), m_year, month, day);
    m_points.push_back(newElem);
    m_selectedPoint = m_points.back();
    m_points.sort(pointCompare);
}

std::shared_ptr<Point> Calendar::getSelectedPoint() const
{
    if (m_selectedPoint == nullptr) throw NoSelectedPoint();
    return m_selectedPoint; 
}

void Calendar::selectEarlierPoint()
{
    std::list<std::shared_ptr<Point>>::const_iterator it = m_points.begin();
    if (m_points.empty()) return;
    if (*it == m_selectedPoint) return;
    it++;
    for ( ; it != m_points.end(); it++) {
        if ((*it) == m_selectedPoint) {
            it--;
            m_selectedPoint = *it;
            return;
        }
    }
}

void Calendar::selectLaterPoint()
{
    std::list<std::shared_ptr<Point>>::const_iterator it;
    for (it = m_points.begin(); it != m_points.end(); it++) {
        if ((*it) == m_selectedPoint) {
            it++;
            if (it != m_points.end())
                m_selectedPoint = *(it);
            return;
        }
    }
}

void Calendar::removeSelectedPoint()
{
    if (m_points.empty()) throw AttemptToRemoveFromEmptyCalendar();
    if (!m_selectedPoint) throw NoSelectedPoint();
    std::list<std::shared_ptr<Point>>::iterator it = m_points.begin();
    while (it != m_points.end())
    {
        if (*it == m_selectedPoint) {
            if (m_points.size() == 1) {
                m_points.pop_front();   
                m_selectedPoint = nullptr;
                return;
            }
            if (it == m_points.begin()) {
                m_points.pop_front();
                m_selectedPoint = m_points.front();
                return;
            }
            m_selectedPoint = *(--it);
            it++;
            m_points.erase(it);
            return;
        }
        it++;
    }
}

void Calendar::print(std::ostream& os) const
{
    std::list<std::shared_ptr<Point>>::const_iterator it;
    int prevMonth = 0;
    int prevDay = 0;
    int currMonth = getMaxMonth();
    int currDay = amountDaysInMonth(m_year,currMonth);
    for (it = m_points.begin(); it != m_points.end(); ++it){
        // MONTHS
        currMonth = (*( (*(*it)).getDate() )).getMonth();
        if(currMonth != prevMonth) {
            if (prevMonth!=0)
                printEmptyDayRanges(os, prevDay, amountDaysInMonth(m_year,prevMonth)+1, prevMonth);
            printMonthTitles(os, prevMonth, currMonth);
            prevMonth = currMonth;
            prevDay = 0;
        }
        // DAYS
        currDay = (*( (*(*it)).getDate() )).getDay();
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

void Calendar::parseCalendarToDatabase() const
{
    std::vector<std::shared_ptr<Banner>>::const_iterator it_banner;
    std::list<std::unique_ptr<Point>>::const_iterator it_point;
    
    std::ofstream data("database.txt");
    data << m_year << "\n\n";
    /*
    for (it_banner = m_banners.begin(); it_banner != m_banners.end(); ++it_banner){
        // TODO: check why this doesn't run more than 0 times
        data << (*(*(it_banner))).getBannerParsed() << "\n";
        for(it_point = m_points.begin(); it_banner != m_banners.end(); ++it_banner) {
            //
        }

        data << "\n";
    }
    */
    data.close();
}

/*
void Calendar::parseTextFileToCalendar(std::ifstream& file)
{
    int lineIndex = 1;
    std::string line = "";
    
    while (getline(file, line))
    {
        getNextLineWithText(file, line, lineIndex);
        
        try {
            parseTextToPoint(file, line, lineIndex);
        } catch (const std::exception & e) {
            std::cout << e.what() << std::endl;
            break;
        }  
    }
    
}

void Calendar::getNextLineWithText(std::ifstream& file, std::string& line, int lineIndex)
{
    while(getline(file, line)) {
        lineIndex++;
        bool whiteSpacesOnly = line.find_first_not_of(' ') == std::string::npos;
        if (!whiteSpacesOnly)
            break;
    }
    line = trim(line);
}

void Calendar::parseTextToPoint(std::ifstream& file, std::string& line, int& lineIndex)
{
    // std::cout << "comparing line: " << line << std::endl;
    if (line.compare("Event") == 0) {
        std::cout << "Parsing Event..." << std::endl;
        parseTextToEvent(file, line, lineIndex);
    }
}

void Calendar::parseTextToEvent(std::ifstream& file, std::string& line, int& lineIndex)
{
    getNextLineWithText(file, line, lineIndex);
    int countElems = countElemsInString(line);
    if (countElems != Event::FULL_AMOUNT_BANNER_WITH_BASE_DATE)
        throw CorruptedFile_InvalidAmountOfElements(lineIndex, Event::FULL_AMOUNT_BANNER_WITH_BASE_DATE, countElems);
    //int i = 1;

}
*/