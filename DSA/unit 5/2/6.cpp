// Single File Programming Question
// Problem Statement



// Emma is a data analyst who frequently collects numerical data for various projects. She often needs to sort this data to identify the smallest and largest values quickly.



// To streamline her workflow, she wants a program that can take a list of numbers, sort them using the heap sort algorithm, and then display the sorted list along with the smallest and largest numbers.



// Write a program that helps Emma by accepting a list of integers, sorting them in ascending order, and identifying the smallest and largest numbers in the list.

// Input format :
// The first line contains an integer n, representing the number of integers in the list.

// The second line contains n space-separated integers numbers, representing the numerical data.

// Output format :
// The output displays the following format:

// Print the sorted integers in ascending order, each separated by a space.
// Print the smallest number in the format: Smallest Number: X, where X is the smallest number.
// Print the largest number in the format: Largest Number: Y, where Y is the largest number.


// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 2 ≤ n ≤ 10

// 1 ≤ numerical data ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 89 25 30 16 38
// Output 1 :
// 16 25 30 38 89 
// Smallest Number: 16
// Largest Number: 89
// Input 2 :
// 10
// 36 23 18 29 21 73 19 28 31 11
// Output 2 :
// 11 18 19 21 23 28 29 31 36 73 
// Smallest Number: 11
// Largest Number: 73

#include <stdio.h>
#include <stdlib.h>


void swap(int* a, int* b) {
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

int findSmallest(int arr[], int size) {
    return arr[0]; // After sorting, the smallest number is at index 0
}

int findLargest(int arr[], int size) {
    return arr[size - 1]; // After sorting, the largest number is at the last index
}

int main() {
    int size;
    scanf("%d", &size);
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Smallest Number: %d\n", findSmallest(arr, size));
    printf("Largest Number: %d", findLargest(arr, size));
    free(arr);
    return 0;
}