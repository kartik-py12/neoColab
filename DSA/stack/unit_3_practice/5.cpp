// Single File Programming Question
// Problem Statement



// John is managing a list of numbers using a stack implemented as an array. He wants to push numbers onto the stack, calculate the average of the numbers in the stack, and pop a number from the stack while displaying the current average. Write a program to assist him with these tasks.

// Input format :
// The first line of input contains an integer n, representing the number of elements to be pushed onto the stack.

// The second line contains n space-separated integers, each representing an element to be pushed onto the stack.

// Output format :
// After pushing elements onto the stack, the first line of output prints the initial elements on the stack.

// The second line prints the average of the stack values, rounded off to two decimal places.

// If an element is popped from the stack, the third line prints the popped value.

// The fourth line prints the updated average of the stack, rounded off to two decimal places.



// Refer to the sample output for the exact format.

// Code constraints :
// The maximum size of the stack is 10.

// Sample test cases :
// Input 1 :
// 3
// 1 2 3
// Output 1 :
// Initial Stack: 3 2 1 
// Average: 2.00
// Popped Value: 3
// Updated Average: 1.50
// Input 2 :
// 6
// 23 78 94 27 19 74
// Output 2 :
// Initial Stack: 74 19 27 94 78 23 
// Average: 52.50
// Popped Value: 74
// Updated Average: 48.20


#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class mystack {
    vector<int> arr;  // No need to pre-allocate; use dynamic vector size
    int top;
    double sum;  // Keep track of sum for O(1) average calculation
    
public:
    mystack() : top(-1), sum(0) {}  // Initialize with top=-1 and sum=0
    
    // Push operation
    void push(int x) {
        arr.push_back(x);  // No need to resize manually, vector grows dynamically
        sum += x;  // Update running sum
        ++top;
    }
    
    // Pop operation
    void pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
        } else {
            sum -= arr[top];  // Update running sum
            cout << "Popped Value: " << arr[top] << endl;
            arr.pop_back();  // Remove the top element
            --top;
        }
    }
    
    // Display all elements in stack
    void display() const {
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    // Calculate average of elements
    void avg() const {
        if (top < 0) {
            cout << "Stack is empty" << endl;
        } else {
            cout << fixed << setprecision(2) << sum / (top + 1) << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    mystack s1;  // Stack initialization
    
    // Push elements to the stack
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        s1.push(ele);
    }
    
    // Display stack
    cout << "Initial Stack: ";
    s1.display();
    
    // Display average
    cout << "Average: ";
    s1.avg();
    
    // Pop an element and show the updated average
    s1.pop();
    cout << "Updated Average: ";
    s1.avg();
    
    return 0;
}