// Single File Programming Question
// Problem Statement



// Bindu is working on a program to convert decimal numbers to binary representation using a stack data structure implemented with a linked list. She needs your help in designing and implementing this program.



// Your task is to design and implement the stack with the specified push and pop operations to support this conversion.

// Input format :
// The input consists of an integer d, representing the decimal number to be converted into binary.

// Output format :
// The output prints "Binary representation: " followed by the binary representation of the input decimal number.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The stack used for the conversion can have a maximum size of 32.

// 1 ≤ d ≤ 512

// Sample test cases :
// Input 1 :
// 10
// Output 1 :
// Binary representation: 1010
// Input 2 :
// 37
// Output 2 :
// Binary representation: 100101


// You are using GCC
// solve this nice question

// Plan:
// Stack using Linked List: We'll implement a stack with two main operations: 
// push (to add elements) and pop (to remove and return the top element). 
// The stack will be implemented using a singly linked list.

// Decimal to Binary Conversion:

// We'll repeatedly divide the decimal number by 2 and push the remainder (0 or 1) onto the stack.
// Once we have all the bits pushed to the stack, we'll pop and print the bits in the correct binary order.


#include <iostream>
#include <vector>
using namespace std;

void decimalToBinary(int n){
    if(n==0 ){
        return;
    }
    else{
        //reccursive call
        decimalToBinary(n/2);
        //print the reminder 0 or 1
        cout<<n%2;
    }
}

int main(){
    int d;
    cin>>d;
    cout<<"Binary representation: ";
    decimalToBinary(d);
}