// Single File Programming Question
// Problem Statement



// Tao, an engineer, is developing a software tool designed for educational purposes that performs basic arithmetic operations, including addition, subtraction, multiplication, and division.



// To maintain flexibility and adhere to object-oriented programming principles, he plans to create an abstract class named operationsBase, which will include four pure virtual functions: void addition(), void subtraction(), void multiplication(), and void division().



// A derived class, operationsDerived, will implement these functions, enabling users to input two integers for the calculations. The program will output the results of all operations in sequence, separated by spaces while ensuring an error message is displayed for division by zero.

// Input format :
// The input consists of two integer values, a and b, separated by a space.

// Output format :
// The output displays the integers representing the results of the four arithmetic operations: addition, subtraction, multiplication, and division. Each result will be separated by a space.



// If division by zero occurs, print "Division by 0 is not allowed.", in the next line.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// -10000 ≤ a, b ≤ 10000

// The division operation should be valid, i.e., the value of b should not be zero.

// Sample test cases :
// Input 1 :
// 20 10
// Output 1 :
// 30 10 200 2 
// Input 2 :
// 5248 0
// Output 2 :
// 5248 5248 0 
// Division by 0 is not allowed.
// Input 3 :
// -10 10
// Output 3 :
// 0 -20 -100 -1 

// You are using GCC
#include <iostream>
using namespace std;
int main(){
    int a;
    int b;
    cin>>a>>b;
    cout<<a+b<<" "<<a-b<<" "<<a*b;
    if(a==0 || b==0){
        cout<<endl;
        cout<<"Division by 0 is not allowed.";
    }else{
        cout<<" "<<a/b;
    }
}