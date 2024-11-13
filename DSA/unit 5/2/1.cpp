// Single File Programming Question
// Problem Statement



// Emma is working with a collection of numbers and needs to manage them using a min-heap data structure. She wants to insert a set of numbers into the min-heap, and then she needs to delete all elements within a specified range (inclusive).



// Your task is to help Emma by implementing the necessary operations to build the min-heap, display its contents, and remove elements in the specified range.



// You need to:

// Insert numbers into the min-heap.
// Delete all elements within the specified range.
// Display the contents of the min-heap before and after deletion.
// Input format :
// The first line consists of an integer n, the number of elements in the array.

// The second line of input consists of n elements separated by spaces.

// The third line consists of the start range and end range, separated by a space.

// Output format :
// The output displays the following format:

// First, print the contents of the min-heap after all elements have been inserted.

// Second, print the contents of the min-heap after deleting the specified range of elements.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ elements ≤ 100

// 1 ≤ start ≤ end ≤ 100

// range should be given input elements.

// Sample test cases :
// Input 1 :
// 7
// 20 36 82 17 51 3 96
// 20 96
// Output 1 :
// Min-heap: 3 20 17 36 51 82 96 
// Min-heap after deletion: 3 17 
// Input 2 :
// 4
// 50 40 30 20
// 10 25
// Output 2 :
// Min-heap: 20 30 40 50 
// Min-heap after deletion: 30 50 40 

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

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
    heap[*size] = value;
    (*size)++;
    int i = *size - 1;

    // Fix the min-heap property if it is violated
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteInRange(int heap[], int *size, int low, int high) {
    for (int i = 0; i < *size; ) {
        if (heap[i] >= low && heap[i] <= high) {
            swap(&heap[i], &heap[*size - 1]);
            (*size)--;
            minHeapify(heap, *size, i);  // Re-heapify after deletion
        } else {
            i++;
        }
    }
}

void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
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

    buildMinHeap(heap, size);

    printf("Min-heap: ");
    displayMinHeap(heap, size);

    int low, high;
    scanf("%d %d", &low, &high);

    deleteInRange(heap, &size, low, high);

    printf("Min-heap after deletion: ");
    displayMinHeap(heap, size);

    return 0;
}