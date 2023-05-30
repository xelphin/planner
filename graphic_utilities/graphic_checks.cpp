#include "./graphic_checks.h"

// CHECKS

bool graphics_checks::validText(const std::string str, std::string& err)
{
    if (!graphics_checks::isNotEmpty(str,err)) return false;
    if (graphics_checks::startsWithLetter(str,err) ){
        if (graphics_checks::hasOnlyLettersAndNumbers(str,err)) {
            return true;
        }
    }
    return false;
}

bool graphics_checks::isNotEmpty(const std::string str, std::string& err)
{
    if (str.empty()) {
        err = "";
        return false;
    }
    return true;
}

bool graphics_checks::startsWithLetter(const std::string str, std::string& err)
{
    if (isalpha(str[0]) == false){
        err = " it doesn't start with a letter.\n";
        return false;
    }
    return true;
}

bool graphics_checks::hasOnlyLettersAndNumbers(const std::string str, std::string& err)
{
    int N = str.length();
    for(int i=0; i<N; i++) {
        if (!isalpha(str[i]) && !isdigit(str[i]) && !isspace(str[i])) {
            err = " there's a non letter/digit/space inside of: "+ str +"\n";
            return false;
        }
    }
    return true;
}

bool graphics_checks::isNumberInRangeUrgency(const std::string str, std::string& err)
{
    if (str.length() > 1) {
        err = " you wrote an input larger than size of one, when the options were 1 to 5 and 'n'\n";
        return false;
    }
        
    if(str[0] == 'n' || str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5') {
        return true;
    }
    err = " you didn't select a number from 1 to 5 or 'n'\n";
    return false;
}

bool graphics_checks::isNumber(const std::string str, std::string& err)
{
    int N = str.length();
    for( int i = 0; i < N; i++ ) {
      if( !isdigit( str[i] )) {
        err = "is not a number.";
        return false;
      }
    }
    return true;
}

bool graphics_checks::isValidTime(const std::string str, std::string& err)
{
    // CHECK FORMAT
    int N = str.length();
    if (N != 5) {
        err = "the time should be represented by 5 characters. Example: 04:32. You haven't put 5 characters.";
        return false;  
    }
    if (!isNumber(str.substr(0, 2),err) || !isNumber(str.substr(3, 2),err)) return false;
    if (str.substr(2, 1) != ":") {
        err = "there should be a ':' in the 3rd place of your input and there wasn't.";
        return false;
    }
    // CHECK VALID HOUR
    int hour = stoi(str.substr(0, 2));
    int minutes = stoi(str.substr(3, 2));
    if (hour>23 || hour < 0) {
        err = "the hour is not between 00 and 23.";
        return false; 
    }
    if (minutes>59 || minutes < 0) {
        err = "the hour is not between 00 and 59.";
        return false; 
    }
    return true;
}


bool graphics_checks::isValidMonthDayFormat(const int year,const std::string userInput, std::string& err, int& month, int& day)
{

    bool passedSlash = false;
    int slashIndex = 0;


    // CHECK CORRECT FORMAT
    int N = userInput.length();
    if (N<3) {
        err = "is not long enough. Has to have at least three characters. '<month>/<day>'.";
        return false;
    }
    for( int i = 0; i < N; i++ ) {
        if( userInput[i] == '/' && passedSlash == true) {
            err = "is not in correct format. You can only have one slash";
            return false;
        } else if (userInput[i] == '/') {
            passedSlash = true;
            slashIndex = i;
        } else if (!isdigit( userInput[i] )) {
            err = "has non-digit and non-slash character";
            return false;
        }
    }
    if(userInput[0] == '/') {
        err = "there is no month number before the '/'";
        return false;
    }
    if(userInput[N-1] == '/') {
        err = "there is no day number after the '/'";
        return false;
    }
    if (passedSlash == false) {
        err = "is wrong format. No slash present.";
        return false;
    }

    // CHECK CORRECT DATE
    if (!validDate(year, stoi(userInput.substr(0, slashIndex)), stoi(userInput.substr(slashIndex+1, N - slashIndex)))) {
        err = "the date is not logical. There is no such combination for the month/day.";
        return false;
    } 
    // Correct format and data
    month = stoi(userInput.substr(0, slashIndex));
    day = stoi(userInput.substr(slashIndex+1, N - slashIndex));
    return true;

}

int graphics_checks::timeToMinutes(const std::string time)
{
    std::string tmp;
    if (!graphics_checks::isValidTime(time, tmp)) {
        return 0;
    }
    int hour = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return (hour*60) + minutes;
}