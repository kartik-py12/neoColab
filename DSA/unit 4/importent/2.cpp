// Single File Programming Question
// Problem Statement



// In a mystical land known as Eldoria, ancient wizards use magical runes to cast powerful spells. These runes are represented by single characters, each possessing a unique magical property. However, the wizards have a challenge: they need these magical runes sorted in a specific order for their spells to work correctly.



// Write a program to help the wizards of Eldoria sort their magical runes based on their potency. Each rune is represented by a single character, and each character holds a unique level of magical power, determined by its position in the ASCII table.



// Your task is to implement a merge sorting logic and recursive function to arrange these magical runes in descending order of their magical potency.

// Input format :
// The first line of input consists of an integer n, representing the number of magical runes to be sorted.

// The second line contains n space-separated characters, each representing a magical rune.

// Output format :
// The output displays a single line containing the magical runes sorted in descending order of their magical potency, separated by spaces.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 <= n <= 25

// Each character in the array is a single uppercase letter or a single lowercase letter.

// Sample test cases :
// Input 1 :
// 8
// G h I J K L m n
// Output 1 :
// n m h L K J I G 
// Input 2 :
// 6
// a Z A B M Z
// Output 2 :
// a Z Z M B A 

#include <iostream>
#include <vector>

using namespace std;

// Function to merge two halves in descending order
void merge(vector<char>& runes, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to hold the halves
    vector<char> leftHalf(n1), rightHalf(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftHalf[i] = runes[left + i];
    for (int i = 0; i < n2; ++i)
        rightHalf[i] = runes[mid + 1 + i];

    // Merge the temp arrays back into the main array in descending order
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftHalf[i] >= rightHalf[j]) {
            runes[k] = leftHalf[i];
            i++;
        } else {
            runes[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftHalf, if any
    while (i < n1) {
        runes[k] = leftHalf[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightHalf, if any
    while (j < n2) {
        runes[k] = rightHalf[j];
        j++;
        k++;
    }
}

// Function to implement merge sort recursively
void mergeSort(vector<char>& runes, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(runes, left, mid);
        mergeSort(runes, mid + 1, right);

        // Merge the sorted halves
        merge(runes, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> runes(n);
    for (int i = 0; i < n; ++i) {
        cin >> runes[i];
    }

    // Apply merge sort to sort the runes in descending order
    mergeSort(runes, 0, n - 1);

    // Output the sorted runes
    for (int i = 0; i < n; ++i) {
        cout << runes[i];
        if (i != n - 1) cout << " ";  // Ensure space between elements
    }
    cout << endl;

    return 0;
}