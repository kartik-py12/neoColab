// Single File Programming Question
// Problem Statement



// In an online bookstore, customers are able to place orders for books, and the system maintains these orders using a stack data structure implemented with a linked list. When a new order is placed, it is added to the top of the stack. The store manager can view all orders in the stack and check the latest order placed.



// Your task is to write a program to accomplish this task.



// Company Tags: Capgemini

// Input format :
// The first line of input contains an integer n, representing the number of book orders to be placed.

// The second line contains n space-separated integers, each representing a book order ID.

// Output format :
// The first line of output prints "Stack elements: " followed by the IDs of all book orders in the stack, starting from the top.

// The second line prints "Top element: " followed by the ID of the latest book order.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15

// 1 ≤ book ID ≤ 1000

// Sample test cases :
// Input 1 :
// 8
// 1 4 7 8 5 2 3 6
// Output 1 :
// Stack elements: 6 3 2 5 8 7 4 1 
// Top element: 6
// Input 2 :
// 3
// 12 45 62
// Output 2 :
// Stack elements: 62 45 12 
// Top element: 62

// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

class mystack{
    int max;
    int top;
    vector<int>arr;
    
    public:
        mystack(int n):max(n),top(-1){}

        void push(int x){
            top++;
            arr.push_back(x);
        }
        
        void display(){
            cout<<"Stack elements: ";
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        
        void peek(){
            cout<<"Top element: "<<arr[top];
        }
    
    
};


int main(){
    int n;
    cin>>n;
    mystack s1(n);
    for (int i=0;i<n;i++){
        int ele;
        cin>>ele;
        s1.push(ele);
    }
    
    s1.display();
    s1.peek();
    
    
}