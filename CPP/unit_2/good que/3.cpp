// Single File Programming Question
// Problem Statement



// Write a program that checks the availability of a book based on its price and availability status. The program should read a price and a character indicating availability ('Y' or 'N'), and determine if the book is available and priced below 2500.50. Output "Yes" if the book is available and affordable, otherwise output "No".

// Input format :
// The first line of input consists of the price of the book as a float value.

// The third line of input consists of the availability status of the book (Y, y, N, or n).

// Output format :
// The output prints "Yes", if the inputs are valid and in the given range.

// The output prints "No", if the inputs are not valid and not in the given range.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1.0 ≤ price ≤ 10,000.0

// The availability status should be either Y, y, N, or n only.

// Sample test cases :
// Input 1 :
// 2300.50
// y
// Output 1 :
// Yes
// Input 2 :
// -89.90
// N
// Output 2 :
// No
// Input 3 :
// 2300.34
// Y
// Output 3 :
// Yes
// Input 4 :
// 6543.00
// n
// Output 4 :
// No

// You are using GCC
#include <iostream>
#include <cctype>
using namespace std;

int main(){
    float num;
    cin>>num;
    void *ptr=&num;
    char av;
    cin>>av;
    char av1=tolower(av);
    void *ptr1=&av1;
    float* pt=(float*)ptr;
    char* pt1=(char*)ptr1;

    if((*pt<2500.50) &&(*pt1=='y')) {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}