// Single File Programming Question
// Problem Statement



// Nandha is learning about data structures and wants to implement a stack data structure using an array. He seeks your help in writing a program that can perform stack operations like push and pop as well as display the top element of the stack. The program should display the top element of the stack or indicate if the stack is empty.



// Can you help him write this program?

// Input format :
// The first line of input contains an integer n, representing the number of elements Nandha wants to push onto the stack.

// The second line contains n space-separated integers, each representing the elements to be pushed onto the stack.

// Output format :
// The first line of output prints the stack elements.

// The second line prints the top element of the stack.

// The third line prints the result, after the pop operation.

// The fourth line prints the top element of the stack, after performing the pop operation.

// If the stack is empty, display "Stack is empty".



// Refer to the sample output for formatting specifications.

// Code constraints :
// The maximum size of the stack is 20.

// 1 ≤ elements ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 12 89 45 32 65
// Output 1 :
// 65 32 45 89 12 
// Top element is 65
// 32 45 89 12 
// Top element is 32
// Input 2 :
// 0
// Output 2 :
// Stack is empty
// Input 3 :
// 1
// 90
// Output 3 :
// 90 
// Top element is 90
// Stack is empty


// You are using GCC
//9

#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=n-1;i>=0;i--){
        int ele;
        cin>>ele;
        arr[i]=ele;
    }
    if(n!=0){
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Top element is "<<arr[0]<<endl;
    n--;
    for(int i=0;i<n;i++){
        arr[i]=arr[i+1];
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    if(n!=0){
    cout<<"Top element is "<<arr[0]<<endl;
    n--;
    }
    else{
        cout<<"Stack is empty";
    }
    
    }
    else{
        cout<<"Stack is empty";
    }
}