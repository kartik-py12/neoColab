// Single File Programming Question
// Problem Statement



// John is managing a list of tasks using a stack implemented as a linked list. He wants to remove all tasks with even numbers and keep only the tasks with odd numbers in the stack. 



// Your task is to write a program to help him accomplish this.

// Input format :
// The input consists of an integer n, the number of tasks, followed by n integers representing the tasks.

// Output format :
// The first line of output prints the tasks in the stack after inserting all tasks.

// The second line prints the remaining tasks after removing the even-numbered tasks.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 12 45 78 35 59
// Output 1 :
// 59 35 78 45 12 
// 59 35 45 
// Input 2 :
// 8
// 12 45 78 23 56 78 99 65
// Output 2 :
// 65 99 78 56 23 78 45 12 
// 65 99 23 45 


#include <iostream>
#include <vector>
using namespace std;

class mystack{
    private:
        int max;
        int top;
        vector <int> arr;
    public:
        mystack(int size):max(size),top(-1){
            arr.resize(max);
        }
        void push(int x){
            if(top>=max){
                cout<<"Stack is overflow";
            }else{
                arr[++top]=x;
            }
        }
        
        void pop(){
            if(top<0){
                cout<<"Stack is underflow";
            }else{
                cout<<arr[top--];
            }
        }
        
        void displayeven(){
            for(int i=top;i>=0;i--){
                if(arr[i]%2!=0){
                    cout<<arr[i]<<" ";
                    
                }
            }
        }
        
        void display(){
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
        }
};


int main(){
    int n;
    cin>>n;
    mystack s1(n);
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        s1.push(ele);
    }
    s1.display();
    cout<<endl;
    s1.displayeven();
}