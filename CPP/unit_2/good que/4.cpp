// Single File Programming Question
// Problem Statement



// Imagine you are tasked with implementing a program to manage complex numbers. The program should define a Complex class with attributes for the real and imaginary parts of a complex number. Your task is to create two instances of the Complex class, obj1 and obj2, and allow the user to input real and imaginary values for each of them. After setting the data for both objects, you need to display the real and imaginary parts of each complex number. Use the pointer to object to accomplish the task.



// Note: This is a sample question asked in a TCS interview.

// Input format :
// The first line of the input consists of real and imaginary parts of the first complex number.

// The second line of the input consists of real and imaginary parts of second complex number.

// Output format :
// The output displays the real and imaginary parts of both complex numbers.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// -103 <= real part <= 103

// -105 <= imaginary parts <= 105

// Sample test cases :
// Input 1 :
// 1 56
// 2 43
// Output 1 :
// Here the real part is 1
// Here the imaginary part is 56
// Here the real part is 2
// Here the imaginary part is 43
// Input 2 :
// -3 -82
// -4 45
// Output 2 :
// Here the real part is -3
// Here the imaginary part is -82
// Here the real part is -4
// Here the imaginary part is 45

// You are using GCC
//without pointer and class
#include <iostream>
using namespace std;
// int main(){
//     int r1,r2,i1,i2;
//     cin>>r1>>i1;
//     cin>>r2>>i2;
//     cout<<"Here the real part is "<<r1<<endl;
//     cout<<"Here the imaginary part is "<<i1<<endl;
//     cout<<"Here the real part is "<<r2<<endl;
//     cout<<"Here the imaginary part is "<<i2<<endl;
// }

//with pointer and class

class complex{
    private:
        int r1,i1;
    public:
        complex(int real,int imaginary){
            r1=real;
            i1=imaginary;
        }
        
        void print(){
            cout<<"Here the real part is "<<r1<<endl;
            cout<<"Here the imaginary part is "<<i1<<endl;
        }
};

int main(){
    int r1,r2,i1,i2;
    cin>>r1>>i1;
    cin>>r2>>i2;
    complex com(r1,i1);
    complex com1(r2,i2);
    complex *ptr = &com;
    complex *ptr1 = &com1;
    ptr->print();
    ptr1->print();
}