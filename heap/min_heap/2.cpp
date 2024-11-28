// Single File Programming Question
// Problem Statement



// Liam is a data analyst at a logistics company and needs to optimize the delivery routes based on the weight of packages. To do this, he decides to use a min heap to prioritize packages by their weight, ensuring that the lightest packages are processed first. After inserting all package weights into the heap, he wants to display the heap structure and calculate the average weight of the packages.



// Write a program that constructs a min heap from an array of package weights entered by Liam, displays the resulting min-heap structure, and calculates the Average Weight = (Total Weight of Packages) / (Number of Packages) of the packages.

// Input format :
// The first line contains an integer n, representing the number of packages.

// The second line contains n space-separated integers representing the weights of the packages.

// Output format :
// The first line should contain n space-separated integers representing the min heap structure.

// The second line should display "Average: " followed by double value representing the average weight of the packages, formatted to two decimal places.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ weights ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 5 10 3 1 7
// Output 1 :
// 1 3 5 10 7 
// Average: 5.20
// Input 2 :
// 6
// 15 8 12 6 4 9
// Output 2 :
// 4 6 9 15 8 12 
// Average: 9.00
// Input 3 :
// 4
// 15 67 14 17
// Output 3 :
// 14 17 15 67 
// Average: 28.25


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

// Calculate the average of all elements in the heap
double averageOfElements(int heap[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += heap[i];
    }
    return sum / size;
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

    double average = averageOfElements(heap, size);
    cout << "Average: "<< fixed << setprecision(2)<< average;

    delete[] heap; // Free dynamically allocated memory
    return 0;
}