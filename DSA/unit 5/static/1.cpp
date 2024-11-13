// Single File Programming Question
// Problem Statement



// Emma is a mathematics enthusiast who wants to analyze prime numbers for her research. She collects several integers and aims to create a max heap that only includes the prime numbers from her collection.



// After inserting the prime numbers into the max heap, she wants to visualize the max heap structure to understand the hierarchy of these numbers.



// Note

// A prime number is a natural number greater than one that has no positive divisors other than one and itself.

// Input format :
// The first line contains an integer n, representing the number of integers Emma collected.

// The second line consists of n space-separated integers, which are the values Emma wants to analyze.

// Output format :
// The output consists of two parts:

// If any prime numbers were inserted into the max heap, display them as integers separated by a space.
// If a number is not prime, print a message in the format: "<value> is not a prime number".


// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ values ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 3 2 4 5
// Output 1 :
// 1 is not a prime number
// 4 is not a prime number
// Max Heap: 5 2 3 
// Input 2 :
// 6
// 17 7 5 11 13 19
// Output 2 :
// Max Heap: 19 13 17 7 11 5

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to display the max heap
void displayMaxHeap(vector<int>& heap) {
    cout << "Max Heap: ";
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> heap;  // To store prime numbers

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        if (isPrime(value)) {
            heap.push_back(value);  // Insert into the heap
            push_heap(heap.begin(), heap.end());  // Maintain max heap property
        } else {
            cout << value << " is not a prime number" << endl;
        }
    }

    // Display the heap if it has any elements
    if (!heap.empty()) {
        displayMaxHeap(heap);
    }

    return 0;
}