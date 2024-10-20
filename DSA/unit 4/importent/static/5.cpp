// Single File Programming Question
// Problem Statement



// Ravi is spending quality time with his children, teaching them about ascending order through a fun game. To make it more interactive, Ravi has decided to create a simple program that takes a list of characters and demonstrates how to arrange them in ascending order. 



// Guide Ravi by implementing this program using quick sort.

// Input format :
// The first line of input consists of an integer n, representing the number of characters.

// The next line consists of n space-separated characters (lowercase letters or uppercase letters).

// Output format :
// The output displays a single line containing the n characters sorted in ascending order with ASCII values, separated by spaces.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 26

// Sample test cases :
// Input 1 :
// 5
// s A a n h
// Output 1 :
// A a h n s 
// Input 2 :
// 6
// h g f d v a
// Output 2 :
// a d f g h v 
// Input 3 :
// 5
// h a p p y 
// Output 3 :
// a h p p y 

// // You are using GCC
// #include <iostream>
// #include <string>

// using namespace std;

// int partition(char arr[], int low, int high) {
//     //Type your code here
    
// }

// void quickSort(char arr[], int low, int high) {
//     //Type your code here
    
// }

// int main() {
//     int n;
//     cin >> n;

//     char characters[n];

//     for (int i = 0; i < n; ++i) {
//         cin >> characters[i];
//     }

//     quickSort(characters, 0, n - 1);

//     for (int i = 0; i < n; ++i) {
//         cout << characters[i] << " ";
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to perform Quick Sort
int partition(vector<char>& arr, int low, int high) {
    char pivot = arr[high]; // Pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap arr[i] and arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // Swap arr[i + 1] and arr[high]
    return i + 1; // Return the partitioning index
}

// Quick Sort function
void quickSort(vector<char>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1); // Sort elements before partition
        quickSort(arr, pi + 1, high); // Sort elements after partition
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform quick sort
    quickSort(arr, 0, n - 1);

    // Print the sorted characters
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}