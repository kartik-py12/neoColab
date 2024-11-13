// Single File Programming Question
// Problem Statement



// Shabu is managing a fleet of delivery trucks, each with different load capacities. She organizes the trucks so that the truck with the highest capacity is always prioritized at the top of her list, forming a max heap. However, Shabu needs to retire the truck with the smallest load capacity, which is always one of the trucks at the bottom of the list.



// Help Shabu first organize the trucks in max heap order based on their load capacities, then remove the truck with the smallest capacity, and ensure the heap remains correctly arranged after the removal.

// Input format :
// The first line contains an integer n, representing the number of trucks Shabu needs to manage.

// The second line contains n space-separated integers representing the load capacities of the trucks.

// Output format :
// The output prints the load capacities of the trucks after building the max heap.

// The output prints the load capacities of the trucks after removing the truck with the smallest capacity.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ load capacities ≤ 100

// Sample test cases :
// Input 1 :
// 6
// 30 15 40 10 50 25
// Output 1 :
// 50 30 40 10 15 25 
// 50 30 40 25 15 
// Input 2 :
// 4
// 60 80 70 90
// Output 2 :
// 90 80 70 60 
// 90 80 70 


#include <stdio.h>
#include <limits.h>




void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void deleteMinFromMaxHeap(int arr[], int *n) {
    // Find the index of the minimum element
    int minIndex = 0;
    for (int i = 1; i < *n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the minimum element with the last element
    swap(&arr[minIndex], &arr[*n - 1]);
    (*n)--; // Reduce the size of the heap

    // Since the min element was removed, we need to re-heapify the affected part
    if (minIndex < *n) {
        // Re-heapify the affected node
        maxHeapify(arr, *n, minIndex);
    }
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    buildMaxHeap(arr, n);

    printHeap(arr, n);

    deleteMinFromMaxHeap(arr, &n);

    printHeap(arr, n);

    return 0;
}