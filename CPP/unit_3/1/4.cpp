// Single File Programming Question
// Problem Statement



// Create a class named AddAmount with a private member variable amount initialized to 50 by the default constructor. Implement a method to add a user-defined value to the amount and another method named print_amount to display both the default and final amounts. In the main function, instantiate the class, accept user input for the amount to add, and display the results.

// Input format :
// The input consists of an integer representing the amount to add.

// Output format :
// The first line displays the default amount (50).

// The second line displays the final amount after adding the user-defined value.



// Refer to the sample output for the exact format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ amount ≤ 1000

// Sample test cases :
// Input 1 :
// 400
// Output 1 :
// Default amount: 50
// Final amount: 450
// Input 2 :
// 214
// Output 2 :
// Default amount: 50
// Final amount: 264


// You are using GCC
#include <iostream>
using namespace std;

class AddAmount{
    private:
        int constant;
        int result;
    public:
        AddAmount():constant(50),result(0){}
        
        void add(int val){
            result=val+constant;
        }
        
        void print_amount(){
            cout<<"Default amount: 50"<<endl;
            cout<<"Final amount: "<<result<<endl;
        }
};



int main(){
    int value;
    cin>>value;
    AddAmount addamount;
    
    addamount.add(value);
    addamount.print_amount();

}