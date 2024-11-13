// Single File Programming Question
// Problem Statement



// Mithu is given an array of integers and a threshold value. He wants to create a max-heap from the given array and then remove all elements from the heap that are greater than the given threshold. After performing these operations, Mithu wants to display the remaining elements in the max-heap.



// Write a program to help Mithu accomplish this task.

// Input format :
// The first line of input consists of an integer n, the number of elements in the array.

// The second line of input consists of n elements separated by spaces.

// The third line of input consists of an integer threshold.

// Output format :
// The output displays the elements of the max-heap after removing all elements greater than the threshold. Separate the elements by spaces.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ elements ≤ 200

// 1 ≤ threshold ≤ 200

// Sample test cases :
// Input 1 :
// 10
// 18 17 16 15 65 13 56 11 40 39
// 39
// Output 1 :
// 39 18 17 11 15 13 16 
// Input 2 :
// 5
// 10 20 30 40 50
// 21
// Output 2 :
// 20 10 

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

void deleteGreaterThanThreshold(int arr[], int *n, int threshold) {
    for (int i = 0; i < *n; ) {
        if (arr[i] > threshold) {
            // Swap the element with the last element
            swap(arr, i, *n - 1);
            (*n)--; // Reduce the size of the heap
            // Heapify the affected part
            maxHeapify(arr, *n, i);
        } else {
            i++;
        }
    }
}

void printMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int n;
    int threshold;

    // Input number of elements
    scanf("%d", &n);

    // Input elements into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the threshold value
    scanf("%d", &threshold);

    // Build the max heap
    buildMaxHeap(arr, n);

    // Delete all elements greater than the threshold
    deleteGreaterThanThreshold(arr, &n, threshold);

    // Print the remaining heap elements
    printMaxHeap(arr, n);

    return 0;
}