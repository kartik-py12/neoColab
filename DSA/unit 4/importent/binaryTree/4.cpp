// Single File Programming Question
// Problem Statement

// ﻿

// Imagine you are given a series of integers that represent the data to be inserted into a binary tree using level-order traversal. Construct the binary tree with these integers and perform a post-order traversal. After printing the post-order traversal, calculate and print the sum of all odd values in the tree.

// Input format :
// The first line contains an integer n, the number of nodes.

// The second line contains n integers, which is the data to be inserted into the tree.

// Output format :
// The first line prints the post-order traversal of the tree, with each value separated by a space.

// The second line prints the sum of all odd values in the tree.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 20

// 1 ≤ elements ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 1 3 4 5 2
// Output 1 :
// Postorder Traversal: 5 2 3 4 1 
// Odd Sum: 9
// Input 2 :
// 5
// 1 7 9 5 6
// Output 2 :
// Postorder Traversal: 5 6 7 9 1 
// Odd Sum: 22




// pre written neo colab syntex

// // You are using GCC
// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node *left, *right;
// };

// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// struct Node* insert(struct Node* root, int data) {
//     //Type your code here
    
// }

// int oddSum = 0;

// void postOrder(struct Node* root) {
//     //Type your code here
    
// }

// int main() {
//     struct Node* root = NULL;
//     int n, data;

//     scanf("%d", &n);

//     while (n-- > 0) {
//         scanf("%d", &data);
//         root = insert(root, data);
//     }

//     printf("Postorder Traversal: ");
//     postOrder(root);
//     printf("\nOdd Sum: %d\n", oddSum);

//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert nodes into the binary tree using level-order traversal
Node* buildTree(const vector<int>& values) {
    if (values.empty()) return nullptr;

    Node* root = new Node(values[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < values.size()) {
        Node* current = q.front();
        q.pop();

        // Insert left child
        if (i < values.size()) {
            current->left = new Node(values[i++]);
            q.push(current->left);
        }

        // Insert right child
        if (i < values.size()) {
            current->right = new Node(values[i++]);
            q.push(current->right);
        }
    }
    
    return root;
}

// Function to perform post-order traversal
void postOrderTraversal(Node* root, vector<int>& result) {
    if (root == nullptr) return;

    postOrderTraversal(root->left, result);  // Traverse left subtree
    postOrderTraversal(root->right, result); // Traverse right subtree
    result.push_back(root->data);             // Visit node
}

// Function to calculate the sum of all odd values in the tree
int sumOfOddValues(Node* root) {
    if (root == nullptr) return 0;

    int sum = 0;
    if (root->data % 2 != 0) {
        sum += root->data; // Add if the value is odd
    }
    sum += sumOfOddValues(root->left);  // Sum for left subtree
    sum += sumOfOddValues(root->right); // Sum for right subtree
    return sum;
}

int main() {
    int n;
    cin >> n; // Input the number of nodes
    vector<int> values(n);
    
    for (int i = 0; i < n; i++) {
        cin >> values[i]; // Input the elements to insert into the tree
    }

    Node* root = buildTree(values); // Build the binary tree

    vector<int> postOrderResult;
    postOrderTraversal(root, postOrderResult); // Perform post-order traversal

    // Output post-order traversal
    cout << "Postorder Traversal: ";
    for (int val : postOrderResult) {
        cout << val << " ";
    }
    cout << endl; // New line after traversal output

    int oddSum = sumOfOddValues(root); // Calculate the sum of odd values
    cout << "Odd Sum: " << oddSum << endl; // Output the sum of odd values

    return 0;
}
