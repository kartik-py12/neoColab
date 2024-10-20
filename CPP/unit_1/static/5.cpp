// Single File Programming Question
// Problem Statement



// Alex is a math enthusiast who loves playing with numbers. One day, Alex came across a challenge to write a program that reverses a given number. Intrigued by the challenge, Alex decides to write a program using reference variables.



// Can you help Alex by creating a program that reverses the number using reference variables?



// Function Name: void reverseNumber



// Note: This is a sample question asked in a HCL interview.

// Input format :
// The input consists of a positive integer N.

// Output format :
// The output displays the reversed number of N.

// Code constraints :
// 1 ≤ N ≤ 107

// Sample test cases :
// Input 1 :
// 157
// Output 1 :
// 751
// Input 2 :
// 120
// Output 2 :
// 21

// You are using GCC
#include <iostream>
using namespace std;
void reverseNumber(int num){

    int temp=num;
    while(temp>0){
        int digit=temp%10;
        cout<<digit;
        temp/=10;
    }
}
int main(){
    int n;
    cin>>n;
    reverseNumber(n);
}