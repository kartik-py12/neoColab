// Single File Programming Question
// Problem Statement



// Tao is a data analyst who has recently been tasked with organizing a list of survey responses. The responses include both even and odd integers representing different scores given by participants.



// To facilitate analysis, he wants to sort the scores into two separate groups: one for odd scores and another for even scores, each sorted in ascending order.



// Write a program that takes a list of integer scores as input, separates them into odd and even numbers, sorts each group using the heap sort algorithm, and then outputs the sorted lists.

// Input format :
// The first line contains an integer n, representing the total number of scores.

// The second line consists of n space-separated integers score, representing the score given by a participant.

// Output format :
// The output displays the sorted character names in alphabetical order, separated by a space.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 2 ≤ n ≤ 10

// 1 ≤ Scores ≤ 1000



// Sample test cases :
// Input 1 :
// 10
// 9 3 2 1 5 6 7 8 10 4
// Output 1 :
// 1 3 5 7 9 
// 2 4 6 8 10 
// Input 2 :
// 5
// 6 7 8 3 2
// Output 2 :
// 3 7 
// 2 6 8 

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
    int odd[size], even[size];
    int oddCount = 0, evenCount = 0;

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 != 0) {
            odd[oddCount++] = arr[i];
        } else {
            even[evenCount++] = arr[i];
        }
    }

    heapSort(odd, oddCount);
    heapSort(even, evenCount);

    for (int i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");
    
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }

    return 0;
}