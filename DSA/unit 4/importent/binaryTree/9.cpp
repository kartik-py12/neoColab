// Single File Programming Question
// Problem Statement



// Ragul wants to build a binary search tree (BST) and perform a key search operation on it. He needs your help to accomplish this. Write a program that helps Ragul create a BST and search for a specific key within it.



// Company Tags: Wipro

// Input format :
// The first line of input consists of the number of nodes n.

// The second line of input consists of n unique values for nodes, separated by a space.

// The third line of input consists of the key to be searched.

// Output format :
// The output displays one of the following messages based on whether the key is found in the binary search tree or not in the following format:



// If the key is found in the binary search tree, print "The key <<key value>> is found in the binary search tree"
// If the key is not found in the binary search tree, print "The key <<key value>> is not found in the binary search tree"


// Refer to the sample output for the exact format.

// Code constraints :
// 1 ≤ n ≤ 10

// Each node value is a unique integer.

// 1 <= key <= 1000

// Sample test cases :
// Input 1 :
// 7
// 101 102 103 105 106 108 110
// 102
// Output 1 :
// The key 102 is found in the binary search tree
// Input 2 :
// 7
// 101 102 103 105 106 108 110
// 115
// Output 2 :
// The key 115 is not found in the binary search tree


// // You are using GCC
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* createNode(int value) {
   
//     //Type your code here
// }

// Node* insertNode(Node* root, int value) {
 
//     //Type your code here
// }

// bool searchKey(Node* root, int key) {
    
//     //Type your code here
// }

// int main() {
//     Node* root = NULL;
//     int numNodes, value, key;

//     cin >> numNodes;

//     for (int i = 0; i < numNodes; i++) {
//         cin >> value;
//         root = insertNode(root, value);
//     }

//     cin >> key;

//     bool found = searchKey(root, key);
//     if (found) {
//         cout << "The key " << key << " is found in the binary search tree";
//     } else {
//         cout << "The key " << key << " is not found in the binary search tree";
//     }

//     return 0;
// }



#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int data) {
        Node* new_node = new Node(data);

        if (root == nullptr) {
            root = new_node;
        } else {
            insertHelper(root, new_node);
        }
    }

    void insertHelper(Node* current, Node* new_node) {
        if (new_node->data < current->data) {
            if (current->left == nullptr) {
                current->left = new_node;
            } else {
                insertHelper(current->left, new_node);
            }
        } else {
            if (current->right == nullptr) {
                current->right = new_node;
            } else {
                insertHelper(current->right, new_node);
            }
        }
    }

    bool search(int key) {
        return searchHelper(root, key);
    }

    bool searchHelper(Node* current, int key) {
        if (current == nullptr) {
            return false;
        }

        if (current->data == key) {
            return true;
        }

        if (key < current->data) {
            return searchHelper(current->left, key);
        } else {
            return searchHelper(current->right, key);
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    BinarySearchTree bst;
    for (int i = 0; i < n; i++) {
        bst.insert(arr[i]);
    }

    int key;
    cin >> key;

    if (bst.search(key)) {
        cout << "The key " << key << " is found in the binary search tree" << endl;
    } else {
        cout << "The key " << key << " is not found in the binary search tree" << endl;
    }

    return 0;
}
