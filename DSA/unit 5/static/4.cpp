// Single File Programming Question
// Problem Statement



// Harish has two lists of integers, one representing the number of items sold in two different months. He wants to merge these two lists and sort the combined data to understand overall sales trends. Harish decides to use a sorting algorithm that structures the data into a heap to simplify the sorting process.



// Your task is to help Harish by merging the two lists and then sorting the combined list in ascending order. Finally, display the sorted list of sales for Harish.

// Input format :
// The first line contains an integer n1, representing the number of items sold in the first month.

// The second line contains n1 space-separated integers representing the sales data for the first month.

// The third line contains an integer n2, representing the number of items sold in the second month.

// The fourth line contains n2 space-separated integers representing the sales data for the second month.

// Output format :
// The output prints a single line containing the combined and sorted sales data as space-separated integers.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n1, n2 ≤ 10

// 1 ≤ sales lists ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 6 4 3 8 7
// 3
// 9 5 2
// Output 1 :
// 2 3 4 5 6 7 8 9 
// Input 2 :
// 5
// 3 9 2 6 8
// 5
// 17 7 5 10 11
// Output 2 :
// 2 3 5 6 7 8 9 10 11 17 

#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2;  

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    for (int i = 0; i < n1; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        result[n1 + i] = arr2[i];
    }
}

int main() {
    int n1, n2;

    scanf("%d", &n1);
    int arr1[n1];

    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &n2);
    int arr2[n2];

    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int result[n1 + n2];
    mergeArrays(arr1, n1, arr2, n2, result);

    heapSort(result, n1 + n2);

    // Print sorted result
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d", result[i]);
        if (i < n1 + n2 - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}