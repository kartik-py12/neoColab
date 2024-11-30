// //<= at current->right because of handling the duplicates value && see the append logic



// Single File Programming Question
// Problem Statement



// Kathir is learning about binary search trees (BSTs) in his computer science class. He has just implemented a simple program to create a binary search tree and calculate the sum of all its leaf nodes. Can you help him validate his code and solve some scenarios to test it?



// For example, consider a tree with the following structure:

//    5

//    / \

//   3  7

//   / \  \

//  2  4  9



// In this tree, the leaf nodes are 2, 4, and 9. The program should compute the sum of these leaf node elements, which is 2 + 4 + 9 = 15.

// Input format :
// The input consists of a series of positive integers as input, each on a separate line.

// The input terminates when Kathir enters -1. This signifies the end of input.

// You can assume that the input integers are unique.

// Output format :
// The output displays the sum of all the leaf nodes in the binary search tree.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// All input integers will be positive integers (greater than 0).

// The number of nodes in the binary tree is at most 100.

// The value of each node is at most 100.

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
// Sum of all leaf nodes are 15
// Input 2 :
// 6
// 3
// 1
// 4
// 2
// -1
// Output 2 :
// Sum of all leaf nodes are 6


// You are using GCC
#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
struct node* root;

//Function to create node

struct node* createNode(int d)
{
  //Type your code here
  node *newNode=new node();
  newNode->data=d;
  newNode->left=nullptr;
  newNode->right=nullptr;
  return newNode;
}

//Function to insert nodes into binary search tree
void append(int d) {
    if (root == nullptr) {  // If the tree is empty, create a new root
        root = createNode(d);
        return;
    }

    // Traverse the tree to find the correct position
    struct node* current = root;
    while (true) {
        if (d < current->data) {  // Move to the left subtree
            if (current->left == nullptr) {
                current->left = createNode(d);
                break;
            } else {
                current = current->left;
            }
        } else if (d >= current->data) {  // Move to the right subtree
            if (current->right == nullptr) {
                current->right = createNode(d);
                break;
            } else {
                current = current->right;
            }
        } else {
            // Do nothing if the value already exists in the BST
            break;
        }
    }
}
void leafsum(node* root, int* sum)
{
  if (!root)
    return;
  if (!root->left && !root->right)
    *sum += root->data;
  leafsum(root->left, sum);
  leafsum(root->right, sum);
}

int main()
{
  int d;
  do
  {
    cin >> d;
    if (d > 0)
      append(d);
  } while (d != -1);
  int sum = 0;
  leafsum(root, &sum);
  cout << "Sum of all leaf nodes are " << sum;
  return 0;
}
