// Single File Programming Question
// Problem Statement



// David, a data center manager, is tasked with efficiently assigning tasks to servers based on their processing times. To achieve this, he decides to use a Min-Heap to prioritize the servers with the lowest processing times. David inputs the number of servers and their respective processing times, ensuring that the heap maintains its property where the smallest element is always at the top.



// After all servers are added, David needs to display the Min-Heap, showing the order in which tasks should be assigned for optimal efficiency.

// Input format :
// The first line contains an integer n, the number of servers in the heap.

// The second line contains n space-separated integers representing the servers' processing times.

// Output format :
// The output prints the Min-Heap array after all elements have been inserted and the heap property has been maintained.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15

// 1 ≤ processing time ≤ 100

// Sample test cases :
// Input 1 :
// 9
// 5 3 8 2 9 1 7 6 4
// Output 1 :
// 1 3 2 4 9 8 7 6 5 
// Input 2 :
// 5
// 10 20 30 40 50
// Output 2 :
// 10 20 30 40 50 


#include <iostream>
#include <iomanip>

using namespace std;



// Swap function for swapping elements
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// MinHeapify function to maintain heap property
void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

// Build the Min Heap by calling minHeapify from the last non-leaf node to the root
void buildMinHeap(int heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

// Insert an element into the heap
void insertElement(int heap[], int &size, int value) {
    if (size < 100) { // Optional: limit size to 100 for example
        heap[size] = value;
        int i = size;
        size++;

        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
}

// Display the heap elements
void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;

    int *heap = new int[n]; // Dynamic memory allocation for heap
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value);
    }
    
    buildMinHeap(heap, size);
    displayMinHeap(heap, size);

    // double average = averageOfElements(heap, size);
    // cout << "Average: "<< fixed << setprecision(2)<< average;

    delete[] heap; // Free dynamically allocated memory
    return 0;
}
