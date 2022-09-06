#include "./utilities.h"

#define MIN_YEAR 2000
#define MAX_YEAR 3000
#define MIN_MONTH 1
#define MAX_MONTH 12

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

void parseStringToArray(int arr[], const int amount, const std::string str)
{
    int size = str.size();
    bool needNumber = true;
    if (size<2 || str[0]!='[' || str[size-1]!=']')
        throw InvalidFormatOfRepetitionArray();
    int arrIndex = 0;
    for (std::string::size_type i = 1; i < str.size() - 1; i++) {
        if ( (str[i]!=' ' && !(str[i]>'0' && str[i]<'9')) || (str[i] == str[i+1] && str[i]==',') )
            throw InvalidFormatOfRepetitionArray();
        if (arrIndex>=int(amount))
            throw TooManyValuesInString();
        if (str[i] == ' ') {
            needNumber = true;
            continue;
        }
        if(str[i] == ',') {
            if(needNumber)
                throw InvalidFormatOfRepetitionArray();
            arrIndex++;
            continue;
        }
        needNumber = false;
        int strIndexAfterLast=i+1;
        while(str[strIndexAfterLast]>='0' && str[strIndexAfterLast]<='9') 
            strIndexAfterLast++;
        
        int numLength = strIndexAfterLast-i;
        if(numLength > 4)
            throw ArrayValueIsTooLarge();
        
        if(arrIndex>int(amount))
            throw InvalidFormatOfRepetitionArray();

        arr[arrIndex] = std::stoi(str.substr(i, numLength));

        arrIndex++;
        i = strIndexAfterLast;
    }

    if(arrIndex-1<int(amount)-1)
        throw TooLittleValuesInString();
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