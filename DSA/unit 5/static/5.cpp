// Single File Programming Question
// Problem Statement



// Maya is conducting a survey to analyze customer feedback ratings for a new product. She collects ratings from a number of customers and wants to sort these ratings using the heap sort algorithm to identify trends. Additionally, Maya is interested in calculating the median rating to understand the central tendency of customer satisfaction.



// Your task is to help Maya sort the ratings in ascending order using heap sort and then calculate and display the median value. Finally, present both the sorted ratings and the median in a clear format.

// Input format :
// The first line contains an integer n, representing the number of customer ratings.

// The second line contains n space-separated integers representing the customer ratings.

// Output format :
// The first line prints a single line containing the sorted ratings as space-separated integers.

// The second line prints a second line displaying the median rating formatted to two decimal places as a double value.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ ratings ≤ 100

// Sample test cases :
// Input 1 :
// 3
// 9 5 2
// Output 1 :
// 2 5 9 
// Median: 5.00
// Input 2 :
// 6
// 17 7 5 10 11 22
// Output 2 :
// 5 7 10 11 17 22 
// Median: 10.50

#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2;  

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

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

double calculateMedian(int arr[], int n) {
    if (n % 2 == 0) {
        // If even, median is the average of the two middle numbers
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        // If odd, median is the middle number
        return arr[n / 2];
    }
}

int main() {
    int n;

    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    double median = calculateMedian(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    printf("Median: %.2lf\n", median);

    return 0;
}