// Single File Programming Question
// Problem Statement



// You are provided with a collection of lowercase letters. Your objective is to create a Binary Search Tree (BST) from these letters.



// Once the BST is constructed, perform an in-order traversal of the tree to display the characters in ascending alphabetical order.

// Input format :
// The first line of input consists of a positive integer N, representing the number of letters.

// The second line consists of N characters, representing the letters to be inserted into the tree.

// Output format :
// The output prints the in-order traversal of the given characters.

// Code constraints :
// 1 ≤ N ≤ 26

// The input characters will be in lowercase.

// Sample test cases :
// Input 1 :
// 5
// k b a c m
// Output 1 :
// a b c k m 
// Input 2 :
// 7
// y q w e g h k
// Output 2 :
// e g h k q w y 


#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char value): data(value), left(nullptr), right(nullptr) {}
};

// Insert characters into the BST
Node* insert(Node* root, char value) {
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

// In-order traversal to print characters in alphabetical order
void inOrder(Node* root) {
    if(root == nullptr) {
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
    
    for(int i = 0; i < N; i++) {
        char ch;
        cin >> ch;
        root = insert(root, ch);
    }
    
    // Perform in-order traversal to print characters in sorted order
    inOrder(root);
    
    return 0;
}