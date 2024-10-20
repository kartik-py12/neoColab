// Problem Statement



// Implement a program that demonstrates the use of a reference parameter in a function. The function should compute the cube of an integer passed by reference. Read an integer from the standard input and print the cubed value using standard output functions.



// Function specification: int cube(int& n)



// Note: This is a sample question asked in a TCS interview.

// Input format :
// The input consists of an integer n.

// Output format :
// The output prints the cube of the given number.

// Code constraints :
// 1 ≤ n ≤ 100

// Sample test cases :
// Input 1 :
// 5
// Output 1 :
// 125
// Input 2 :
// 9
// Output 2 :
// 729

// You are using GCC
#include <iostream>
using namespace std;

// Function to compute the cube of an integer by reference
void cube(int& n) {
    n = n * n * n; // Compute the cube
}

int main() {
    int n;
    cin >> n; // Read the integer from standard input

    cube(n); // Call the function that computes the cube

    cout << n << endl; // Print the cubed value

    return 0;
}