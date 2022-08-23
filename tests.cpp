
#include "./tests.h"

/* Avoids Console Printing If Not Debugging */

#ifdef NDEBUG // I DONT want to debug
void printFail ();
void printSuccess ();
#define printFail() ((void)0)
#define printSuccess() ((void)0)
#else // I DO want to debug
#define printFail() (std::cout<< test_name <<" FAILED."<<std::endl)
#define printSuccess() (std::cout<< test_name <<" SUCCESS."<<std::endl)
#endif

void run_all_tests() {
    run_test(utilities_amountDaysInMonth, "utilities_amountDaysInMonth");
    run_test(utilities_validDate, "utilities_validDate");
}

void run_test(std::function<bool()> test, std::string test_name)
{
    if(!test()){
        printFail();
        std::cout << std::endl;
        return;
    }
    printSuccess();
    std::cout << std::endl;
}

bool compareFiles(const std::string &filename1, const std::string &filename2)
{
    std::string line1,line2;
    std::fstream file1(filename1),file2(filename2);
    if( !file2){
         std::cerr<<"Error opening file 2" << std::endl;
         return false;
    }
	if(!file1 ){
         std::cerr << "Error opening file 1" << std::endl;
         return false;
    }
    while(!file1.eof()){ //read file until you reach the end
        getline(file1,line1);
        getline(file2,line2);
        if(!(line1==line2))
        {
            return false;
        }
    }
    if(!file2.eof()){
        return false;
    }
    return true;
}

void deleteTextFile(const std::string &filename)
{
    std::remove(filename.c_str());
}

// ----------------------------- TESTS -----------------------------


bool utilities_amountDaysInMonth()
{
    int count = 0;
    count += amountDaysInMonth(2022,1) == 31;
    count += amountDaysInMonth(2022,2) == 28;
    count += amountDaysInMonth(2024,2) == 29;
    count += amountDaysInMonth(2022,3) == 31;
    count += amountDaysInMonth(2022,4) == 30;
    count += amountDaysInMonth(2022,5) == 31;
    count += amountDaysInMonth(2022,6) == 30;
    count += amountDaysInMonth(2022,7) == 31;
    count += amountDaysInMonth(2022,8) == 31;
    count += amountDaysInMonth(2022,9) == 30;
    count += amountDaysInMonth(2022,10) == 31;
    count += amountDaysInMonth(2022,11) == 30;
    count += amountDaysInMonth(2022,12) == 31;
    return count == 13;
}

bool utilities_validDate()
{
    int count = 0;
    count += validDate(2022,12,1) == true;
    count += validDate(2022,13,1) == false;
    count += validDate(2022,-1,1) == false;
    count += validDate(2022,12,32) == false;
    count += validDate(2022,12,31) == true;
    count += validDate(2022,11,31) == false;
    count += validDate(2024,2,29) == true;
    count += validDate(2023,2,29) == false;
    count += validDate(2023,0,2) == false;
    count += validDate(2023,1,2) == true;
    return count == 10;
}
