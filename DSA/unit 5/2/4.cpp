// Single File Programming Question
// Problem Statement



// Diego is managing a data structure that represents a priority queue, implemented as a Max Heap. He wants to insert elements into this Max Heap and delete the largest odd number from it. Help Diego build the Max Heap, insert elements, and then delete the largest odd number if it exists. After deletion, he wants to print the updated Max Heap.



// Your task is to:

// Insert numbers into a Max Heap.
// Print the Max Heap.
// Find and delete the largest odd number from the Max Heap.
// Print the Max Heap again after the deletion.
// Input format :
// The first line contains an integer n, the number of elements Diego will insert into the heap.

// The second line consists of n space-separated integers, representing an element of the heap.

// Output format :
// The output displays the following format:

// First, print "Max Heap before deletion: " followed by the elements of the Max Heap on the same line.



// If an odd number is deleted, print "Deleted largest odd number: " followed by the value of the deleted odd number.

// If no odd number is found, print "No odd number found in the heap".



// Finally, print "Max Heap after deletion: " followed by the elements of the Max Heap on the same line.



// Refer to the sample output for the exact format.

// Code constraints :
// the test cases will fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ values ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 4 3 2 5 6
// Output 1 :
// Max Heap before deletion: 6 5 2 3 4 
// Deleted largest odd number: 5
// Max Heap after deletion: 6 4 2 3 
// Input 2 :
// 3
// 4 2 8
// Output 2 :
// Max Heap before deletion: 8 2 4 
// No odd number found in the heap
// Max Heap after deletion: 8 2 4 

#include <stdio.h>
#include <limits.h>


void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr, i, largest);
        // Recursively heapify the affected subtree
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    // Build max heap by calling maxHeapify on each non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void insertIntoMaxHeap(int arr[], int *n, int value) {
    arr[*n] = value; // Insert the new value at the end
    (*n)++; // Increase the size of the heap

    // Fix the max heap property if it is violated
    int i = *n - 1; // Index of the newly inserted element
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void printMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int deleteLargestOdd(int arr[], int *n) {
    int largestOddIndex = -1;
    int largestOddValue = -1;

    // Find the largest odd number
    for (int i = 0; i < *n; i++) {
        if (arr[i] % 2 != 0) { // Check if the number is odd
            if (largestOddIndex == -1 || arr[i] > largestOddValue) {
                largestOddValue = arr[i];
                largestOddIndex = i;
            }
        }
    }

    // If no odd number found, print the message and return -1
    if (largestOddIndex == -1) {
        printf("No odd number found in the heap\n");
        return -1;
    }

    // Swap the largest odd number with the last element
    swap(arr, largestOddIndex, *n - 1);
    (*n)--; // Reduce the size of the heap

    // Heapify the affected part
    maxHeapify(arr, *n, largestOddIndex);

    return largestOddValue; // Return the deleted odd number}
}

int main() {
    int arr[100];
    int n = 0;
    int num_elements;

    scanf("%d", &num_elements);

    for (int i = 0; i < num_elements; i++) {
        int value;
        scanf("%d", &value);
        insertIntoMaxHeap(arr, &n, value);
    }

    buildMaxHeap(arr, n);
    printf("Max Heap before deletion: ");
    printMaxHeap(arr, n);

    int deletedValue = deleteLargestOdd(arr, &n);
    if (deletedValue != -1) {
        printf("Deleted largest odd number: %d\n", deletedValue);
    }

    printf("Max Heap after deletion: ");
    printMaxHeap(arr, n);

    return 0;
}