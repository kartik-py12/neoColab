// Single File Programming Question
// Function Overloading:



// An ice cream vendor sells his ice cream in cone-shaped (radius r and height h) and square-shaped (side r) containers. However, he is unsure of the quantity that can be filled in the two containers.



// You are required to write a program that prints the volume of the containers, given their respective dimensions as input. Your class must be named "Icecream," which has two methods with the same name, "Quantity," each having the respective dimensions of the containers as the parameters. 



// Function Prototype:

// Quantity(int r, int h)

// Quantity(int r)



// Formulas:

// A cone's volume is equal to 0.33*pi*r*r*h.

// The volume of a square is r*r*r.



// Note: Use M_PI for pi

// Input format :
// The first line of the input consists of the choice (1 for square, 2 for cone).

// If the choice is 1, enter the side of the square.

// If the choice is 2, enter the radius and height of the cone, separated by a space.



// Note: The input type should be an integer.

// Output format :
// The output must display the volume of the container, rounded off to two decimal places, for which the dimensions are given.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The integer "n" will be either 1 or 2.

// 1 ≤ r, h ≤ 10 (radius and height of the ice cream).

// The output will have a precision of 2 decimal places.

// Sample test cases :
// Input 1 :
// 1
// 4
// Output 1 :
// 64.00
// Input 2 :
// 2
// 4 5
// Output 2 :
// 82.94

// You are using GCC
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Icecream {
public:
    double Quantity(int r, int h) {
        double volume = (0.33 * M_PI * r * r * h);
        return volume;
    }

    double Quantity(int r) {
        double volume = (r * r * r);
        return volume;
    }
};

int main() {
    int choice, r, h;
    double volume;
    Icecream icecream;

    cin >> choice;

    switch (choice) {
        case 1:
            cin >> r;
            volume = icecream.Quantity(r);
            break;
        case 2:
            cin >> r >> h;
            volume = icecream.Quantity(r, h);
            break;
        default:
            cout << "Invalid choice" << endl;
            return 0;
    }

    cout << fixed << setprecision(2) << volume << endl;

    return 0;
}

