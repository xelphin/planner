/*
RUN TESTS:
g++ -std=c++11 -Wall -Werror -pedantic-errors -g *.cpp -o output
./ouptut
*/

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <random>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <functional>

#include "./utilities.h"


// --RUN TESTS
void run_all_tests();

// --UTILITIES
void run_test(std::function<bool()> test, std::string test_name);
bool compareFiles(const std::string &filename1, const std::string &filename2);
void deleteTextFile(const std::string &filename);
std::string readFileIntoString(const std::string& path);

// --TESTS

// UTILITIES
bool utilities_amountDaysInMonth();
bool utilities_validDate();


#endif