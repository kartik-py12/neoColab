// Single File Programming Question
// Problem Statement



// Revi is fascinated by binary search trees (BSTs) and wants to perform some operations on them. He wishes to construct a binary search tree from a series of positive integers and calculate the sum of all the nodes in the BST.



// Write a program to help Revi implement these operations using the BST concept.

// Input format :
// The input consists of a series of positive integers (greater than zero) separated by a space.

// The input ends when -1 is entered.

// The integers represent the elements to be inserted into the binary search tree.

// Output format :
// The output displays an integer value, which represents the sum of all the nodes in the BST.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The input integers will be positive and greater than zero.

// The number of elements in the binary search tree will be at most 100.

// Sample test cases :
// Input 1 :
// 5
// 3
// 7
// 2
// 4
// 9
// -1
// Output 1 :
// Sum of all nodes in the BST is 30
// Input 2 :
// 6
// 3
// 1
// 4
// 2
// -1
// Output 2 :
// Sum of all nodes in the BST is 16


#include <bits/stdc++.h>
using namespace std;

// Structure of a node in the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the Binary Search Tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to calculate the sum of all nodes in the Binary Search Tree
int sumOfNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int value;

    // Continuously take input until -1 is entered
    while (cin >> value && value != -1) {
        root = insert(root, value);
    }

    // Calculate and print the sum of all nodes
    int sum = sumOfNodes(root);
    cout << "Sum of all nodes in the BST is " << sum << endl;

    return 0;
}