// Single File Programming Question
// Problem Statement



// John, a computer science student, is learning about binary search trees (BST) and their properties. He decides to write a program to create a BST, display it in post-order traversal, and find the minimum value present in the tree.



// Help him by implementing the program.

// Input format :
// The first line of input consists of an integer N, representing the number of elements to insert into the BST.

// The second line consists of N space-separated integers data, which is the data to be inserted into the BST.

// Output format :
// The first line of output prints the space-separated elements of the BST in post-order traversal.

// The second line prints the minimum value found in the BST.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ data ≤ 1000

// Sample test cases :
// Input 1 :
// 3
// 5 10 15
// Output 1 :
// 15 10 5 
// The minimum value in the BST is: 5
// Input 2 :
// 10
// 10 5 15 3 7 12 18 20 25 30
// Output 2 :
// 3 7 5 12 30 25 20 18 15 10 
// The minimum value in the BST is: 3


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