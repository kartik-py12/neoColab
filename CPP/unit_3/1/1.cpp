// Single File Programming Question
// Problem Statement



// You are required to create a program that can perform basic arithmetic operations on complex numbers. A complex number consists of a real part and an imaginary part. The program should provide the following functionality:



// Create two instances of the Complex class using the default constructor, Complex c1 and Complex c2.
// Prompt the user to enter the real and imaginary parts for both c1 and c2 using the setvalue() method.
// Calculate the sum of c1 and c2 using the sum() method and store the result in a third instance of the Complex class, c3.
// Display the result of the addition using the display() method.
// Ensure that a destructor is called for each Complex object when it is destroyed.


// Company Tags: Wipro

// Input format :
// The input consists of two lines, consisting of the real and imaginary real parts of two complex numbers as float values, separated by space.

// Output format :
// The output displays "Sum of two complex numbers is X +Yi" where X is the real part and Y is the imaginary part of the result value as float values rounded to one decimal value.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 0.0 ≤ real, imaginary parts ≤ 1000.0

// Sample test cases :
// Input 1 :
// 2.7 3.5 
// 3.2 1.6
// Output 1 :
// Sum of two complex numbers is 5.9 + 5.1i
// Input 2 :
// 1.0 2.0
// 3.0 2.0
// Output 2 :
// Sum of two complex numbers is 4.0 + 4.0i


#include <iostream>
#include <iomanip>
using namespace std;

class Complex{
    private:
        float real;
        float imag;
    public:
        // creating a default constructer
        Complex():real(0),imag(0){}
        
        void setvalue(float r,float i){
            real=r;
            imag=i;
        }
        
        Complex sum(const Complex& c){
            Complex result;
            result.real=real+c.real;
            result.imag=imag+c.imag;
            return result;
        }
        
        void display(){
            cout<<"Sum of two Complex numbers is "<<fixed<<setprecision(1)<<real<<" + "<<imag<<"i";
        }
        
        ~Complex(){
            
        }
};

int main(){
    Complex c1,c3;
    Complex c2;
    float r1,i1;
    cin>>r1>>i1;
    float r2,i2;
    cin>>r2>>i2;
    c1.setvalue(r1,i1);
    c2.setvalue(r2,i2);
    
    c3=c1.sum(c2);
    
    c3.display();
}