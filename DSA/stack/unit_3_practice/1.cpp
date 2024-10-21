// Single File Programming Question
// Problem Statement



// Sarah is managing a to-do list application where tasks are represented using a stack implemented as an array. She wants to remove the task that is in the middle of the stack. 



// Write a program to help her accomplish this.



// Company Tags: Infosys

// Input format :
// The input consists of a single integer n, the number of tasks.

// Output format :
// The first line of output prints the initial stack elements.

// The second line prints the remaining tasks in the stack after removing the middle task.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 3 ≤ n ≤ 75 (The value of n will be odd)

// Sample test cases :
// Input 1 :
// 7
// Output 1 :
// Initial Stack: 7 6 5 4 3 2 1 
// Stack after Deletion: 7 6 5 3 2 1 
// Input 2 :
// 11
// Output 2 :
// Initial Stack: 11 10 9 8 7 6 5 4 3 2 1 
// Stack after Deletion: 11 10 9 8 7 5 4 3 2 1 


// You are using GCC
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int count=n;
    for(int i=0;i<n;i++){
        arr[i]=count;
        count--;
    }
    int mid=n/2;
    cout<<"Initial Stack: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Stack after Deletion: ";
    for(int i=0;i<n;i++){
        if(i!=mid){
            cout<<arr[i]<<" ";
        }
    }
}