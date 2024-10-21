// Single File Programming Question
// Problem Statement



// Lisa is learning about stack data structures in her computer science class. She is particularly interested in performing operations on stacks and wants to practice reversing the elements in a stack. 



// Can you help Lisa by designing a program using an array that allows her to reverse the elements in a stack and display the reversed stack?



// Manage two stacks, A and B.
// Perform stack operations like push and pop on stack A.
// Reverse the elements in stack A and store the reversed elements in stack B.
// Display the elements of stack B, which now contain the reversed elements of stack A.


// Company Tags: Infosys

// Input format :
// The first line consists of an integer n, indicating the number of elements to be pushed onto stack A.

// The second line consists of the values to be pushed onto stack A, separated by a space.

// Output format :
// The first line of output prints "Stack A elements: " followed by the elements of stack A, separated by a space.

// The second line prints "Elements in Stack B (reversed): " followed by the reversed elements of stack A (in stack B), separated by a space.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 20

// 1 ≤ stack elements ≤ 200

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// Output 1 :
// Stack A elements: 5 4 3 2 1 
// Elements in Stack B (reversed): 1 2 3 4 5 
// Input 2 :
// 7
// 10 20 30 40 50 60 70
// Output 2 :
// Stack A elements: 70 60 50 40 30 20 10 
// Elements in Stack B (reversed): 10 20 30 40 50 60 70


// You are using GCC
//88 => 91 done in 3 min;
//92 doing it with stack
#include <iostream>
#include <vector>
using namespace std;

class mystack{
    int top;
    int max;
    vector <int> arr;
    
    public:
        mystack(int n):max(n),top(-1) {}

    void push(int x);
    void pop();
    int peek();
    void display();
    void displayreverse();
    bool isEmpty();
};

void mystack::push(int x){
    if(top>=(max-1)){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        top++;
        arr.push_back(x);
    }
};

void mystack::pop(){
    if(top<0){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        arr[top--];
    }
}

void mystack::display(){
    for(int i=top;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void mystack::displayreverse(){
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}




int main(){
    int n;
    cin>>n;
    mystack s1(n);
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        s1.push(ele);
    }
    cout<<"Stack A elements: ";
    s1.display();
    cout<<"Elements in Stack B (reversed): ";
    s1.displayreverse();
}