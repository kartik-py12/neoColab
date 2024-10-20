// Single File Programming Question
// Problem Statement



// Imagine you have two objects: obj1 and obj2, each with a numerical value. You want to create a simple program that allows you to compare these values and determine whether they are equal or not while using the "this" pointer concept.

// Input format :
// The input consists of two integer values for obj1 and obj2, separated by a space.

// Output format :
// After comparing the values of obj1 and obj2, the program should display one of the following messages:

// "The values are equal" if the values are equal.
// "The values are not equal" if the values are not equal.


// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// -105 ≤ obj1, obj2 ≤ 105

// Sample test cases :
// Input 1 :
// 10 20
// Output 1 :
// The values are not equal
// Input 2 :
// 30 30
// Output 2 :
// The values are equal
// Input 3 :
// -20 -20
// Output 3 :
// The values are equal

// You are using GCC
#include <iostream>
using namespace std;

class equal1{
    private:
        int n1;
        int n2;
    public:
        equal1(int num1,int num2){
            this->n1=num1;
            this->n2=num2;
        }
        
        void display(){
            if(this->n1==this->n2){
                cout<<"The values are equal";
            }else{
                cout<<"The values are not equal";
            }
        }
        
};

int main(){
    int n1,n2;
    cin>>n1>>n2;
    equal1 eq(n1,n2);
    equal1 *ptr =&eq;
    ptr->display();
}