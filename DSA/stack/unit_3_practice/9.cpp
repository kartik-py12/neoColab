// Single File Programming Question
// Problem Statement



// Ethan and Alya are working together on a simple stack-based program to search for elements in a fixed-size stack implemented using an array. The program has two main operations: pushing elements onto the stack and searching for elements within the stack. They need to implement these operations efficiently.



// Write a program to accomplish the above operations.



// Company Tags: Infosys 

// Input format :
// The first line of input consists of an integer n, representing the number of elements to be pushed onto the stack.

// The next line contains n space-separated integers, each representing an element to be pushed onto the stack.

// The next line consists of an integer s, representing the element to be searched for in the stack.

// Output format :
// If the stack is empty, print "The STACK is empty"

// If the searched element is found in the stack, print "Element found"

// If the searched element is not found in the stack, print "Element not found"



// Refer to the sample outputs for the exact format.

// Code constraints :
// The maximum size of the stack is 30.

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// 3
// Output 1 :
// Element found
// Input 2 :
// 5
// -1 2 3 4 -5
// -6
// Output 2 :
// Element not found
// Input 3 :
// 0
// Output 3 :
// The STACK is empty


// You are using GCC
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=0){
        cout<<"The STACK is empty";
    }
    else{
        
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int find;
    cin>>find;
    bool found =false;
    for(int i=0;i<n;i++){
        if(arr[i]==find){
            cout<<"Element found";
            found=true;
        }
    }
    if (!found){
        cout<<"Element not found";
    }
    }
}