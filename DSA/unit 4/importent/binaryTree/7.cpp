// Single File Programming Question
// Problem Statement



// Romit, a student studying data structures, wants to explore the concept of left subtrees within binary search trees (BST).



// He plans to create a program that builds a BST, inserts data into it while keeping track of the number of elements added to the left subtree, and finally counts the nodes in the left subtree.

// Input format :
// The first line of input consists of an integer N, representing the number of elements to insert into the BST.

// The second line consists of N space-separated integers, representing the data to be inserted into the BST.

// Output format :
// The output prints the number of nodes in the left subtree of the BST.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ data ≤ 1000

// The input data values are distinct.

// Sample test cases :
// Input 1 :
// 3
// 5 3 7
// Output 1 :
// 1
// Input 2 :
// 6
// 10 8 15 6 9 12
// Output 2 :
// 3



// // You are using GCC
// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* left;
//     struct Node* right;
// };

// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// struct Node* insert(struct Node* root, int data, int* leftSubtreeSize) {
//     //Type your code here
    
// }

// int countLeftSubtreeNodes(struct Node* root) {
//     //Type your code here
    
// }

// int main() {
//     struct Node* root = NULL; 
//     int n, data;
//     scanf("%d", &n);

//     int leftSubtreeSize = 0; 

//     for (int i = 0; i < n; i++) {
//         scanf("%d", &data);
//         root = insert(root, data, &leftSubtreeSize);
//     }

//     int nodesInLeftSubtree = countLeftSubtreeNodes(root->left);
//     printf("%d", nodesInLeftSubtree);

//     return 0;
// }



#include <iostream>
using namespace std;

// Node structure for the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to count the nodes in a subtree
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the nodes in the left subtree
int countLeftSubtree(Node* root) {
    if (root == nullptr) {
        return 0; // If the tree is empty, return 0
    }
    return countNodes(root->left); // Count nodes in the left subtree
}

int main() {
    int N;
    cin >> N; // Read the number of elements to insert

    Node* root = nullptr; // Initialize the root of the BST
    int data;

    // Read elements and insert them into the BST
    for (int i = 0; i < N; i++) {
        cin >> data;
        root = insert(root, data);
    }

    // Count and output the number of nodes in the left subtree
    cout << countLeftSubtree(root) << endl;

    return 0;
}
