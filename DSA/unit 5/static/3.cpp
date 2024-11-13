// Single File Programming Question
// Problem Statement



// Tao is developing a program to manage a min-heap data structure for a small application. The program should enable Tao to insert elements, remove the root node, find the maximum value in the heap, and calculate the sum and average of all nodes in the heap.



// The program must ensure that the min-heap property is maintained throughout these operations.

// Input format :
// The first line contains an integer n, representing the number of elements to be inserted into the min-heap.

// The second line consists of n space-separated integers, representing which are the values to be inserted into the heap.

// Output format :
// The output displays the following format:

// Print the elements of the min-heap in order, separated by spaces, on a single line.
// Print the value of the root node after removing it.
// Print the maximum value present in the heap after the removal operation.
// Print the sum of all remaining nodes in the heap.
// Print the average of all remaining nodes in the heap, rounded to two decimal places.


// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ values ≤ 10

// Sample test cases :
// Input 1 :
// 5
// 6 4 3 7 8
// Output 1 :
// Min Heap: 3 6 4 7 8 
// Root node: 3
// Maximum value: 8
// Sum of nodes: 25
// Average of nodes: 6.25
// Input 2 :
// 5
// 3 9 2 6 8
// Output 2 :
// Min Heap: 2 6 3 9 8 
// Root node: 2
// Maximum value: 9
// Sum of nodes: 26
// Average of nodes: 6.50

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <climits>
#include <algorithm> // Include this header for max_element
using namespace std;

// Function to print elements of the min-heap without altering its structure
void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> heap;

    // Insert elements while maintaining the heap property
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        heap.push_back(value);

        // Rebuild heap to maintain the min-heap property
        push_heap(heap.begin(), heap.end(), greater<int>());
    }

    // Print the elements of the min-heap
    cout << "Min Heap: ";
    printHeap(heap);

    // Remove the root node
    pop_heap(heap.begin(), heap.end(), greater<int>());
    int rootNode = heap.back();
    heap.pop_back();
    cout << "Root node: " << rootNode << endl;

    // Find the maximum value in the remaining heap
    int maxValue = *max_element(heap.begin(), heap.end());
    cout << "Maximum value: " << maxValue << endl;

    // Calculate the sum and average of remaining nodes
    int sum = 0;
    for (int val : heap) {
        sum += val;
    }
    double average = (double)sum / heap.size();
    cout << "Sum of nodes: " << sum << endl;
    cout << "Average of nodes: " << fixed << setprecision(2) << average << endl;

    return 0;
}