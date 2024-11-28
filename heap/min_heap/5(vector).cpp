// Single File Programming Question
// Problem Statement



// Benjamin is conducting a survey to understand the age distribution of participants in a community event. He collects the ages and wants to identify how many participants are younger than a specified age threshold.



// To organize the data efficiently, Benjamin uses a Min-Heap to sort the ages. After inputting the ages and the threshold age, he builds the Min-Heap and counts the number of participants younger than the specified age. Finally, Benjamin prints both the sorted ages and the count of younger participants for analysis.

// Input format :
// The first line contains an integer n, the number of participants.

// The second line contains n space-separated integers representing the ages of the participants.

// The third line contains an integer value, the age threshold to compare against.

// Output format :
// The first line prints the Min-Heap array after all elements have been inserted and the heap property has been maintained.

// The second line prints the count of participants whose ages are less than the specified threshold age.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15

// 1 ≤ age ≤ 100

// 1 ≤ age threshold ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 5 3 8 1 4
// 4
// Output 1 :
// 1 3 8 5 4 
// 2
// Input 2 :
// 5
// 7 2 9 6 8
// 2
// Output 2 :
// 2 6 9 7 8 
// 0



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printHeap(const std::vector<int>& heap) {
    for (int val : heap) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> heap;
    int n;

    // Input the number of elements
    // std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Input the elements
    // std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        heap.push_back(value);
    }

    // Convert vector into a min-heap
    std::make_heap(heap.begin(), heap.end(), std::greater<int>());

    // Print the Min-Heap
    // std::cout << "Min-Heap elements: ";
    int thre;
    cin>>thre;
    int count=0;
    for(int i=0;i<n;i++){
        if(heap[i]<thre){
            count++;
        }
    }
    printHeap(heap);
    cout<<count;

    // // Adding another element to the heap
    // int newElement;
    // std::cout << "Enter an element to add to the heap: ";
    // std::cin >> newElement;
    // heap.push_back(newElement);
    // std::push_heap(heap.begin(), heap.end(), std::greater<int>());

    // std::cout << "Min-Heap after adding " << newElement << ": ";
    // printHeap(heap);

    // // Removing the smallest element
    // std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
    // heap.pop_back();

    // std::cout << "Min-Heap after removing the smallest element: ";
    // printHeap(heap);

    return 0;
}