// You are using GCC

// worked on question 1 2 8 10 of neo colab unit 5 practice lecture 32 
//and not worked on que 5(need to solve using vector)


#include <iostream>
#include <iomanip>

using namespace std;



// Swap function for swapping elements
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// MinHeapify function to maintain heap property
void minHeapify(int heap[], int size, int i) {
    int smallest = i;       //parent
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
void insertElement(int heap[], int &size, int value) {
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
        if(heap[i]==value){
            done =true;
        }
    }
    if(done){
        cout<<value<<" is present";
    }
    else{
        cout<<value<<" is not present";
    }
}

int main() {
    int n;
    cin >> n;

    int *heap = new int[n]; // Dynamic memory allocation for heap
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value);
    }
    
    buildMinHeap(heap, size);
    displayMinHeap(heap, size);
    int val;
    cin>>val;
    task(heap,val,size);
    // double average = averageOfElements(heap, size);
    // cout << "Average: "<< fixed << setprecision(2)<< average;

    delete[] heap; // Free dynamically allocated memory
    return 0;
}