// Single File Programming Question
// Problem Statement



// Ava is responsible for managing job assignments in a large company. Each job has a priority level, and Ava wants to ensure that jobs with the highest priority are handled first. To do this, she uses a Max-Heap structure where the job with the highest priority is always at the top.



// Ava will input the number of jobs and their respective priority levels, ensuring that the heap maintains its property. After all jobs are added, Ava needs to display the Max-Heap showing the order in which jobs should be processed.

// Input format :
// The first line contains an integer n, the number of jobs to be inserted into the Max-Heap.

// The second line contains n space-separated integers representing the priority levels of the jobs.

// Output format :
// The output prints the Max-Heap array after all elements have been inserted and the heap property has been maintained.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15

// 1 ≤ priority level ≤ 100

// Sample test cases :
// Input 1 :
// 4
// 10 5 15 20
// Output 1 :
// 20 15 10 5 
// Input 2 :
// 4
// 8 3 12 6
// Output 2 :
// 12 6 8 3 

// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

// Function to insert an element into the Max Heap
void insertIntoMaxHeap(vector<int>& heap, int key) {
    // Insert the element at the end of the heap
    heap.push_back(key);

    // Get the index of the newly inserted element
    int i = heap.size() - 1;

    // While the newly inserted element is not the root and is greater than its parent
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        // Swap the newly inserted element with its parent
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        // Update the index of the newly inserted element
        i = (i - 1) / 2;
    }
}

// Function to print the Max Heap
void printMaxHeap(vector<int>& heap) {
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    // Get the number of jobs
    int n;
    cin >> n;

    // Create a Max Heap
    vector<int> maxHeap;

    // Insert the jobs into the Max Heap
    for (int i = 0; i < n; i++) {
        int priority;
        cin >> priority;
        insertIntoMaxHeap(maxHeap, priority);
    }

    // Print the Max Heap
    printMaxHeap(maxHeap);

    return 0;
}
