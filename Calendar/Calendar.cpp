#include "./Calendar.h"

Calendar::Calendar(std::string databaseName) : m_fileName(databaseName)
{
    m_selectedPoint = *m_points.begin();
    std::ifstream data;
    data.open(m_fileName);
    std::string strYear;
    if (data)
    {
        try
        {
            getline(data, strYear);
            m_year = std::stoi(strYear);
            if (m_year < getMinYear() || m_year > getMaxYear())
                throw;
            parseTextFileToCalendar(data);
        }
        catch (...)
        {
            throw InvalidDatabaseFormat_Year(getMinYear(), getMaxYear(), m_year);
        }
        // TODO: Read rest of Calendar and create it
    }
    else
    {
        m_year = askUserYear();
        Calendar::createDatabase();
    }
    data.close();
}

int Calendar::getYear() const
{
    return this->m_year;
}

void Calendar::createDatabase() const
{
    std::ofstream data(m_fileName);
    data << m_year << "\n";
    data.close();
}

void Calendar::createNewBannerEvent(const std::string title, const std::string location, const std::string description, const int urgency,
                                    const int month, const int day, const int timeStart, const int timeEnd)
{
    std::shared_ptr<Banner> newBanner = std::make_shared<Banner>(Banner::TYPE::EVENT, title, description, location, urgency);
    this->addEvent(newBanner, month, day, timeStart, timeEnd);
}

void Calendar::createNewBannerTask(const std::string title, const std::string location, const std::string description, const int urgency,
                                   const int month, const int day, const int deadline, const bool completed)
{
    std::shared_ptr<Banner> newBanner = std::make_shared<Banner>(Banner::TYPE::TASK, title, description, location, urgency);
    this->addTask(newBanner, month, day, deadline, completed);
}

void Calendar::createNewBannerReminder(const std::string title, const std::string location, const std::string description, const int urgency,
                                       const int month, const int day)
{
    std::shared_ptr<Banner> newBanner = std::make_shared<Banner>(Banner::TYPE::REMINDER, title, description, location, urgency);
    this->addReminder(newBanner, month, day);
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
    if (m_selectedPoint == nullptr)
        throw NoSelectedPoint();
    return m_selectedPoint;
}

void Calendar::selectEarlierPoint()
{
    std::list<std::shared_ptr<Point>>::const_iterator it = m_points.begin();
    if (m_points.empty())
        return;
    if (*it == m_selectedPoint)
        return;
    it++;
    for (; it != m_points.end(); it++)
    { // TODO: Not economical, see if can be improved
        if ((*it) == m_selectedPoint)
        {
            it--;
            m_selectedPoint = *it;
            return;
        }
    }
}

void Calendar::selectEarlierPointFromAPreviousMonth()
{
    if (m_points.empty())
        return;
    int initialPointMonth = ((*((*(this->getSelectedPoint())).getDate())).getMonth());

    while (*(m_points.begin()) != m_selectedPoint && initialPointMonth == ((*((*(this->getSelectedPoint())).getDate())).getMonth()))
    {
        this->selectEarlierPoint();
    }
}

void Calendar::selectLaterPoint()
{
    std::list<std::shared_ptr<Point>>::const_iterator it;
    for (it = m_points.begin(); it != m_points.end(); it++)
    {
        if ((*it) == m_selectedPoint)
        {
            it++;
            if (it != m_points.end())
                m_selectedPoint = *(it);
            return;
        }
    }
}

void Calendar::selectLaterPointFromAnUpcomingMonth()
{
    if (m_points.empty())
        return;
    int initialPointMonth = ((*((*(this->getSelectedPoint())).getDate())).getMonth());

    while ((m_points.back()) != m_selectedPoint && initialPointMonth == ((*((*(this->getSelectedPoint())).getDate())).getMonth()))
    {
        this->selectLaterPoint();
    }
}

void Calendar::selectFirstPoint()
{
    m_selectedPoint = *(m_points.begin());
}

void Calendar::selectFirstPointFromDate(const int month, const int day)
{
    std::list<std::shared_ptr<Point>>::const_iterator it = m_points.begin();
    for (; it != m_points.end(); it++)
    {
        int currMonth = (*((*(*it)).getDate())).getMonth();
        int currDay = (*((*(*it)).getDate())).getDay();
        m_selectedPoint = *(it);
        if (currMonth < month || (currMonth == month && currDay < day))
            continue;
        break;
    }
    // std::cout << "Selected point: " << (*( (*(*it)).getDate() )).getDay() << "/"
    //     << (*( (*(*it)).getDate() )).getMonth() << std::endl; // BUG: because reached m_points.end()
}

void Calendar::removeSelectedPoint()
{
    if (m_points.empty())
        throw AttemptToRemoveFromEmptyCalendar();
    if (!m_selectedPoint)
        throw NoSelectedPoint();
    std::list<std::shared_ptr<Point>>::iterator it = m_points.begin();
    while (it != m_points.end())
    {
        if (*it == m_selectedPoint)
        {
            if (m_points.size() == 1)
            {
                m_points.pop_front();
                m_selectedPoint = nullptr;
                return;
            }
            if (it == m_points.begin())
            {
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

void Calendar::print(std::ostream &os) const
{
    std::list<std::shared_ptr<Point>>::const_iterator it = m_points.begin();
    for (int m = 0; m < 12; m++)
    {
        os << printMonth_withIt(m, it);
    }
}

std::string Calendar::printMonth(const int month) const
{
    std::list<std::shared_ptr<Point>>::const_iterator it = m_points.begin();
    for (; it != m_points.end() && (*((*(*it)).getDate())).getMonth() < month; it++)
    {
    }
    return Calendar::printMonth_withIt(month, it);
}

std::string Calendar::printMonthSimplified() const
{
    std::list<std::shared_ptr<Point>>::const_iterator it = m_points.begin();
    // PRINT MONTH
    int monthOfPrevPoint = 0;
    for (; it != m_points.end() && (*(*it)) != (*m_selectedPoint); it++)
    {
        monthOfPrevPoint = (*((*(*it)).getDate())).getMonth();
    }
    if (*it == nullptr)
    {
        return "No ocassions have been recorded yet.\n Press 'c' and ENTER to create a new occassion.\n";
    }
    int monthOfCurrPoint = (*((*(*it)).getDate())).getMonth();
    int dayPreviousInSameMonth = (monthOfPrevPoint == monthOfCurrPoint) * ((*((*(*it)).getDate())).getDay());

    return Calendar::printMonth_withIt((*((*(*it)).getDate())).getMonth(), it, true, dayPreviousInSameMonth);
}

std::string Calendar::printMonth_withIt(const int month, std::list<std::shared_ptr<Point>>::const_iterator &it,
                                        const bool simplified, const int dayPreviousInSameMonth) const
{
    // month == 0 <--> January
    int pointCount = 0;
    int prevDay = dayPreviousInSameMonth;
    int currDay = 0;
    std::string text = "";
    text += "=== " + numToMonthName(month) + " ===\n";
    (simplified && dayPreviousInSameMonth != 0) ? text += "[...]\n" : text += "\n";
    bool withArrow = false;
    const int simplified_maxPoints = 5; // TODO: make dependent on cmd size instead

    for (; it != m_points.end(); it++)
    {
        int currMonth = (*((*(*it)).getDate())).getMonth();
        if (currMonth != month)
        {
            // No points in left in month
            break;
        }
        // Point inside of month
        simplified ? pointCount++ : pointCount += 0;
        if (simplified && pointCount > simplified_maxPoints)
        {
            text += "[...]\n";
            break; // TODO: change from 10 to something flexible depending on screen size of cmd
        }
        currDay = (*((*(*it)).getDate())).getDay();
        text += printEmptyDayRanges(prevDay, currDay, currMonth);
        prevDay = currDay;
        ((*it) == m_selectedPoint) ? withArrow = true : withArrow = false;
        text += (*(*it)).printToString(withArrow);
    }
    pointCount > simplified_maxPoints ? text += "" : text += printEmptyDayRanges(currDay, amountDaysInMonth(m_year, month) + 1, month);
    return text;
}

std::ostream &operator<<(std::ostream &os, const Calendar &toPrint)
{
    toPrint.print(os);
    return os;
}

std::string Calendar::printMonthTitles(const int prev, const int curr) const
{
    std::string text = "";
    for (int m = prev; m < curr; m++)
    {
        text += "=== " + numToMonthName(m) + " ===\n\n";
        if (m + 1 != curr)
            text += printEmptyDayRanges(0, amountDaysInMonth(m_year, m) + 1, m + 1);
    }
    return text;
}

std::string Calendar::printEmptyDayRanges(const int prev, const int curr, const int month) const
{
    std::string text = "";
    if (prev + 1 < curr - 1)
        text += " (" + numToMonthName(month).substr(0, 3) + " " + std::to_string(prev + 1) +
                " - " + std::to_string(curr - 1) + ")\n\n";
    return text;
}

void Calendar::parseCalendarToTextFile(const std::string &databaseName)
{
    std::ofstream database;
    database.open(databaseName, std::ofstream::out);
    if (!database)
    {
        std::cout << "Issue in creating databse..." << std::endl;
    }

    // YEAR
    database << std::to_string(m_year) << "\n\n";

    // BANNERS
    while (!m_points.empty())
        Calendar::parseBannerToTextFile(database);

    database.close();
}

void Calendar::parseBannerToTextFile(std::ofstream &database)
{
    // BANNER
    selectFirstPoint();
    std::shared_ptr<Point> anchorPoint = (this->getSelectedPoint());
    std::shared_ptr<Banner> banner = (*anchorPoint).getBanner();
    database << (*banner).getBannerTypeString() << "\n";
    database << (*anchorPoint).parsePointToTextFull() << "\n";
    this->removeSelectedPoint();
    // POINTS
    bool reachedLast = false;
    while (!m_points.empty() && !reachedLast)
    {
        if (this->getSelectedPoint() == (m_points.back()))
            reachedLast = true;
        if (banner == (*(this->getSelectedPoint())).getBanner())
        {
            database << (*(this->getSelectedPoint())).parsePointToText() << "\n";
            this->removeSelectedPoint();
        }
        else
        {
            this->selectLaterPoint();
        }
    }
    database << "-";
    if (!m_points.empty())
        database << "\n\n";
}

void Calendar::parseTextFileToCalendar(std::ifstream &file)
{
    int lineIndex = 1;
    std::string line = "";

    while (getline(file, line))
    {
        if (line.find_first_not_of(' ') == std::string::npos)
            getNextLineWithText(file, line, lineIndex);
        trim(line);
        try
        {
            parseTextToPoint(file, line, lineIndex);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
            break;
        }
    }
}

void Calendar::getNextLineWithText(std::ifstream &file, std::string &line, int &lineIndex)
{
    while (getline(file, line))
    {
        lineIndex++;
        bool whiteSpacesOnly = line.find_first_not_of(' ') == std::string::npos;
        if (!whiteSpacesOnly)
            break;
    }
    line = trim(line);
}

void Calendar::parseTextToPoint(std::ifstream &file, std::string &line, int &lineIndex)
{
    if ((trim(line)).find_first_not_of('\n') == std::string::npos)
        getNextLineWithText(file, line, lineIndex);

    if (line.compare(Banner::typeToString(Banner::TYPE::EVENT)) == 0)
    {
        std::cout << "Parsing Event..." << std::endl;
        parseTextToEvent(file, line, lineIndex);
        getNextLineWithText(file, line, lineIndex);
        parseTextToEventRepetitions(file, line, lineIndex);
    }
    else if (line.compare(Banner::typeToString(Banner::TYPE::TASK)) == 0)
    {
        std::cout << "Parsing Task..." << std::endl;
        parseTextToTask(file, line, lineIndex);
        getNextLineWithText(file, line, lineIndex);
        parseTextToTaskRepetitions(file, line, lineIndex);
    }
    else if (line.compare(Banner::typeToString(Banner::TYPE::REMINDER)) == 0)
    {
        std::cout << "Parsing Reminder..." << std::endl;
        parseTextToReminder(file, line, lineIndex);
        getNextLineWithText(file, line, lineIndex);
        parseTextToReminderRepetitions(file, line, lineIndex);
    }
    else
    {
        throw CorruptedFile_InvalidPointType(lineIndex, line);
    }

    if ((trim(line)).compare("-") != 0)
        throw CorruptedFile_InvalidFormat_NoDash();
}

void Calendar::parseTextToEvent(std::ifstream &file, std::string &line, int &lineIndex)
{
    getNextLineWithText(file, line, lineIndex);
    int countElems = countElemsInString(line);
    if (countElems != Event::FULL_AMOUNT_BANNER_WITH_BASE_DATE)
        throw CorruptedFile_InvalidAmountOfElements(lineIndex, Event::FULL_AMOUNT_BANNER_WITH_BASE_DATE, countElems);

    int i = 1;

    std::string title, location, description;
    int urgency, month, day, timeStart, timeEnd;
    extractPointData(line, i, title, location, description, urgency, month, day);
    timeStart = extractInt(line, i);
    timeEnd = extractInt(line, i);

    this->createNewBannerEvent(title, location, description, urgency, month, day, timeStart, timeEnd);
}

void Calendar::parseTextToTask(std::ifstream &file, std::string &line, int &lineIndex)
{
    getNextLineWithText(file, line, lineIndex);
    int countElems = countElemsInString(line);
    if (countElems != Task::FULL_AMOUNT_BANNER_WITH_BASE_DATE)
        throw CorruptedFile_InvalidAmountOfElements(lineIndex, Task::FULL_AMOUNT_BANNER_WITH_BASE_DATE, countElems);

    int i = 1;

    std::string title, location, description;
    int urgency, month, day, deadline, completed;
    extractPointData(line, i, title, location, description, urgency, month, day);
    deadline = extractInt(line, i);
    completed = extractInt(line, i);
    if (completed != 0 && completed != 1)
        throw CorruptedFile_InvalidData_CompletedInTask();
    this->createNewBannerTask(title, location, description, urgency, month, day, deadline, completed);
}

void Calendar::parseTextToReminder(std::ifstream &file, std::string &line, int &lineIndex)
{
    getNextLineWithText(file, line, lineIndex);
    int countElems = countElemsInString(line);
    if (countElems != Reminder::FULL_AMOUNT_BANNER_WITH_BASE_DATE)
        throw CorruptedFile_InvalidAmountOfElements(lineIndex, Reminder::FULL_AMOUNT_BANNER_WITH_BASE_DATE, countElems);

    int i = 1;

    std::string title, location, description;
    int urgency, month, day;
    extractPointData(line, i, title, location, description, urgency, month, day);
    this->createNewBannerReminder(title, location, description, urgency, month, day);
}

void Calendar::parseTextToEventRepetitions(std::ifstream &file, std::string &line, int &lineIndex)
{
    while (line[0] == '[')
    {
        int countElems = countElemsInString(line);
        if (countElems != Event::DATE_VARIABLE_AMOUNT)
            throw CorruptedFile_InvalidAmountOfElements(lineIndex, Event::DATE_VARIABLE_AMOUNT, countElems);
        int i = 1;
        int month = extractInt(line, i);
        int day = extractInt(line, i);
        int timeStart = extractInt(line, i);
        int timeEnd = extractInt(line, i);
        this->addEvent((*(this->getSelectedPoint())).getBanner(), month, day, timeStart, timeEnd);
        getNextLineWithText(file, line, lineIndex);
    }
}

void Calendar::parseTextToTaskRepetitions(std::ifstream &file, std::string &line, int &lineIndex)
{
    while (line[0] == '[')
    {
        int countElems = countElemsInString(line);
        if (countElems != Task::DATE_VARIABLE_AMOUNT)
            throw CorruptedFile_InvalidAmountOfElements(lineIndex, Task::DATE_VARIABLE_AMOUNT, countElems);
        int i = 1;
        int month = extractInt(line, i);
        int day = extractInt(line, i);
        int deadline = extractInt(line, i);
        int completed = extractInt(line, i);
        if (completed != 0 && completed != 1)
            throw CorruptedFile_InvalidData_CompletedInTask();
        this->addTask((*(this->getSelectedPoint())).getBanner(), month, day, deadline, completed);
        getNextLineWithText(file, line, lineIndex);
    }
}

void Calendar::parseTextToReminderRepetitions(std::ifstream &file, std::string &line, int &lineIndex)
{
    while (line[0] == '[')
    {
        int countElems = countElemsInString(line);
        if (countElems != Reminder::DATE_VARIABLE_AMOUNT)
            throw CorruptedFile_InvalidAmountOfElements(lineIndex, Reminder::DATE_VARIABLE_AMOUNT, countElems);
        int i = 1;
        int month = extractInt(line, i);
        int day = extractInt(line, i);
        this->addReminder((*(this->getSelectedPoint())).getBanner(), month, day);
        getNextLineWithText(file, line, lineIndex);
    }
}

void Calendar::extractPointData(std::string &line, int &i,
                                std::string &title, std::string &location, std::string &description, int &urgency,
                                int &month, int &day)
{
    title = extractString(line, i);
    location = extractString(line, i);
    description = extractString(line, i);
    urgency = extractInt(line, i);
    month = extractInt(line, i);
    day = extractInt(line, i);
}

// TODO: Generify parsing functions as much as possible