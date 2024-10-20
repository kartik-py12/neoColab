// Single File Programming Question
// Problem Statement



// Selsi, a mathematics teacher, needs a program that takes two integers as input, calculates their sum, and determines if the sum is odd or even. The result should be displayed in a boolean format using the boolalpha manipulator.

// Input format :
// The input consists of two space-separated integers, representing a and b.

// Output format :
// The output prints true if the sum of a and b is odd.

// The output prints false if the sum of a and b is even.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ a, b ≤ 109

// Sample test cases :
// Input 1 :
// 784 48
// Output 1 :
// false
// Input 2 :
// 14 97
// Output 2 :
// true

// You are using GCC
#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int sum =0;
    sum=a+b;
    bool isodd=sum%2!=0;
    cout<<boolalpha<<isodd<<endl;
}