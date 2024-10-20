// Single File Programming Question
// Problem Statement



// Shabu works at a library and needs to analyze the frequency of digits in identification numbers. Help Shabu by writing a program that counts how many times each digit (0-9) appears in a given number. The output should use the setw manipulator function for formatting.



// Note: Make the width length as 2.

// Input format :
// The input consists of an integer N, representing the identification number.

// Output format :
// For each digit (0-9) that appears in the number, output the digit and the number of times it appears, formatted with a width of 2 for the count.



// The output should be in the format: "Digit X: Y times", where X is the digit and Y is its count.



// Refer to the sample outputs for the formatting specifications.

// Code constraints :
// 102 ≤ N ≤ 109

// Sample test cases :
// Input 1 :
// 12312
// Output 1 :
// Digit 1:  2 times
// Digit 2:  2 times
// Digit 3:  1 times
// Input 2 :
// 123
// Output 2 :
// Digit 1:  1 times
// Digit 2:  1 times
// Digit 3:  1 times
// Input 3 :
// 900
// Output 3 :
// Digit 0:  2 times
// Digit 9:  1 times


// You are using GCC
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int arr[10]={0};
    int n;
    cin>>n;
    int temp=n;
    while(temp>0){
        int digit=temp%10;
        arr[digit]++;
        temp/=10;
    }
    for(int i=0;i<10;i++){
        if(arr[i]>0){
        cout<<"Digit "<<i<<": "<<setw(2)<< arr[i]<<" times"<<endl;
        }
    }
}
