// Single File Programming Question
// Problem Statement



// A company is designing an organizational structure to manage employees hierarchically. Each employee is represented as a node in a binary tree, where each node (positive integer) contains the employee's ID. The organization uses a level-order approach to insert employees into the tree. Each new employee is added to the next available position in the current level of the binary tree.



// The system needs to:



// Insert new employee's ID positive integers into the organizational structure following a level-order traversal.
// Print out the IDs of employees in the organization using an in-order traversal.


// Example



// Input

// 1 2 3 0

// Output

// 2 1 3

// Explanation

// 1 is the root of the Binary tree. 2 is the left child of 1, and 3 is the right child of 1. Hence the in-order traversal is 2 1 3, which follows the rule Left Root Right.

// Input format :
// The input consists of a sequence of positive integers, where each integer represents an employee ID.

// The sequence ends with a non-positive integer (e.g., 0 or -1), which indicates the end of input.

// Output format :
// The output displays the sequence of integers representing the employee IDs in the in-order traversal of the binary tree.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 <= employee ID <= 100

// Sample test cases :
// Input 1 :
// 1 2 3 0
// Output 1 :
// 2 1 3 
// Input 2 :
// 1 2 3 4 5 6 7 -8
// Output 2 :
// 4 2 5 1 6 3 7 


#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

Node* newNode(int data) {
  Node* node = new Node;
  node->data = data;
  node->left = node->right = NULL;
  return (node);
}

void insert(Node*& root, int data) {
  if (root == NULL) {
    root = newNode(data);
    return;
  }

  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node* temp = q.front();
    q.pop();

    if (temp->left == NULL) {
      temp->left = newNode(data);
      return;
    } else
      q.push(temp->left);

    if (temp->right == NULL) {
      temp->right = newNode(data);
      return;
    } else
      q.push(temp->right);
  }
}

void inorder(Node* root) {
  if (root == NULL) return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main() {
  Node* root = NULL;
  int data;

  while (cin >> data && data > 0) {
    insert(root, data);
  }

  inorder(root);
  cout << endl;

  return 0;
}
