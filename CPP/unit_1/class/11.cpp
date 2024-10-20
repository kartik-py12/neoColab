// Single File Programming Question
// Problem Statement



// Smith wants to buy a second-hand car so he wants to check for a few parameters before buying. So you have to design a class Car with private attributes brand and fuelConsumption. Implement a friend function calculateFuelCost(Car&, double , double ) that takes a car object, the distance traveled, and the fuel price per liter as parameters and calculates and returns the total fuel cost. 



// Write a program to input the brand, fuel consumption, distance traveled, and fuel price, create an object of the Car class, calculate the fuel cost using the calculateFuelCost function, and display the result.



// Note: This is a sample question asked in TCS recruitment.

// Input format :
// The first line consists of the car brand as a string.

// The second line consists of the fuel consumption in liters per 100 km as a double.

// The third line consists of the distance traveled in kilometers as a double.

// The fourth line consists of the fuel price per liter as a double.

// Output format :
// The output prints the total fuel cost as a double, rounded off to two decimal places.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The brand string will have a maximum length of 50 characters.

// 0 < fuelConsumption <= 100

// 0 < distance <= 1000.0

// 0 < fuelPrice <= 100.0

// Sample test cases :
// Input 1 :
// Toyota
// 8.5
// 200.75
// 4.25
// Output 1 :
// 72.52

#include <iostream>
#include <iomanip>
#include <string>

class Car {
private:
    std::string brand;
    double fuelConsumption; // Liters per 100 km

public:
    Car(const std::string& b = "", double f = 0.0) : brand(b), fuelConsumption(f) {}

    friend double calculateFuelCost(const Car& car, double distance, double fuelPrice);
};

double calculateFuelCost(const Car& car, double distance, double fuelPrice) {
    double fuelNeeded = (car.fuelConsumption / 100) * distance;
    return fuelNeeded * fuelPrice;
}

int main() {
    std::string brand;
    double fuelConsumption, distance, fuelPrice;

    // Input the car details
    std::getline(std::cin, brand);
    std::cin >> fuelConsumption;
    std::cin >> distance;
    std::cin >> fuelPrice;

    // Create a Car object
    Car car(brand, fuelConsumption);

    // Calculate the fuel cost
    double totalFuelCost = calculateFuelCost(car, distance, fuelPrice);

    // Output the result rounded to two decimal places
    std::cout << std::fixed << std::setprecision(2) << totalFuelCost << std::endl;

    return 0;
}