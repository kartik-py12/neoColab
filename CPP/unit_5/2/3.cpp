// Single File Programming Question
// Problem statement



// David is tasked with creating a versatile calculator program that can perform various mathematical operations based on user inputs. The calculator should be able to handle three types of operations: square of a number, modulus between two integers, and quotient between two double-point numbers. Write a program to accomplish this task.



// Function Prototype

// int calc(int a)

// int calc(int a, int b)

// double calc(double a, double b)

// Input format :
// The input consists of 2 space-separated integers and 2 space-separated double values.



// Note: The first input for the Square function, the first two inputs for the modulus function, and the last two inputs for the division function.

// Output format :
// The output prints the following three lines:

// "Square of x: <result>" - The square of x.

// "Modulus of x, y: <result>" - The result of x % y.

// "Quotient of n1, n2: <result>" - The result of n1 / n2, rounded to two decimal places.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 0.0 ≤ double values ≤ 1000.0

// 0 ≤ integer values ≤ 1000

// Sample test cases :
// Input 1 :
// 2 5 6.3 5.2
// Output 1 :
// Square of 2: 4
// Modulus of 2, 5: 2
// Quotient of 6.3, 5.2: 1.21
// Input 2 :
// 8 6 5.8 2.3
// Output 2 :
// Square of 8: 64
// Modulus of 8, 6: 2
// Quotient of 5.8, 2.3: 2.52


#include <iostream>
using namespace std;

int calc(int a) {
    return a * a;
}

int calc(int a, int b) {
    return a % b;
}

double calc(double a, double b) {
    return (int)(a / b * 100 + 0.5) / 100.0;
}

int main() {
    int a, b;
    double n1, n2;
    cin >> a >> b >> n1 >> n2;
    cout << "Square of " << a << ": " << calc(a) << endl;
    cout << "Modulus of " << a << ", " << b << ": " << calc(a, b) << endl;
    cout << "Quotient of " << n1 << ", " << n2 << ": " << calc(n1, n2) << endl;
    return 0;
}
