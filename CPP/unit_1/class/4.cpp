// Single File Programming Question
// Problem Statement



// A weather forecasting application needs a program that can convert temperature values between Celsius, Fahrenheit, and Kelvin. The program should allow the user to input a temperature in Celsius and display its equivalent values in Fahrenheit and Kelvin.



// You are tasked with creating a temperature conversion program using a class called TemperatureConverter. The program should allow users to input a temperature in Celsius and display its equivalent values in Fahrenheit and Kelvin. Use a non-inline member function to calculate the converted temperatures.



// Formulas:

// Celsius to Fahrenheit	= 9/5 (Celcius) + 32
// Celsius to Kelvin	K = Celcius + 273.15


// Company Tags: Cocubes 

// Input format :
// The input consists of a single line containing a double value representing the temperature in Celsius.

// Output format :
// The first line of the output displays the temperature in Fahrenheit, as a double value rounded to two decimal places.

// The second line of the output displays the temperature in Kelvin, as a double value rounded to two decimal places.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The temperature range is not limited.

// The program should handle positive and negative temperature values.

// Sample test cases :
// Input 1 :
// 25.5
// Output 1 :
// Temperature in Fahrenheit: 77.90
// Temperature in Kelvin: 298.65
// Input 2 :
// 0
// Output 2 :
// Temperature in Fahrenheit: 32.00
// Temperature in Kelvin: 273.15
// Input 3 :
// -22
// Output 3 :
// Temperature in Fahrenheit: -7.60
// Temperature in Kelvin: 251.15


// You are using GCC
#include <iostream>
#include <iomanip>
using namespace std;

class TemperatureConverter{
public:
    float cel;
    float kel;
    float fah;
    
    void tokelvin(){
        kel=cel+273.15;
    }
    
    void tofah(){
        fah=(9.0/5.0)*cel+32;
    }
};

int main(){
    float temp;
    cin>>temp;
    TemperatureConverter convert;
    convert.cel=temp;
    convert.tokelvin();
    convert.tofah();
    cout<<"Temperature in Fahrenheit: "<<fixed<<setprecision(2)<<convert.fah<<endl;
    cout<<"Temperature in Kelvin: "<<convert.kel<<endl;
}