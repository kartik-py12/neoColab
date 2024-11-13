// Single File Programming Question
// Problem Statement



// Alice is a teacher who wants to analyze the performance of her students in an exam. She has collected their scores and now wants to sort these scores in ascending order to identify how many students have scored more than a certain threshold.



// Write a program that helps Alice sort the scores and count how many students have scored more than a given number using the heap sort algorithm.

// Input format :
// The first input is an integer n representing the number of students.

// The second line consists of n space-separated integers, representing the scores of the students.

// The last input is an integer T, representing the threshold score.

// Output format :
// The first line displays integers, representing the sorted scores in descending order, separated by a space.

// The second line displays an integer, representing the count of scores that are greater than the given number.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 2 ≤ n ≤ 10

// 2 ≤ Scores ≤ 100

// 1 ≤ T ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 3 1 4 6 5
// 2
// Output 1 :
// 1 3 4 5 6 
// 4
// Input 2 :
// 6
// 9 8 7 6 5 4
// 5
// Output 2 :
// 4 5 6 7 8 9 
// 4

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

int countGreaterThan(int arr[], int size, int number) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > number) {
            count++;
        }
    }
    return count;
}

int main() {
    int size;
    scanf("%d", &size);
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, size);
    int number;
    scanf("%d", &number);
    int greaterCount = countGreaterThan(arr, size, number);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("%d", greaterCount);
    free(arr);
    return 0;
}