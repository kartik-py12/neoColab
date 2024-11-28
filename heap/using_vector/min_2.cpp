




//in 3 min heap question this method
// passed all test cases in 2 of them 












// Single File Programming Question
// Problem Statement



// Caleb loves to organize his collection of rare coins, and he wants to ensure that he can quickly find any coin in his collection. To do this, he decides to implement a min-heap data structure. Caleb inputs the number of coins and their respective values, inserting each value into the min-heap.



// After building the heap, he checks if a specific coin is present in his collection. He prints the entire heap and whether the coin is found, helping him maintain his collection efficiently.

// Input format :
// The first line contains an integer n, representing the number of elements.

// The second line contains n integers separated by spaces, representing the values of the coins.

// The third line contains an integer C, representing the value of the coin to check for presence in the heap.

// Output format :
// The first line outputs the elements of the min-heap in sorted order, separated by spaces.

// The second line indicates whether the specified element is present in the heap, formatted as:

// "C is present" if the element is found.
// "C is not present" if the element is not found.


// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15

// 1 ≤ value ≤ 1000

// 1 ≤ C ≤ 1000

// Sample test cases :
// Input 1 :
// 4
// 10 5 15 20
// 6
// Output 1 :
// 5 10 15 20 
// 6 is not present
// Input 2 :
// 5
// 8 3 12 7 25
// 7
// Output 2 :
// 3 7 12 8 25 
// 7 is present


//unable to do using vector need to find out the reason

#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    std::vector<int> heap;

    // Function to heapify up after insertion
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;           
            if (heap[index] < heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // // Function to heapify down after removal
    // void heapifyDown(int index) {
    //     int size = heap.size();
    //     while (true) {
    //         int left = 2 * index + 1;
    //         int right = 2 * index + 2;
    //         int smallest = index;

    //         if (left < size && heap[left] < heap[smallest]) {
    //             smallest = left;
    //         }
    //         if (right < size && heap[right] < heap[smallest]) {
    //             smallest = right;
    //         }
    //         if (smallest != index) {
    //             std::swap(heap[index], heap[smallest]);
    //             index = smallest;
    //         } else {
    //             break;
    //         }
    //     }
    // }

public:
    void find(int value){
        bool found=false;
        for(int val:heap){
            if(val==value){
                found=true;
            }
        }
        
        if(found){
            cout<<value <<" is present";
        }else{
            cout<<value<<" is not present";
        }
    }
    // Insert an element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // // Remove and return the minimum element
    // int extractMin() {

    //     int minElement = heap[0];
    //     heap[0] = heap.back();
    //     heap.pop_back();
    //     heapifyDown(0);
    //     return minElement;
    // }

    // Print the heap elements
    void printHeap() const {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap minHeap;
    int n;

    // Input the number of elements
    std::cin >> n;

    // Input the elements
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        minHeap.insert(value);
    }

    // Print the Min-Heap
    minHeap.printHeap();
    int value;
    cin>>value;
    minHeap.find(value);

    // // Extract the minimum element
    // try {
    //     std::cout << "Extracted minimum: " << minHeap.extractMin() << std::endl;
    //     std::cout << "Min-Heap after extraction: ";
    //     minHeap.printHeap();
    // } catch (const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }

    return 0;
}