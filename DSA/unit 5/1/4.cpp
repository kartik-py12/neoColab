// Single File Programming Question
// Problem Statement



// Sarah is a financial analyst who is developing a budgeting application for individuals looking to save money. The app allows users to input their savings goals, but Sarah wants to ensure that only certain amounts (specifically, those that are multiples of five) are considered valid savings entries.



// She needs a program that stores valid savings amounts in a min-heap structure, allowing her to efficiently retrieve the lowest savings goal. Your task is to help Sarah implement this functionality.

// Input format :
// The first line contains an integer n, representing the number of savings goals a user wishes to enter.

// The second line consists of n space-separated integers representing a savings goal.

// Output format :
// If an entered amount is not a multiple of five, display a message indicating that the value is not valid.

// After processing all inputs, display the min-heap of valid savings goals in a single line, with amounts separated by spaces.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ saving goal ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 15 10 20 5 30
// Output 1 :
// 5 10 20 15 30 
// Input 2 :
// 6
// 50 20 70 15 30 34
// Output 2 :
// 34 is not a multiple of five
// 15 20 70 50 30 
// Input 3 :
// 7
// 1 2 3 4 5 6 10
// Output 3 :
// 1 is not a multiple of five
// 2 is not a multiple of five
// 3 is not a multiple of five
// 4 is not a multiple of five
// 6 is not a multiple of five
// 5 10 

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;  // left child index
    int right = 2 * i + 2; // right child index

    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void buildMinHeap(int heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

void insertElement(int heap[], int *size, int value) {
    heap[*size] = value; // Insert the new value at the end
    (*size)++;          // Increase the size

    // Bubble up the new value to maintain the min-heap property
    int i = *size - 1; // Index of the newly inserted element
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", heap[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int *heap = (int *)malloc(n * sizeof(int));
    int size = 0;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        if (value % 5 == 0) {
            insertElement(heap, &size, value);
        } else {
            printf("%d is not a multiple of five\n", value);
        }
    }
    buildMinHeap(heap, size);
    displayMinHeap(heap, size);
    free(heap); 
    return 0;
}