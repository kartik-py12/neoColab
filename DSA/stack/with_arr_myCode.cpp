// Single File Programming Question
// Problem Statement



// Akash has implemented a simple stack using an array with a maximum size of 10.



// The program provides the following operations:

// Push: Add an integer to the stack.
// Pop: Remove an integer from the top of the stack.
// Check if Stack is Full: Determine if the stack is full.
// Check if Stack is Empty: Determine if the stack is empty.
// Exit: Terminate the program.


// Company Tags: Capgemini 

// Input format :
// The choice represents the operation to be performed:

// 1: Push an integer onto the stack. The following input is the element to be pushed.

// 2: Pop an integer from the stack.

// 3: Check if the stack is full.

// 4: Check if the stack is empty.

// 5: Exit the program.

// Output format :
// The output prints one of the following messages:

// If the choice is 1 (Push), there is no output.

// If the choice is 2 (Pop) and the stack is empty, print "Stack is empty!".

// If the choice is 3 (Check if Full), and the stack is full, print "Stack is full!", and if the stack is not full, print "Stack is not full"

// If the choice is 4 (Check if Empty), and the stack is empty, print "Stack is empty!", and if the stack is not empty, print "Stack is not empty"

// If the choice is 5 (Exit), the program should terminate immediately.

// If the choice is more than 6, it prints "Invalid choice".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// Valid choice = 1, 2, 3, 4, 5

// 1 ≤ stack elements ≤ 100

// Sample test cases :
// Input 1 :
// 1 2
// 1 6
// 2
// 3
// 4
// 5
// Output 1 :
// Stack is not full
// Stack is not empty
// Input 2 :
// 1 3
// 1 4
// 1 5
// 1 7
// 1 18
// 1 19
// 1 20
// 1 21
// 1 34
// 1 76
// 4
// 3
// 5
// Output 2 :
// Stack is not empty
// Stack is full!
// Input 3 :
// 1 2
// 1 4
// 1 5
// 1 76
// 1 89
// 1 34
// 1 23
// 1 65
// 1 45
// 1 23
// 2
// 2
// 2
// 2
// 2
// 2
// 2
// 2
// 2
// 2
// 4
// 5
// Output 3 :
// Stack is empty!
// Input 4 :
// 1 6
// 1 7
// 9
// 5
// Output 4 :
// Invalid choice
// Input 5 :
// 1 4
// 2
// 2
// 5
// Output 5 :
// Stack is empty!



// You are using GCC
//123=>141 around 20 min with learning
#include <iostream>
using namespace std;

class mystack{
    int top;
    int max;
    int arr[10];
    
    public:
        mystack() {
            max=10;
            top=-1;
        }
        
        int push(int x){
            if(top>=max-1){
                return -1;
            }
            else{
                arr[++top]=x;
            }
        }
        
        int pop(){
            if(top<0){
                cout<<"Stack is empty!"<<endl;
                return 0;
            }else{
                arr[top--];
            }
        }
        
        int isFull(){
            if(top>=max-1){
                cout<<"Stack is full!"<<endl;
                return -1;
            }
            else{
                cout<<"Stack is not Full"<<endl;
            }
        }
        
        void isEmpty(){
            if(top<0){
                cout<<"Stack is empty!"<<endl;
            }
            else{
                cout<<"Stack is not empty"<<endl;
            }
            
        }
};

int main(){
    mystack s1;
    
    int choice;
    cin>>choice;
    while(choice!=5){
    if(choice==1){
        int ele;
        cin>>ele;
        s1.push(ele);
    }
    else if(choice==2){
        s1.pop();
    }
    
    else if(choice==3){
        s1.isFull();
    }
    else if(choice==4){
        s1.isEmpty();
    }
    else{
        cout<<"Invalid choice"<<endl;
    }
    cin>>choice;
    
        
    }
};
