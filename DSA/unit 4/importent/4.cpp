// Single File Programming Question
// Problem Statement



// Ram is organizing a literary competition at a book club where participants submit their favorite quotes. To prepare a display of quotes for the event, Ram wants to sort them in descending alphabetical order.



// Help Ram by writing a program that reads a list of quotes and sorts them in descending order using the quicksort algorithm.

// Input format :
// The first line contains an integer n, representing the number of quotes.

// The second line consists of strings, representing a quote as a string, separated by a space.

// Output format :
// The output displays the sorted list of quotes in descending alphabetical order, each on a new line.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 <= n <= 10

// Each quote is a non-empty string and may contain spaces and punctuation.

// Sample test cases :
// Input 1 :
// 2
// Cap Cat
// Output 1 :
// Cat Cap 
// Input 2 :
// 5
// Chair Door Mouse Keyboard Table
// Output 2 :
// Table Mouse Keyboard Door Chair 



#include <iostream>
#include <algorithm>

using namespace std;

int partition(string arr[], int low, int high) {
    string pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(string arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
