// Single File Programming Question
// Problem Statement



// In a busy hospital, beds are allocated to patients as they arrive. You are an administrator at a hospital in charge of managing the allocation of beds. 



// You need to perform the following tasks:

// Allocate Beds: As new patients arrive, their beds are assigned and pushed onto the stack.
// View Allocation: After allocating a series of beds, you need to view the stack of beds in the order they were allocated (i.e., from the most recently allocated to the oldest).
// Sort Beds: To optimize bed management, you need to sort the stack of bed IDs in ascending order based on their IDs.


// Write a program to implement the above operations using a stack with a linked list.

// Input format :
// The first line of input contains an integer n, representing the number of beds to be allocated.

// The second line contains n space-separated integers, each denoting a bed ID.

// Output format :
// The first line of output prints the original stack of bed IDs in the order they were allocated.

// The second line prints the stack of bed IDs sorted in ascending order.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ ID ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 4 5 6 3 2
// Output 1 :
// Original Stack: 2 3 6 5 4 
// Sorted Stack: 2 3 4 5 6 
// Input 2 :
// 8
// 3 2 4 5 6 9 8 7
// Output 2 :
// Original Stack: 7 8 9 6 5 4 2 3 
// Sorted Stack: 2 3 4 5 6 7 8 9 



// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

class mystack{
    int max;
    int top;
    vector <int> arr;
    
    public:
        mystack(int n):max(n),top(-1){}

        void push(int x){
            ++top;
            arr.push_back(x);
        };
        
        void display(){
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" "; 
            }
            cout<<endl;
        }
        
        void sort(){
            for(int i=0;i<=top;i++){
                for(int j=0;j<i;j++){
                    if(arr[i]>arr[j]){
                        int temp=arr[i];
                        arr[i]=arr[j];
                        arr[j]=temp;
                    }
                }
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
    cout<<"Original Stack: ";
    s1.display();
    cout<<"Sorted Stack: ";
    s1.sort();
    s1.display();
}