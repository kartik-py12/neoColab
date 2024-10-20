// Single File Programming Question
// Problem Statement



// Raj oversees parcel IDs in his logistics company and needs to identify prime numbers within a given range for special processing. 



// He wants to create a program that reads the start and end values of this range and uses reference variables to determine and display all prime parcel IDs in ascending order.



// Function Name: void generatePrimesInRange



// Note: This is a sample question asked in TCS recruitment.

// Input format :
// The input consists of two integers start and end, representing the starting and ending parcel ID, respectively separated by space.

// Output format :
// The output displays a single line containing all prime parcel IDs within the specified range, separated by spaces.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 0 ≤ start and end ≤ 100

// Sample test cases :
// Input 1 :
// 0 10
// Output 1 :
// 2 3 5 7 

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int start, end;
    cin >> start >> end;

    for (int num = start; num <= end; ++num) {
        if (isPrime(num)) {
            cout << num << " ";
        }
    }

    cout << endl;
    return 0;
}