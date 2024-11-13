// Single File Programming Question
// Problem Statement



// Tao is a warehouse manager responsible for maintaining the inventory of products. Each product has a unique code that represents its value. To better manage the warehouse operations, Tao needs to sort the product codes in ascending order to simplify product retrieval and restocking processes.



// Write a program that takes a list of product codes as input and sorts them using the heap sort algorithm.

// Input format :
// The first line contains an integer n, representing the number of product codes.

// The second line contains n space-separated integers code, representing the product codes in the warehouse.

// Output format :
// The output displays the sorted product codes in ascending order, each separated by a space.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 2 ≤ n ≤ 10

// 1 ≤ code ≤ 1000

// Sample test cases :
// Input 1 :
// 10
// -3 4 -9 2 5 12 13 15 6 -11
// Output 1 :
// -11 -9 -3 2 4 5 6 12 13 15 
// Input 2 :
// 5
// 6 7 -9 2 3
// Output 2 :
// -9 2 3 6 7 

#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int root) {
    int largest = root; // Initialize largest as root
    int left = 2 * root + 1; // left child index
    int right = 2 * root + 2; // right child index

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        // Recursively heapify the affected subtree
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    // Build heap (rearranging array)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Move current root to end
        heapify(arr, i, 0); // call max heapify on the reduced heap
    }
}

int main() {
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}