// Single File Programming Question
// Problem Statement



// Alex is a software engineer working on a project that involves processing user scores from an online gaming platform. He needs to create a max heap to efficiently manage these scores for ranking purposes. Additionally, Alex wants to analyze the performance of the top players by calculating the cube of their scores to get a better understanding of their performance metrics.



// Your task is to help Alex by implementing a program that builds a max heap from the input scores and prints the cubed values of these scores.

// Input format :
// The first line contains an integer N, representing the number of scores Alex will input.

// The second line consists of an N space-separated integers representing a user score.

// Output format :
// The first line displays the max heap in a single line, with scores separated by spaces.

// The second line displays the cubed values of the scores in the same order as they were input.



// Refer to the sample output for exact format specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ scores ≤ 30

// Sample test cases :
// Input 1 :
// 5
// 3 4 2 1 5
// Output 1 :
// 5 4 2 1 3 
// 125 64 8 1 27 
// Input 2 :
// 8
// 9 3 12 18 27 6 15 21
// Output 2 :
// 27 21 15 18 12 6 9 3 
// 19683 9261 3375 5832 1728 216 729 27

#include <iostream>
#include <vector>

using namespace std;

// Function to maintain the max heap property
void maxHeapify(vector<int>& heap, int i, int size) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < size && heap[left] > heap[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < size && heap[right] > heap[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(heap[i], heap[largest]); // Swap root with largest
        maxHeapify(heap, largest, size); // Recursively heapify the affected sub-tree
    }
}

// Function to build a max heap from an array
void buildMaxHeap(vector<int>& heap) {
    int size = heap.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, i, size);
    }
}

int main() {
    int n;
    cin >> n; // Read the number of elements
    vector<int> scores(n); // Create a vector to hold the scores

    // Read the scores into the vector
    for (int i = 0; i < n; i++)
        cin >> scores[i];

    // Build the max heap
    buildMaxHeap(scores);

    // Print the max heap in level order
    for (int score : scores)
        cout << score << " ";
    cout << endl;

    // Print the cubes of the original scores in the same order as input
    for (int score : scores)
        cout << score * score * score << " ";
    cout << endl;

    return 0;
}