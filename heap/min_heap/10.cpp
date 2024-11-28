// Single File Programming Question
// Problem Statement



// Aiden is working on organizing his collection of unique integers, which represent the number of books he has in different categories. He wants to create a min heap out of these integers so that he can quickly access the category with the smallest number of books. Additionally, Aiden is curious about the sum of all even and odd numbers in his collection.



// Write a program that builds a min heap from Aiden's collection of numbers, displays the min heap, and calculates the sum of even and odd numbers separately.

// Input format :
// The first line contains an integer representing n representing the number of integers in Aiden's collection.

// The second line contains n space-separated integers representing the number of books in each category.

// Output format :
// The first line displays the min heap structure, where the smallest number of books is at the root.

// The second line displays the sum of all even numbers in the collection.

// The third line displays the sum of all odd numbers in the collection.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ no.of. books ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 2 4 1 5 9
// Output 1 :
// Min Heap: 1 4 2 5 9 
// Sum of even elements: 6
// Sum of odd elements: 15


#include <iostream>
using namespace std;



// Swap function for swapping elements
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// MinHeapify function to maintain heap property
void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

// Build the Min Heap by calling minHeapify from the last non-leaf node to the root
void buildMinHeap(int heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

// Insert an element into the heap
void insertElement(int heap[], int &size, int value,int &sumEven,int &sumOdd) {
    if(value%2==0){
        sumEven+=value;
    }else{
        sumOdd+=value;
    }
    if (size < 100) { // Optional: limit size to 100 for example
        heap[size] = value;
        int i = size;
        size++;

        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
}

// Display the heap elements
void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void task(int heap[],int value,int size){
    int count=0;
    bool done=false;
    for(int i=0;i<size;i++){
        if(heap[i]<value){
            count++;
        }
    }
    cout<<count;
}

int main() {
    int n;
    cin >> n;
    int heap[n];
    int size = 0;
    int sumEven = 0, sumOdd = 0;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value, sumEven, sumOdd);
    }
    buildMinHeap(heap, size);
    cout << "Min Heap: ";
    displayMinHeap(heap, size);
    cout << "Sum of even elements: " << sumEven << endl;
    cout << "Sum of odd elements: " << sumOdd;
    return 0;
}