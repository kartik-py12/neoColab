// Single File Programming Question
// Problem Statement



// Imagine you are writing a program to calculate the circumference and area of a circular garden, given its radius. You want to represent the garden as a structure, and you want the program to display the results rounded off to 2 decimal places.



// By entering the radius of the garden, the program will calculate and output the circumference and area of the circular garden, providing you with valuable information for gardening purposes.



// Structure Name: Circle



// Formula:

// circumference = 2 * PI * radius
// area = PI * radius2
// Assume that the PI value is 3.14. Use pow() from the math library.

// Input format :
// The input consists of a single floating-point number representing the radius of the circle.

// Output format :
// The first line of output displays the circumference of the circle, as a float value rounded off to two decimal places.

// The second line of output displays the area of the circle, as a float value rounded off to two decimal places.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1.00 ≤ radius ≤ 120.00

// Sample test cases :
// Input 1 :
// 8.3
// Output 1 :
// 52.12
// 216.31
// Input 2 :
// 5.48
// Output 2 :
// 34.41
// 94.30


// You are using GCC
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Circle{
    float radius;
    float circumference;
    float area;
    
    void cf(){
        circumference=2*3.14*radius;
    }
    
    void ar(){
        area=3.14*pow(radius,2);
    }
    
};

int main(){
    Circle garden;
    cin>>garden.radius;
    garden.cf();
    garden.ar();
    cout<<fixed<<setprecision(2)<<garden.circumference<<endl;
    cout<<fixed<<setprecision(2)<<garden.area<<endl;
    
}