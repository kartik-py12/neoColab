// Single File Programming Question
// Problem Statement



// Sharon is working on a programming project that involves manipulating Binary Search Trees (BST). She is currently developing a program to delete all the odd-valued nodes in a given BST and display the resulting modified BST using an in-order traversal.



// Help Sharon complete this task.

// Input format :
// The first line of input consists of an integer N, representing the number of nodes in the BST.

// The second line consists of N space-separated integers, representing the values of the nodes in the BST.

// Output format :
// The output prints the in-order traversal of the nodes in the modified BST after deleting all odd-valued nodes.

// If odd-valued nodes are not found, print the in-order traversal of the given input values of nodes.

// The nodes should be printed using an inorder traversal, separated by a space.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ nodes ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 4 6 2 8 10
// Output 1 :
// 2 4 6 8 10 
// Input 2 :
// 8
// 44 32 55 87 99 23 12 89
// Output 2 :
// 12 32 44 




#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node in the BST
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



// In-order traversal to print the BST in sorted order
void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    int N;
    cin >> N;
    
    Node* root = nullptr;
    
    // Insert the nodes into the BST
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        if(value%2==0){
        root = insert(root, value);
        }
    }

    // Perform in-order traversal to print the remaining nodes
    inOrder(root);
    
    return 0;
}