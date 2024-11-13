// Single File Programming Question
// Problem Statement



// Ram is working with a Max Heap to manage a set of numbers. He needs your help to build the heap, delete the root element, and calculate the sum of all remaining leaf nodes in the heap after the deletion. Your task is to:



// Insert numbers into a Max Heap.
// Print the Max Heap before and after deleting the root.
// Calculate and print the sum of all the leaf nodes in the heap after the root deletion.


// Help Ram perform these operations efficiently.

// Input format :
// The first line contains an integer n, representing the number of elements Ram will insert into the heap.

// The second line consists of n space-separated integers, representing the elements to be inserted into the heap.

// Output format :
// The output displays the following format:

// First, print the Max Heap before the root deletion on one line.

// Next, print the Max Heap after the root deletion on one line.

// Finally, print the sum of all leaf nodes in the format: "Sum of leaf nodes: X", where X is the computed sum.



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
// 6 5 2 3 4 
// 5 4 2 3 
// Sum of leaf nodes: 5
// Input 2 :
// 6
// 4 5 6 3 2 1
// Output 2 :
// 6 4 5 3 2 1 
// 5 4 1 3 2 
// Sum of leaf nodes: 6

#include <stdio.h>

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

void deleteRoot(int arr[], int *n) {
    if (*n <= 0) return; // If the heap is empty, do nothing

    // Replace the root with the last element
    arr[0] = arr[*n - 1];
    (*n)--; // Decrease the size of the heap

    // Heapify the root element to maintain the max heap property
    maxHeapify(arr, *n, 0);
}

int sumOfLeafNodes(int arr[], int n) {
    int sum = 0;
    // Leaf nodes are in the range from n/2 to n-1
    for (int i = n / 2; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void printMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    printMaxHeap(arr, n);

    deleteRoot(arr, &n);

    printMaxHeap(arr, n);

    int leafSum = sumOfLeafNodes(arr, n);
    printf("Sum of leaf nodes: %d", leafSum);

    return 0;
}