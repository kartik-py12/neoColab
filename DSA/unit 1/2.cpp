/*
Problem Statement

Ishu wants to create a program that asks users to input their birthdates, 
including the day, month, and year. The program should then display the entered birthdate in 
the format "DD/MM/YYYY."


Write a program to assist Ishu in achieving this task.

Input format :
The input consists of three space-separated integer values, representing the user's 
birthdate(day, month, and year).

Output format :
The output displays the user's birthdate in the format "Your birthday 
is on " followed by the formatted date DD/MM/YYYY.
    */


#include <iostream>

int main (){
    int day, month, year;
    std::cout << "Enter your birthdate (day month year): ";
    std::cin >> day >> month >> year;
    std::cout << "Your birthday is on " << day << "/" << month << "/" << year << std::endl;
    return 0;
}