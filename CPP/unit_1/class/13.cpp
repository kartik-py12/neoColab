// Single File Programming Question
// Problem Statement



// A company needs a utility to calculate the total revenue from a set of sales transactions. Each transaction amount is input one by one. The system should compute the total revenue by summing up all the individual transaction amounts using the call-by-value function.



// The system should read the number of transactions from the user. Then, for each transaction, it will read the amount and keep a running total. Finally, it should output the total revenue.



// Function Specifications: int sum(int n)



// Note: This is a sample question asked in Capgemini recruitment.

// Input format :
// The first line consists of the input starting with an integer n indicating the number of transactions.

// The second line consists of the n-space-separated integers, each representing a transaction amount.

// Output format :
// The output displays a single integer representing the total revenue.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 0 ≤ amount ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 17 28 39 10 37
// Output 1 :
// 131
// Input 2 :
// 8
// 17 26 10 25 16 18 9 16
// Output 2 :
// 137

// You are using GCC
#include <iostream>
using namespace std;

// Function to calculate the total revenue
int sum(int n, int transactions[]) {
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += transactions[i];
    }
    return total;
}

int main() {
    int n;
    cin >> n; // Read number of transactions

    int transactions[n]; // Array to store transaction amounts

    // Read transaction amounts
    for (int i = 0; i < n; ++i) {
        cin >> transactions[i];
    }

    // Calculate and display the total revenue
    int totalRevenue = sum(n, transactions);
    cout << totalRevenue << endl;

    return 0;
}