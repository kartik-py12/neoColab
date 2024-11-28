
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
 int n = 5;
 std::vector<int> coins = {10, 5,15, 20};
 int C = 7;

 // Build the min-heap
 std::make_heap(coins.begin(), coins.end(), std::greater<int>());

 // Print heap in array representation
 std::cout << "Min-Heap Elements: ";
 for (int x : coins) {
     std::cout << x << " ";
 }
 std::cout << std::endl;

 // Check if C is present
 if (std::find(coins.begin(), coins.end(), C) != coins.end()) {
     std::cout << C << " is present" << std::endl;
 } else {
     std::cout << C << " is not present" << std::endl;
 }

 return 0;
}
