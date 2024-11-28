#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

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

void buildMinHeap(int heap[], int size) {
    for (int i = (size / 2) - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

void insertElement(int heap[], int &size, int value) {
    size++;
    int i = size - 1; //last index of heap
    heap[i] = value;// insert the value at the end
// while heap child is > then parent swap them
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2; //jump to 
    }
}

bool isElementInHeap(int heap[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == value) {
            return true; // Element found
        }
    }
    return false; // Element not found
}

void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int heap[n];
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value);
    }

    buildMinHeap(heap, size);

    displayMinHeap(heap, size);

    return 0;
}