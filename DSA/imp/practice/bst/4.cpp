// Single File Programming Question
// Problem Statement



// Kumar is studying data structures and is currently learning about Binary Search Trees (BST). He wants to implement the operations of creating and displaying a Binary Search Tree.



// Write a program that takes a sequence of positive integers as input and constructs a BST using these integers. After constructing the BST, the program should display the nodes in ascending order.

// Input format :
// The input consists of a series of positive integers greater than zero, separated by a space.

// The input ends when -1 is entered.

// The integers represent the elements to be inserted into the binary search tree.

// Output format :
// The output displays the elements of the binary search tree in ascending order (sorted order), separated by space.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The input integers > 0.

// The number of elements in the binary search tree will be at most 100.

// Sample test cases :
// Input 1 :
// 1
// 2
// 3
// 4
// 5
// -1
// Output 1 :
// 1 2 3 4 5 
// Input 2 :
// 7
// 6
// 4
// 5
// 3
// -1
// Output 2 :
// 3 4 5 6 7 


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value): data(value), left(nullptr), right(nullptr) {}
};

// Insert values into the BST following BST properties
Node* insert(Node* root, int value) {
    if(root == nullptr) {
        return new Node(value);
    }
    if(value < root->data) {
        root->left = insert(root->left, value);
    } else if(value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// In-order traversal to print the BST in ascending order
void inOrder(Node* root) {
    if(root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;
    int value;
    
    // Keep inserting values until we encounter -1
    while(cin >> value && value != -1) {
        root = insert(root, value);
    }
    
    // Perform in-order traversal to print elements in sorted order
    inOrder(root);
    
    return 0;
}