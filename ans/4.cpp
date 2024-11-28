#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;  // Input number of trucks
    vector<int> trucks(n);

    // Input the load capacities of the trucks
    for (int i = 0; i < n; i++) {
        cin >> trucks[i];
    }

    // Step 1: Build the max heap
    make_heap(trucks.begin(), trucks.end(), less<int>());
    
    // Output the heap after building max heap
    for (int i = 0; i < n; i++) {
        cout << trucks[i] << " ";
    }
    cout << endl;

    // Step 2: Find the smallest element in the max heap
    int minElement = *min_element(trucks.begin(), trucks.end());
    
    // Step 3: Remove the smallest element from the heap
    auto it = find(trucks.begin(), trucks.end(), minElement);
    if (it != trucks.end()) {
        trucks.erase(it);  // Remove the smallest element from the vector
    }

    // Step 4: Rebuild the heap to maintain the max heap property
    make_heap(trucks.begin(), trucks.end(), less<int>());
    
    // Output the heap after removing the smallest element
    for (int i = 0; i < trucks.size(); i++) {
        cout << trucks[i] << " ";
    }
    cout << endl;

    return 0;
}
