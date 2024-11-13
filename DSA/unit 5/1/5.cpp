// Single File Programming Question
// Problem Statement



// John is organizing a programming competition where participants need to input numbers into a system that automatically arranges them in a max heap. Additionally, John wants to keep track of how many of the entered numbers are even and how many are odd. After processing all the inputs, the system should display the numbers in max heap order, along with the count of even and odd numbers.



// Help John implement this system by writing a program that builds a max heap and tracks the number of even and odd numbers.

// Input format :
// The first line contains an integer n, representing the number of elements John will input.

// The second line contains n space-separated integers, representing the values John enters.

// Output format :
// The first line displays the max heap in a single line, with elements separated by spaces.

// The second line displays the count of even elements in the heap.

// The third line displays the count of odd elements in the heap.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ values ≤ 1000

// Sample test cases :
// Input 1 :
// 6
// 75 24 63 56 19 53
// Output 1 :
// Max Heap: 75 56 63 24 19 53 
// Even elements count: 2
// Odd elements count: 4
// Input 2 :
// 5
// 85 60 20 56 70
// Output 2 :
// Max Heap: 85 70 20 56 60 
// Even elements count: 4
// Odd elements count: 1

#include <stdio.h>


#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void maxHeapify(int heap[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, size, largest);
    }
}

void buildMaxHeap(int heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, size, i);
    }
}

void insertIntoMaxHeap(int heap[], int *size, int value, int *evenCount, int *oddCount) {
    heap[*size] = value; // Insert the new value at the end
    (*size)++; // Increase the size of the heap

    // Count even and odd
    if (value % 2 == 0) {
        (*evenCount)++;
    } else {
        (*oddCount)++;
    }

    // Maintain the max heap property
    int i = *size - 1;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printMaxHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", heap[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int arr[100];
    int n = 0;
    int num_elements;
    int evenCount = 0, oddCount = 0; 
    scanf("%d", &num_elements);
    for (int i = 0; i < num_elements; i++) {
        int value;
        scanf("%d", &value);
        insertIntoMaxHeap(arr, &n, value, &evenCount, &oddCount);
    }
    buildMaxHeap(arr, n);
    printf("Max Heap: ");
    printMaxHeap(arr, n);
    printf("\nEven elements count: %d\n", evenCount);
    printf("Odd elements count: %d", oddCount);
    return 0;
}