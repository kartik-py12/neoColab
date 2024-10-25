#include <iostream>
#define MAX 1000  // Maximum size of the stack

class Stack {
    int top;        // Index of the top element
    int arr[MAX];   // Array to hold stack elements

public:
    Stack() { top = 0; }   // Constructor initializes `top` as -1, meaning the stack is empty
    bool push(int x);       // Adds an element onto the stack
    int pop();              // Removes the top element from the stack
    int peek();             // Returns the top element
    bool isEmpty();         // Checks if the stack is empty
};

// Adds an element to the stack
bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        std::cout << "Stack Overflow\n";
        return false;
    } else {
        arr[++top] = x;
        std::cout << x << " pushed into stack\n";
        return true;
    }
}

// Removes the top element from the stack
int Stack::pop() {
    if (top < 0) {
        std::cout << "Stack Underflow\n";
        return 0;
    } else {
        int x = arr[top--];
        return x;
    }
}

// Returns the top element without removing it
int Stack::peek() {
    if (top < 0) {
        std::cout << "Stack is Empty\n";
        return 0;
    } else {
        return arr[top];
    }
}

// Checks if the stack is empty
bool Stack::isEmpty() {
    return (top < 0);
}

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << s.pop() << " popped from stack\n";
    std::cout << "Top element is " << s.peek() << std::endl;
    std::cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << std::endl;
    return 0;
}
