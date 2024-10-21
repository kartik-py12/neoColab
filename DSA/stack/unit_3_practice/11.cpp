// Single File Programming Question
// Problem Statement



// Mira wants to create a program that allows her to manipulate a stack using a linked list, perform push and pop operations, and display the elements in the stack. 



// She would like a user-friendly interface that presents a menu with the following options:

// Push Operation: Add an integer to the top of the stack.
// Pop Operation: Remove and discard the integer from the top of the stack.
// Display Stack: Display all the elements currently in the stack, from top to bottom.
// Exit the Program: Terminate the program.
// Input format :
// The program expects Mira to enter a choice (an integer) corresponding to the operation she wants to perform:

// 1: Push the integer value onto the stack. The following input is an integer to push onto the stack.

// 2: Pop an integer from the stack.

// 3: Display the elements currently in the stack.

// 4: Exit the program.

// Output format :
// The output displays messages according to the chosen menu option and the status of the stack:

// "Stack is empty. Cannot perform pop operation" when attempting to pop from an empty stack.
// "Stack is empty" when attempting to display when the stack is empty.
// "Elements in the stack: " followed by the elements in the stack when choosing option 3.
// "Exiting the program" when choosing option 4.
// "Invalid choice" when entering an invalid menu choice.


// Refer to the sample output for the exact format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// Valid choice = 1, 2, 3, 4.

// 0 ≤ stack elements ≤ 100

// Sample test cases :
// Input 1 :
// 1
// 5
// 1
// 10
// 1
// 25
// 2
// 3
// 4
// Output 1 :
// Elements in the stack: 10 5 
// Exiting the program
// Input 2 :
// 1
// 5
// 3
// 8
// 4
// Output 2 :
// Elements in the stack: 5 
// Invalid choice
// Exiting the program
// Input 3 :
// 1
// 2
// 1
// 7
// 2
// 2
// 3
// 4
// Output 3 :
// Stack is empty
// Exiting the program
// Input 4 :
// 1
// 4
// 2
// 2
// 3
// 4
// Output 4 :
// Stack is empty. Cannot perform pop operation
// Stack is empty
// Exiting the program


// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

class mystack{
    int max;
    int top;
    vector<int>arr;
    
    public:
        mystack():top(-1) {}
        
        void push(int x){
            top++;
            arr.push_back(x);
        }
        
        void pop(){
            if(top<0){
                cout<<"Stack is empty. Cannot perform pop operation"<<endl;
            }
            else{
                top--;
                arr.pop_back();
            }
        }
        
        int display(){
            if(top<0){
                cout<<"Stack is empty"<<endl;
                return 0;
            }
            cout<<"Elements in the stack: ";
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }
};

int main(){
    int n;
    cin>>n;
    mystack s1;
    while(n!=4){
        if(n==1){
            int ele;
            cin>>ele;
            s1.push(ele);
        }
        else if(n==2){
            s1.pop();
        }
        else if(n==3){
            s1.display();
        }
        else{
            cout<<"Invalid choice"<<endl;
        }
        
        cin>>n;
    }
    
    cout<<"Exiting the program";
}