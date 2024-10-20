// Single File Programming Question
// Problem Statement



// Diego is organizing a digital library and wants to categorize books based on the years they were published. He has a list of publication years stored as integers, which he needs to sort in ascending order to make it easier to find books from a specific year. Diego uses a custom quicksort algorithm to sort these publication years efficiently.



// Help Diego by writing a program that reads a list of publication years and sorts them in ascending order using the quicksort algorithm.

// Input format :
// The first line contains an integer N, representing the number of publication years.

// The second line consists of N space-separated integers, representing a publication year.

// Output format :
// The output displays the integers, representing the sorted list of publication years, separated by spaces.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// N > 0

// Each year is a 4-digit positive integer.

// Sample test cases :
// Input 1 :
// 5
// 2014 2009 2000 1997 1865
// Output 1 :
// 1865 1997 2000 2009 2014 
// Input 2 :
// 3
// 1496 3015 2056
// Output 2 :
// 1496 2056 3015


#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements in a vector
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Partition function for quicksort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

// Quicksort function
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);  // Recursively sort the left subarray
        quicksort(arr, pi + 1, high);  // Recursively sort the right subarray
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
