// Single File Programming Question
// Problem Statement



// Let's imagine you are working on a program that involves complex numbers. You have been assigned the task of creating a ComplexNumber class to handle complex number operations. The ComplexNumber class has member variables: real and imaginary, representing the real and imaginary parts of a complex number.



// To enhance the functionality of the ComplexNumber class, you need to implement a friend function named multiply(). This function takes two ComplexNumber objects as arguments and returns their multiplication result.



// Now, let's consider a scenario where you are designing a scientific calculator application. You want to provide complex number multiplication functionality to the calculator's users. Your task is to implement the ComplexNumber class and the multiply() function, allowing users to multiply two complex numbers.



// Note: This is a sample question asked in Infosys recruitment.

// Input format :
// The first line consists of two space-separated double values, representing the real and imaginary parts of the first complex number.

// The second line consists of two space-separated double values, representing the real and imaginary parts of the second complex number.

// Output format :
// The output displays the result of the multiplication in the format "a + bi", where a is the real part and b is the imaginary part.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// Real and imaginary parts of the complex numbers are of double datatype.

// -400.0 ≤ input values ≤ 400.0

// Sample test cases :
// Input 1 :
// 2.0 2.0
// 1.2 2.2
// Output 1 :
// -2 + 6.8i
// Input 2 :
// 1.5 9.0
// 3.6 -0.9
// Output 2 :
// 13.5 + 31.05i

#include <stdio.h>

typedef struct ComplexNumber {
    double real;
    double imaginary;
} ComplexNumber;

ComplexNumber multiply(ComplexNumber a, ComplexNumber b) {
    ComplexNumber result;
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return result;
}
class ComplexNumber1{
    int friend1;
    int multiply;
};

int main() {
    ComplexNumber a, b, result;
    scanf("%lf %lf", &a.real, &a.imaginary);
    scanf("%lf %lf", &b.real, &b.imaginary);
    result = multiply(a, b);
    printf("%g + %gi\n", result.real, result.imaginary);
    return 0;
}
