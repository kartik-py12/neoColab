// Single File Programming Question
// Problem Statement



// Liam is a data analyst who is working on optimizing a list of numbers for further analysis. He decides to create a min heap from the integers he collects, as it allows him to efficiently retrieve the smallest number at any time.



// After inserting the numbers into the min heap, he wants to visualize its structure and also find the maximum value among the elements.

// Input format :
// The first line contains an integer n, representing the number of integers Liam collected.

// The second line consists of n space-separated integers, which are the values Liam wants to insert into the min heap.

// Output format :
// The output consists of two parts:

// Display the elements of the min heap as integers separated by a space.
// Display the maximum value among the elements in the min heap in the format: "Maximum: <value>".


// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ values ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 3 9 2 6 8
// Output 1 :
// 2 6 3 9 8 
// Maximum: 9
// Input 2 :
// 8
// 25 15 17 32 23 5 12 8
// Output 2 :
// 5 8 12 23 25 17 15 32 
// Maximum: 32

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(int heap[], int size, int i) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

    // If left child is smaller than root
    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]); // Swap root with smallest
        minHeapify(heap, size, smallest); // Recursively heapify the affected subtree
    }
}

void buildMinHeap(int heap[], int size) {
    // Build a min heap from the array
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

void insertElement(int heap[], int *size, int value) {
    // Insert a new value into the min heap
    heap[*size] = value; // Add the new value at the end
    (*size)++; // Increase the size of the heap
    buildMinHeap(heap, *size); // Rebuild the heap to maintain the min heap property
}

void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int findMaxValue(int heap[], int size) {
    int maxValue = heap[0]; // Assume the first element is the maximum
    for (int i = 1; i < size; i++) {
        if (heap[i] > maxValue) {
            maxValue = heap[i]; // Update maxValue if a larger value is found
        }
    }
    return maxValue;
}

int main() {
    int n;
    scanf("%d", &n);

    int heap[n];
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertElement(heap, &size, value);
    }

    displayMinHeap(heap, size);

    int maxValue = findMaxValue(heap, size);
    printf("Maximum: %d\n", maxValue);

    return 0;
}