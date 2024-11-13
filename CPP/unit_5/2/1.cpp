// Single File Programming Question
// Problem Statement



// Gowtham, a computer science student, is exploring object-oriented programming. He created a base class called Demo with two integer attributes, num1, and num2, along with a virtual method display. To enhance functionality, he derived a class called Derived that overrides the display method to present the values with additional context.



// Gowtham's program takes two integer inputs, dynamically allocates an object of the Derived class, and displays the numbers. After displaying, the program deletes the object to ensure proper cleanup and destructor calls.



// Your task is to implement this program according to Gowtham's design and demonstrate the output with two integer inputs.

// Input format :
// The input consists of space-separated integers num1 and num2.

// Output format :
// The output consists of several lines displaying the construction and destruction of objects, followed by the values of num1 and num2 from the derived class:

// "Inside Demo Constructor"

// "Inside Derived Constructor"

// "Derived - Number 1: n1" (where n1 is the first integer input)

// "Derived - Number 2: n2" (where n2 is the second integer input)

// "Inside Derived Destructor"

// "Inside Demo Destructor"



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n1, n2 ≤ 2000

// Sample test cases :
// Input 1 :
// 10 20
// Output 1 :
// Inside Demo Constructor
// Inside Derived Constructor
// Derived - Number 1: 10
// Derived - Number 2: 20
// Inside Derived Destructor
// Inside Demo Destructor


#include <iostream>
using namespace std;

class Demo {
protected:
    int num1, num2;
public:
    Demo() { cout << "Inside Demo Constructor" << endl; }
    virtual void display() = 0;
    virtual ~Demo() { cout << "Inside Demo Destructor" << endl; }
};

class Derived : public Demo {
public:
    Derived() { cout << "Inside Derived Constructor" << endl; }
    
    void setNumbers(int n1, int n2) {
        num1 = n1;
        num2 = n2;
    }
    
    void display() override {
        cout << "Derived - Number 1: " << num1 << endl;
        cout << "Derived - Number 2: " << num2 << endl;
    }

    ~Derived() { cout << "Inside Derived Destructor" << endl; }
};

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    Derived* obj = new Derived();
    obj->setNumbers(n1, n2);
    obj->display();
    delete obj;
    return 0;
}