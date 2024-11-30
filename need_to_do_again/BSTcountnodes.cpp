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

// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// int ls=0;
Node* insert(Node* root, int data, int& leftSubtreeSize) {

    if(root==nullptr) return createNode(data);
    
    if(data<root->data){
        // cout<<root->data<<":"<<data<<endl;
        root->left=insert(root->left,data,leftSubtreeSize);
        // ls++;
    }
    else if(data>root->data){
        root->right=insert(root->right,data,leftSubtreeSize);
    }
    
    return root;
    
}


int countNodes(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the nodes in the left subtree
int countLeftSubtreeNodes(Node* root) {
    if (root == nullptr) return 0;
    return countNodes(root);
}


int main() {
    Node* root = nullptr; 
    int n, data;
    cin >> n;

    int leftSubtreeSize = 0; 

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data, leftSubtreeSize);
    }

    int nodesInLeftSubtree = countLeftSubtreeNodes(root->left);
    cout << nodesInLeftSubtree;

    return 0;
}