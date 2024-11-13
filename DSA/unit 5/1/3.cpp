// Single File Programming Question
// Problem Statement



// Emily is organizing a competition where participants are judged based on their talent scores represented by characters. She decides to use a Max-Heap data structure to ensure that the highest-scoring participants are prioritized. Emily will input the number of participants and their corresponding talent scores as characters.



// The Max-Heap will maintain the order, with the highest score always at the top. After all participants are added, Emily needs to display the Max-Heap, showing the prioritized order of participants for the competition.

// Input format :
// The first line contains an integer n, the number of participants to be inserted into the Max-Heap.

// The second line contains n space-separated characters representing the talent scores of the participants.

// Output format :
// The output prints the Max-Heap array after all characters have been inserted and the heap property has been maintained.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15

// Each character is a lowercase English letter (i.e., from a to z).

// Sample test cases :
// Input 1 :
// 5
// c b a d e
// Output 1 :
// e d a b c 
// Input 2 :
// 3
// z y x
// Output 2 :
// z y x 

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class MaxHeap {
public:
    MaxHeap() {}

    void insert(char key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    std::vector<char> getHeap() {
        return heap;
    }

private:
    std::vector<char> heap;

    void heapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        if (index > 0 && heap[parentIndex] < heap[index]) {
            std::swap(heap[parentIndex], heap[index]);
            heapifyUp(parentIndex);
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // Ignore the newline after the integer input
    std::string scoresLine;
    std::getline(std::cin, scoresLine);
    
    MaxHeap maxHeap;
    
    std::istringstream iss(scoresLine);
    char score;
    while (iss >> score) {
        maxHeap.insert(score);
    }
    
    std::vector<char> heapArray = maxHeap.getHeap();
    
    // Print the Max-Heap
    for (size_t i = 0; i < heapArray.size(); ++i) {
        std::cout << heapArray[i];
        if (i < heapArray.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}