// Single File Programming Question
// Problem Statement



// You have been assigned the responsibility of implementing the Area class for the construction company's software application.



// You have declared the following inline functions within the Area class: get(), squareArea(), rectangleArea(), circleArea(), and parallelogramArea(). These functions are used to calculate the area of different geometric shapes.



// Write a suitable program to calculate the areas of squares, rectangles, circles, and parallelograms. Provide the complete code solution, including the class definition, method implementations, and the main method where the object is created and the methods are called.



// Note: This is a sample question asked in a HCL interview.

// Input format :
// The first line consists of an integer value representing the side of a square. 

// The second line consists of two integers representing the length and breadth of a rectangle, respectively. 

// The third line consists of a floating-point value representing the radius of a circle.

// The last line consists of two floating-point values representing the base and height of a parallelogram, respectively.

// Output format :
// The output prints the areas of the square, rectangle, circle, and parallelogram in separate lines with the corresponding labels.

// The output should be rounded off to two decimal places for the area of the circle and parallelogram.



// Refer to the sample output for formatting specifications.

// Code constraints :
// Take pi value as 3.14.

// Sample test cases :
// Input 1 :
// 4
// 5 4
// 6.5
// 6.2 4.5
// Output 1 :
// Area of the square: 16
// Area of the rectangle: 20
// Area of the circle: 132.66
// Area of the parallelogram: 27.90
// Input 2 :
// 6
// 10 12
// 8
// 15.2 18.7
// Output 2 :
// Area of the square: 36
// Area of the rectangle: 120
// Area of the circle: 200.96
// Area of the parallelogram: 284.24

#include <iostream>
#include <iomanip>  // For std::fixed and std::setprecision

using namespace std;

class Area {
public:
    // Inline function to calculate the area of a square
    inline int squareArea(int side) {
        return side * side;
    }

    // Inline function to calculate the area of a rectangle
    inline int rectangleArea(int length, int breadth) {
        return length * breadth;
    }

    // Inline function to calculate the area of a circle
    inline double circleArea(double radius) {
        const double PI = 3.14;
        return PI * radius * radius;
    }

    // Inline function to calculate the area of a parallelogram
    inline double parallelogramArea(double base, double height) {
        return base * height;
    }
};

int main() {
    // Create an object of the Area class
    Area areaCalc;
    
    // Variables to hold input values
    int side, length, breadth;
    double radius, base, height;
    
    // Read input values
    cin >> side;
    cin >> length >> breadth;
    cin >> radius;
    cin >> base >> height;

    // Calculate and print areas
    cout << "Area of the square: " << areaCalc.squareArea(side) << endl;
    cout << "Area of the rectangle: " << areaCalc.rectangleArea(length, breadth) << endl;
    cout << fixed << setprecision(2);
    cout << "Area of the circle: " << areaCalc.circleArea(radius) << endl;
    cout << "Area of the parallelogram: " << areaCalc.parallelogramArea(base, height) << endl;

    return 0;
}

