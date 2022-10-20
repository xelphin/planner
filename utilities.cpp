#include "./utilities.h"

#define MIN_YEAR 2000
#define MAX_YEAR 3000
#define MIN_MONTH 1
#define MAX_MONTH 12
#define ASCII_COMMA 44
#define ASCII_ZERO 48
#define ASCII_NINE 57
#define ASCII_QUOTE 34
#define ASCII_BACKSLASH 92
#define ASCII_MIN_SYMBOL 32
#define ASCII_MAX_SYMBOL 126
#define ASCII_SPACE 32

int amountDaysInMonth(const int year, const int month)
{
    if (year<MIN_YEAR || year>MAX_YEAR || month<1 || month>12)
        throw InvalidDate();
    bool isLeapYear = (year%4 == 0);
    return (month == 2) ?
		(28 + isLeapYear) : 31 - (month - 1) % 7 % 2;
}

int getMinYear() {return MIN_YEAR;}
int getMaxYear() {return MAX_YEAR;}
int getMinMonth() {return MIN_MONTH;}
int getMaxMonth() {return MAX_MONTH;}

bool validDate(const int year, const int month, const int day)
{
    if (year<MIN_YEAR || year>MAX_YEAR || month<1 || month>12 || day<1 || day>31)
        return false;
    try {
        if (day > amountDaysInMonth(year, month))
            return false;
    } catch (...) {
        return false;
    }
    return true;
}

bool checkValidTime(const int minutes)
{
    return !(minutes<0 || minutes>1440);
}

bool checkValidTimeRange(const int start, const int end)
{
    return !(start>end || !checkValidTime(start) || !checkValidTime(end));
}

void printArray(int arr[], const int amount)
{
    std::cout << "[";
    for(int i=0; i<amount; i++) {
       std::cout << arr[i];
       if(i!=amount-1)
            std::cout << ", "; 
    }
    std::cout << "]" << std::endl;
}

bool checkEquivalence(int arr1[], int arr2[], const int amount)
{
    for(int i=0; i<amount; i++) {
       if(arr1[i]!=arr2[i])
            return false;
    }
    return true;
}

int askUserYear()
{
    std::string strYear;
    int year = 2000;
    bool accepted = false;
    while(!accepted) {
        try {
            std::cout << "Please enter a year for the calendar between "<< getMinYear() << " and " << getMaxYear() << std::endl;
            std::getline(std::cin, strYear);
            year = std::stoi(strYear);
            if (year<getMinYear() || year>getMaxYear())
                throw InvalidLength(getMinYear(), getMaxYear(), year);
            accepted = true;
        } catch (...) {
            std::cout << "Wrong: ";
        }
    }
    return year;
}

std::string numToMonthName(const int num)
{
    switch(num) {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return "[UNKNOWN]";
    }
}

std::string minutesToTime(const int min)
{
    std::string time = "";
    time += std::to_string((int)(min/60));
    if (min/60 < 10)
        time += "0";
    time += ":";
    time += std::to_string((int)(min%60));
    if (min%60 < 10)
        time += "0";
    return time;
}


int countElemsInString(const std::string& str)
{
    std::cout << str << std::endl;
    // TODO: Spaces!!! - between commas is fine, not between numbers
    int length = str.length();
    // SPECIAL CASES
    if (length<2)
        throw StringIsNotOfArrayFormat();
    if(str[0]!='[' || str[length-1]!=']')
        throw StringIsNotOfArrayFormat();
    if (length==2) // delete this
        return 0;

    int count = 1;
    bool elemAppeared = false;
    for (int i=1; i<length-1; i++) {
        if (!(str[i] >= ASCII_ZERO && str[i] <= ASCII_NINE) && !(str[i] == ASCII_QUOTE) && !(str[i] == ASCII_SPACE) && !(str[i] == ASCII_COMMA))
            throw InvalidCharacterInString(i, str[i]);
        if (str[i] == ASCII_SPACE)
            continue;
        if (str[i] >= ASCII_ZERO && str[i] <= ASCII_NINE) {
            elemAppeared = true;
            checkBecomesValidNumber(str, length, i);
        }
        else if (str[i] == ASCII_QUOTE) {
            elemAppeared = true;
            checkBecomesValidString(str, length, i);
        }
        if (str[i] == ASCII_COMMA) { // after check valid, str[i] should be pointing at ',' (after spaces)
            if (!elemAppeared)
                throw MissingElemInArrayString();
            elemAppeared = false;
            count++;
        }
    }
    // std::cout << "string: " + str + " has" << count << " elements" << std::endl;
    return count;
}

void checkBecomesValidNumber(const std::string& str, const int length, int& i)
{
    for ( ; i<length-1; i++) {
        if (str[i]==ASCII_SPACE) {
            checkOnlySpacesTillComma(str, length, i);
            return;
        }
        if (!(str[i] >= ASCII_ZERO && str[i] <= ASCII_NINE) && !(str[i] == ASCII_COMMA))
            throw InvalidCharacterInString(i, str[i]);
        if (str[i] == ASCII_COMMA) {
            if (i==length-2) // case of: [... 123,]
                throw MissingElemInArrayString();
            return;
        }
    }
}


void checkBecomesValidString(const std::string& str, const int length, int& i)
{
    i++;
    for ( ; i<length-1; i++) {
        if (str[i] == ASCII_QUOTE && str[i-1] != ASCII_BACKSLASH) { 
            i++;
            checkOnlySpacesTillComma(str, length, i);
            return;
        }
    }
    throw StringIsNotOfArrayFormat();
}

void checkOnlySpacesTillComma(const std::string& str, const int length, int& i)
{
    while(str[i] != ASCII_COMMA && i < length-1) {
        if (str[i] != ASCII_SPACE)
            throw InvalidCharacterInString(i, str[i]);
        i++;
    }
    if (str[i] == ASCII_COMMA && i == length-2) // [...123 ,]
        throw MissingElemInArrayString();
    return;
}