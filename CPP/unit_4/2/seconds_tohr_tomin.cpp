// Single File Programming Question
// Problem Statement



// Peter is working on a project, and his task is to create a program that takes an input integer representing a total number of seconds and utilizes basic to class type conversion to convert it into a Time object.



// The Time class, defined in the code, has private member variables for hours, minutes, and seconds and a constructor that converts the input seconds into these time components.



// After inputting the total seconds, the program constructs a Time object and then calls its display() function to print the time in the format "hours:minutes:seconds". 



// For example, if the user enters 3661 seconds, the program will output "1:1:1" corresponding to 1 hour, 1 minute, and 1 second.



// Company Tag: Wipro

// Input format :
// The input contains an integer representing the time in seconds.

// Output format :
// The output displays the converted time as integers in the following format: "hours:minutes:seconds"



// Refer to the sample output for formatting specifications.

// Code constraints :
// 0 ≤ seconds ≤ 86400

// Sample test cases :
// Input 1 :
// 3661
// Output 1 :
// 1:1:1
// Input 2 :
// 45034
// Output 2 :
// 12:30:34


// You are using GCC
#include <iostream>
using namespace std;

int main(){
    int sec;
    cin>>sec;

    int hr=sec/3600; //converts sec into hr bcz(1hr has 3600 sec (60*60))
    int remsec=sec%3600; //get the remaining secs after hours
    
    // cout<<min;
    // min
    cout<<hr<<":";
    cout<<remsec/60<<":"; //converts the remainning seconds into min
    cout<<remsec%60; // getting the left over seconds 
    // min=sec/60;
    // cout<<min/60;
}