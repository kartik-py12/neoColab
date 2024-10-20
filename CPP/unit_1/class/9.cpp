// Single File Programming Question
// Problem Statement



// You are developing a bank application. Implement overloaded functions called "calculateInterest" that can calculate the interest for different types of accounts, such as savings accounts and fixed deposit accounts.



// Each overloaded function should take the principal amount, interest rate, and time period as input and display the interest for both types of accounts, formatted to two decimal places.



// Example



// Input:

// 1200.0

// 3.8

// 2



// Output:

// 45.60

// 91.20



// Explanation:

// ﻿For a savings account:

// The formula to calculate the interest for a savings account is interest = principal_amount * interest_rate / 100.

// So, the interest for the savings account is 1200 * 3.8 / 100 = 45.60.



// For a fixed deposit account:

// The formula to calculate the interest for a fixed deposit account is interest = principal_amount * interest_rate / 100 * time_period.

// So, the interest for the fixed deposit account is 1200 * 3.8 / 100 * 2 = 91.20.



// Note: This is a sample question asked in Mettl recruitment.

// Input format :
// The first line consists of a double value representing the principal amount.

// The second line consists of a double value representing the interest rate.

// The third line consists of an integer representing the time period (in years).

// Output format :
// The first line of output displays the calculated interest for the savings account rounded off to two decimal places.

// The second line of output displays the calculated interest for the fixed deposit account rounded off to two decimal places.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 500 ≤ Principal amount ≤ 100000

// 0 < Interest rate < 15

// 0 < Years < 10

// Sample test cases :
// Input 1 :
// 1200.0
// 3.8
// 2
// Output 1 :
// 45.60
// 91.20
// Input 2 :
// 3243.87
// 1.2
// 3
// Output 2 :
// 38.93
// 116.78

#include <iostream>
#include <iomanip>  // For std::fixed and std::setprecision

using namespace std;

// Function to calculate interest for a savings account
double calculateInterest(double principal, double rate) {
    return principal * rate / 100;
}

// Overloaded function to calculate interest for a fixed deposit account
double calculateInterest(double principal, double rate, int time) {
    return principal * rate / 100 * time;
}

int main() {
    double principal, rate;
    int time;
    
    // Read input values
    cin >> principal;
    cin >> rate;
    cin >> time;
    
    // Calculate and print interest for savings account
    double savingsInterest = calculateInterest(principal, rate);
    double fixedDepositInterest = calculateInterest(principal, rate, time);
    
    // Print results formatted to two decimal places
    cout << fixed << setprecision(2);
    cout << savingsInterest << endl;
    cout << fixedDepositInterest << endl;

    return 0;
}
