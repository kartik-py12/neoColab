// Single File Programming Question
// Problem statement



// Rahul is developing a program to help a construction company calculate the total area of different shapes in a construction project. The company uses various shapes like circles, squares, and triangles in their projects, and they need a tool to quickly determine the total area covered by these shapes in a specific project. 



// The program should allow the user to input the details of each shape used in the project and then calculate the total area.



// Note: This kind of question will help in clearing Capgemini recruitment.



// Formula:

// Circle Calculation = 3.14159 x radius x radius
// Square Calculation = side x side
// Triangle Calculation = 0.5 × base × height
// Total Area = Circle Area + Square Area + Triangle Area
// Input format :
// The first line consists of a string, representing the name of the circle.

// The second line consists of a double value, representing the radius of the circle.

// The third line consists of a string, representing the name of the square.

// The fourth line consists of a double value, representing the side length of the square.

// The fifth line consists of a string, representing the name of the triangle.

// The sixth line consists of a double value, representing the base length of the triangle.

// The last line consists of a double value, representing the height of the triangle.

// Output format :
// The output displays the total area covered by all the shapes in the following format: "Total area of all shapes: [total_area_value]".

// Total area calculation is rounded to two decimal places.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The name of each shape can have a maximum length of 100 characters.

// The radius, side length, base length, and height of each shape will be non-negative floating-point numbers.

// The pi value is 3.14159.

// Sample test cases :
// Input 1 :
// Inner Garden
// 5.5
// Front Lawn
// 10.2
// Backyard
// 8.3
// 6.7
// Output 1 :
// Total area of all shapes: 226.88
// Input 2 :
// Circle Garden
// 3.0
// Square Patio
// 7.5
// Triangle Roof
// 6.2
// 8.4
// Output 2 :
// Total area of all shapes: 110.56


// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main(){
    string circle;
    getline(cin,circle);
    double r;
    cin>>r;
    cin.ignore();
    
    string square;
    getline(cin,square);
    double s;
    cin>>s;
    cin.ignore();
    
    string triangle;
    getline(cin,triangle);
    double b,h;
    cin>>b;
    cin>>h;
    cin.ignore();
    
    double areaC=3.14159*r*r;
    double areaS=s*s;
    double areaT=0.5*b*h;
    double totalArea=areaC+areaS+areaT;
    
    cout<<"Total area of all shapes: "<<fixed<<setprecision(2)<<totalArea;
    
    
}