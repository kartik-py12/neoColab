// Single File Programming Question
// Problem Statement



// You are developing a simple date management system for a small library. Each entry in the library’s catalog must record the date when a book was added. Your task is to create a program that allows you to input a date (day, month, and year) whose attributes are declared within the class Date, display this date, and determine if the year is a leap year or not.

// Input format :
// The input consists of three integers separated by spaces representing the day, month, and year.

// Output format :
// The first line of output will display the date in the format: "day month year".

// The second line will display whether the year is a leap year or not.



// Refer to the sample outputs for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ day ≤ 31

// 1 ≤ month ≤ 12

// 1900 ≤ year ≤ 2100

// Sample test cases :
// Input 1 :
// 19 12 1919
// Output 1 :
// 19 12 1919
// 1919 is not a leap year
// Input 2 :
// 12 04 2004
// Output 2 :
// 12 4 2004
// 2004 is a leap year


#include <iostream>

class LeapYear {
private:
    int day;
    int month;
    int year;

public:
    LeapYear(int d, int m, int y) : day(d), month(m), year(y) {}

    bool isLeapYear() {
 
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                return (year % 400 == 0);
            } else {
                return true;
            }
        } else {
            return false;
        }
    }

    void displayResult() {
        std::cout << day << " " << month << " " << year << std::endl;

        if (isLeapYear()) {
            std::cout << year << " is a leap year" << std::endl;
        } else {
            std::cout << year << " is not a leap year" << std::endl;
        }
    }
};

int main() {
    int day, month, year;

    std::cin >> day;
    std::cin >> month;
    std::cin >> year;

    LeapYear date(day, month, year);

    date.displayResult();

    return 0;
}