// Single File Programming Question
// Problem Statement

// ﻿

// Alice is working on a project where she needs to build a complete binary tree from an array of integers. After constructing the tree, she wants to perform a post-order traversal to retrieve the node values in a specific order. 



// Write a program that takes the number of nodes and the array as input and outputs the post-order traversal of the tree.

// Input format :
// The first line contains an integer n, representing the number of elements in the array.

// The second line contains n space-separated integers, representing the values of the nodes in the binary tree.

// Output format :
// The output displays a single line containing n space-separated integers, which represent the postorder traversal of the binary tree constructed from the input array.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15

// 1 ≤ array elements ≤ 100

// Sample test cases :
// Input 1 :
// 3
// 1 2 3
// Output 1 :
// 2 3 1 
// Input 2 :
// 5
// 1 2 3 4 5
// Output 2 :
// 4 5 2 3 1 





//pre written neo colab syntax


// // You are using GCC
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_NODES 100

// struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };

// int ans[MAX_NODES];
// int idx = 0;

// struct TreeNode* createNode(int x) {
//     //Type your code here
    
// }

// void postorder(struct TreeNode* root) {
//     //Type your code here
    
// }

// void fillArray(struct TreeNode* root) {
//     postorder(root);
// }

// int* postorderTraversal(struct TreeNode* root) {
//     fillArray(root);
//     return ans;
// }

// struct TreeNode* createTree(int arr[], int i, int n) {
//     //Type your code here
    
// }

// int main() {
//     int n;
//     scanf("%d", &n);

//     int arr[MAX_NODES];
//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &arr[i]);
//     }

//     struct TreeNode* root = createTree(arr, 0, n);

//     int* postorderResult = postorderTraversal(root);

//     for (int i = 0; i < n; ++i) {
//         printf("%d ", postorderResult[i]);
//     }

//     return 0;
// }



#include <iostream>
#include <vector>

using namespace std;

// Function to perform post-order traversal
void postOrderTraversal(int index, const vector<int>& arr, vector<int>& result) {
    if (index >= arr.size()) {
        return; // Base case: if the index is out of bounds
    }
    
    // Traverse the left subtree
    postOrderTraversal(2 * index + 1, arr, result);
    
    // Traverse the right subtree
    postOrderTraversal(2 * index + 2, arr, result);
    
    // Visit the node
    result.push_back(arr[index]);
}

int main() {
    int n;
    cin >> n; // Input the number of nodes
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the elements of the array
    }

    vector<int> result;
    postOrderTraversal(0, arr, result); // Start post-order traversal from the root (index 0)

    // Output the post-order traversal result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " "; // Print each node in post-order
    }
    cout << endl; // New line at the end

    return 0;
}
