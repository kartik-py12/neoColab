// Single File Programming Question
// Problem Statement



// Imagine you are organizing a game where you need to keep track of the scores of players and also quickly find out the highest score among them. 



// You have a stack-based system to manage the scores, where each operation can be one of the following:

// Push Score: Add a new score to the top of the stack.
// Pop Score: Remove the most recent score from the top of the stack.
// Get Maximum Score: Retrieve the highest score currently in the stack.
// Print Scores: Display all the scores currently in the stack, from the most recent to the oldest.


// Implement the task using arrays.

// Input format :
// The input consists of a choice in the menu for interacting with the stack. The choices are as follows:

// 1: Push an element onto the stack. The next input is the element to push, separated by a space.

// 2: Pop the top element from the stack.

// 3: Find and print the maximum element in the stack.

// 4: Print all elements currently in the stack.

// 5: Exit the program.

// Output format :
// The program performs various actions based on the user's choices and prints messages accordingly.

// If an element is pushed onto the stack, no specific message is printed.
// If an element is popped from the stack, no specific message is printed unless the stack is empty, in which case it prints "Stack is empty"
// If the maximum element in the stack is queried, it prints "Maximum element: " followed by the maximum element in the stack. If the stack is empty when querying the maximum, it prints "Maximum element: -1".
// If the elements in the stack are printed, they are separated by spaces. If the stack is empty, it prints, "Stack is empty"
// If an invalid choice is made, it prints "Invalid choice"


// Refer to the sample output for formatting specifications.

// Code constraints :
// The maximum size of the stack is 10.

// Sample test cases :
// Input 1 :
// 1 25
// 1 43
// 2
// 1 15
// 1 74
// 1 39
// 1 50
// 2 
// 3
// 4
// 5
// Output 1 :
// Maximum element: 74
// 39 74 15 25 
// Input 2 :
// 1 2
// 1 4
// 6
// 2
// 2
// 2
// 3
// 4
// 5
// Output 2 :
// Invalid choice
// Stack is empty
// Maximum element: -1
// Stack is empty
// Input 3 :
// 1 23
// 2
// 3
// 4
// 5
// Output 3 :
// Maximum element: -1
// Stack is empty


// You are using GCC
//245 - 265
#include <iostream>
#include <vector>
using namespace std;

class mystack{
  int top;
  vector<int>arr;
  
  public:
    mystack():top(-1){}
    
    void push(int x){
        if(top<9){ //given max limit of array 10 and top start from 0-9 =10
        ++top;
        arr.push_back(x);
            
        }
    }
    
    void pop(){
        if(top<0){
            cout<<"Stack is empty"<<endl;
        }else{
            --top;
            arr.pop_back();
        }
    }
    
    int maxfind(){
        int max=0;
        if(top<0){
            cout<<"Maximum element: -1"<<endl;
            return 0;
        }else{
            for(int i=top;i>=0;i--){
                if(arr[i]>max){
                    max=arr[i];
                }
            }
        }
        
        cout<<"Maximum element: "<<max<<endl;
    }
    
    void display(){
        if(top<0){
            cout<<"Stack is empty"<<endl;
        }else{
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }
    
};


int main(){
    int choice;
    mystack s1;
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
            s1.maxfind();
        }
        else if(choice==4){
            s1.display();
        }
        else{
            cout<<"Invalid choice"<<endl;
        }
        
        
        cin>>choice;
        
        
        
        
    }
}

