// Single File Programming Question
// Problem Statement



// Athulya needs a program that constructs a binary tree from a given array of integers and prints its in-order traversal. The program should take an integer n as input, followed by n integers representing the elements of the array. 



// Then, it constructs a binary tree using the array elements in level order and prints the in-order traversal of the constructed binary tree.

// Input format :
// The first line consists of an integer n, representing the number of elements in the array.

// The second line consists of n space-separated integers representing the elements of the array.

// Output format :
// The output prints a single line containing the inorder traversal of the constructed binary tree in the format "Inorder traversal: <inorder sequence>".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The input integers should be unique.

// 1 ≤ n ≤ 15

// 1 ≤ array elements ≤ 150

// Sample test cases :
// Input 1 :
// 6
// 1 2 3 4 5 6
// Output 1 :
// Inorder traversal: 4 2 5 1 6 3 
// Input 2 :
// 5
// 5 3 7 2 4
// Output 2 :
// Inorder traversal: 2 3 4 5 7


// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

Node* constructTree(vector<int>& arr, int n) {
    if (n <= 0)
        return nullptr;
    
    Node* root = newNode(arr[0]);
    vector<Node*> queue;
    queue.push_back(root);
    
    int i = 1;
    while (!queue.empty() && i < n) {
        Node* node = queue.front();
        queue.erase(queue.begin());
        
        if (i < n) {
            node->left = newNode(arr[i]);
            queue.push_back(node->left);
        }
        i++;
        if (i < n) {
            node->right = newNode(arr[i]);
            queue.push_back(node->right);
        }
        i++;
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    Node* root = constructTree(arr, n);
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}
