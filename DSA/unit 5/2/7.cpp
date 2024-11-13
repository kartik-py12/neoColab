// Single File Programming Question
// Problem Statement



// David is a data analyst who often needs to analyze numbers by extracting their digits and sorting them in descending order. This will help him visualize the frequency of each digit and understand patterns within large numerical datasets.



// Write a program that takes a number as input, extracts its digits, sorts them, and displays the sorted digits as a single number using the heap sort algorithm.

// Input format :
// The input consists of an integer n, representing a single number.

// Output format :
// The output displays the digits of the number sorted in descending order as a single integer without any spaces.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 2 ≤ n ≤ 109

// Sample test cases :
// Input 1 :
// 123
// Output 1 :
// 321
// Input 2 :
// 31524
// Output 2 :
// 54321
// Input 3 :
// 1001
// Output 3 :
// 1100

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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

void extractDigits(int num, int** digits, int* digitCount) {
    *digitCount = 0;
    int temp = num;

    // Count the number of digits
    while (temp > 0) {
        temp /= 10;
        (*digitCount)++;
    }

    // Allocate memory for the digits
    *digits = (int*)malloc(*digitCount * sizeof(int));

    // Extract digits
    temp = num;
    for (int i = 0; i < *digitCount; i++) {
        (*digits)[i] = temp % 10; // Get the last digit
        temp /= 10; // Remove the last digit
    }
}

void printSortedDigits(int digits[], int digitCount) {
    // Print digits in reverse order since we extracted them from least significant to most
    for (int i = digitCount - 1; i >= 0; i--) {
        printf("%d", digits[i]);
    }
    printf("\n");
}

int main() {
    int num;
    scanf("%d", &num);
    int* digits = NULL;
    int digitCount = 0;
    extractDigits(num, &digits, &digitCount);
    heapSort(digits, digitCount);
    printSortedDigits(digits, digitCount);
    free(digits); 
    return 0;
}