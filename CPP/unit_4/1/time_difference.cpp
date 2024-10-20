// Single File Programming Question
// Problem Statement



// In a distant realm where time was more than just numbers, a talented watchmaker named Edward crafted a unique Time class with the extraordinary ability to calculate time differences using the '-' operator.



// One day, a curious young apprentice named Lily encountered Edward's creation and was fascinated by its time-manipulation powers. Eager to put it to the test, Lily entered two specific times into the console.



// As the magical operator performed its calculations, the time difference was revealed, leaving Lily in awe of the operator overloading concept and its potential to unravel the mysteries of time in their timekeeping adventures.

// Input format :
// The first line of input consists of Time 1 in the format "hours minutes seconds," separated by spaces.

// The second line of input consists of Time 2 in the format "hours minutes seconds," separated by spaces.

// Each time component (hours, minutes, and seconds) should be entered as an integer.

// Output format :
// The first two lines of output display Time 1 and Time 2 in the format "hours h minutes m seconds s".

// The next line of output displays the time difference between Time 1 and Time 2 in the same format.



// Refer to the sample output for further formatting specifications.

// Code constraints :
// The hours, minutes, and seconds should be non-negative integers.

// The hours should be in the range of [0, 23].

// The minutes and seconds should be in the range of [0, 59].

// Sample test cases :
// Input 1 :
// 5 33 10
// 2 22 25
// Output 1 :
// Time 1: 5h 33m 10s
// Time 2: 2h 22m 25s
// Time difference: 3h 10m 45s
// Input 2 :
// 20 20 10
// 13 20 50
// Output 2 :
// Time 1: 20h 20m 10s
// Time 2: 13h 20m 50s
// Time difference: 6h 59m 20s


// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int h1,m1,s1;
    int h2,m2,s2;
    int th,tm,ts;
    int borrows=0,borrowm=0;
    cin>>h1>>m1>>s1;
    cin>>h2>>m2>>s2;
    cout<<"Time 1: "<<h1<<"h "<<m1<<"m "<<s1<<"s"<<endl;
    cout<<"Time 2: "<<h2<<"h "<<m2<<"m "<<s2<<"s"<<endl;
    
    ts=s1-s2;
    if(ts<0){
        ts+=60;
        borrows++;
    }
    tm=m1-m2-borrows;
    if(tm<0){
        tm+=60;
        borrowm++;
    }
    th=h1-h2-borrowm;

    cout<<"Time difference: "<<th<<"h "<<tm<<"m "<<ts<<"s";
};