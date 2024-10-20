// Single File Programming Question
// Problem Statement



// Sam needs to sort an array of integers using the divide-and-conquer method. He wants to implement the merge sort algorithm, displaying the array after each iteration to track the sorting process. 



// Assist him in writing a program that divides the array, merges it back, and prints the array.

// Input format :
// The first line of input consists of an integer n, denoting the array size.

// The second line consists of n space-separated integers, representing the array of elements.

// Output format :
// The first line of output prints the given array.

// The following lines print the sorted array, after each iteration.

// The last line of output prints the final sorted array.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 20

// 0 ≤ array elements ≤ 50

// Sample test cases :
// Input 1 :
// 6
// 4 1 5 3 2 6
// Output 1 :
// Given Array
// 4 1 5 3 2 6 
// After iteration 1
// 1 4 5 3 2 6 
// After iteration 2
// 1 4 5 3 2 6 
// After iteration 3
// 1 4 5 2 3 6 
// After iteration 4
// 1 4 5 2 3 6 
// After iteration 5
// 1 2 3 4 5 6 
// Sorted Array
// 1 2 3 4 5 6 
// Input 2 :
// 8
// 8 1 7 2 6 3 5 4
// Output 2 :
// Given Array
// 8 1 7 2 6 3 5 4 
// After iteration 1
// 1 8 7 2 6 3 5 4 
// After iteration 2
// 1 8 2 7 6 3 5 4 
// After iteration 3
// 1 2 7 8 6 3 5 4 
// After iteration 4
// 1 2 7 8 3 6 5 4 
// After iteration 5
// 1 2 7 8 3 6 4 5 
// After iteration 6
// 1 2 7 8 3 4 5 6 
// After iteration 7
// 1 2 3 4 5 6 7 8 
// Sorted Array
// 1 2 3 4 5 6 7 8 


// // You are using GCC
// #include <stdio.h>

// int rec = 0;

// void conquer(int arr[], int l, int m, int r, int size) {
//     //Type your code here
    
// }

// void divide(int arr[], int l, int r, int size) {
//     //Type your code here
    
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     int arr[n];
//     for (int i = 0; i < n; i++)
//         scanf("%d", &arr[i]);
//     printf("Given Array\n");
//     for (int i = 0; i < n; ++i)
//         printf("%d ", arr[i]);
//     divide(arr, 0, n - 1, n);
//     printf("\nSorted Array\n");
//     for (int i = 0; i < n; ++i)
//         printf("%d ", arr[i]);
//     return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

// Function to merge two halves of the array
void merge(vector<int>& arr, int left, int mid, int right, int iteration) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    vector<int> L(n1), R(n2);
    
    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Print the array after merging
    cout << "After iteration " << iteration << endl;
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// Function to implement merge sort
void mergeSort(vector<int>& arr, int left, int right, int& iteration) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid, iteration);
        mergeSort(arr, mid + 1, right, iteration);
        merge(arr, left, mid, right, ++iteration);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print the given array
    cout << "Given Array" << endl;
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    int iteration = 0;
    mergeSort(arr, 0, n - 1, iteration);
    
    // Print the final sorted array
    cout << "Sorted Array" << endl;
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}