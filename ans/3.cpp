#include <iostream>
#include <vector>
#include <algorithm> // For heap functions
using namespace std;

void printMaxHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> heap;
    int num_elements;

    cin >> num_elements;
    for (int i = 0; i < num_elements; i++) {
        int value;
        cin >> value;
        heap.push_back(value);          // Add the new value to the vector
        push_heap(heap.begin(), heap.end()); // Maintain max-heap property
    }

    printMaxHeap(heap); // Display the max-heap
    return 0;
}
