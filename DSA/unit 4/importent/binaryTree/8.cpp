// Single File Programming Question
// Problem Statement



// Sita is working on implementing a binary search tree (BST). She wants to write functions to insert nodes into the BST, delete nodes from the BST (the number of nodes she wants to delete and then request the values of those nodes), and perform an in-order traversal of the BST to display the updated BST. 



// Help her in implementing the function to delete the specified nodes.

// Input format :
// The first line of input consists of an integer N, representing the number of nodes to be inserted into the BST.

// The second line consists of N space-separated integers, representing the values of the nodes to be inserted into the BST.

// The third line consists of an integer M, representing the number of nodes to delete.

// The fourth line consists of M space-separated integers key, representing the values of the nodes to be deleted from the BST.

// Output format :
// The output prints the space-separated values of the BST in in-order traversal, after deleting the specified nodes.

// If the specified nodes are not in the BST, print the in-order traversal of the given values.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ values ≤ 100

// 1 ≤ M ≤ 10

// 1 ≤ key ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 3 7 2 4 8
// 1
// 3
// Output 1 :
// 2 4 7 8 
// Input 2 :
// 5
// 3 4 2 5 1
// 2
// 7 8
// Output 2 :
// 1 2 3 4 5 
// Input 3 :
// 6
// 3 5 4 7 8 1
// 3
// 5 8 1
// Output 3 :
// 3 4 7 


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

// struct Node* insert(struct Node* root, int data) {
//     if (root == NULL) {
//         return createNode(data);
//     }

//     if (data < root->data) {
//         root->left = insert(root->left, data);
//     } else if (data > root->data) {
//         root->right = insert(root->right, data);
//     }

//     return root;
// }

// void inorderTraversal(struct Node* root) {
//     if (root == NULL) {
//         return;
//     }

//     inorderTraversal(root->left);
//     printf("%d ", root->data);
//     inorderTraversal(root->right);
// }

// struct Node* deleteNode(struct Node* root, int key) {
//     //Type your code here
    
// }

// int main() {
//     struct Node* root = NULL;
//     int n, data;
    
//     scanf("%d", &n);
    
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &data);
//         root = insert(root, data);
//     }
    
//     scanf("%d", &n);
    
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &data);
//         root = deleteNode(root, data);
//     }

//     inorderTraversal(root);

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node *root;

    BST() {
        root = nullptr;
    }

    void insert(int data) {
        Node *new_node = new Node(data);
        if (root == nullptr) {
            root = new_node;
            return;
        }

        Node *current = root;
        Node *parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (data < parent->data) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }

    void deleteNode(int key) {
        Node *current = root;
        Node *parent = nullptr;
        while (current != nullptr && current->data != key) {
            parent = current;
            if (key < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (current == nullptr) {
            return;
        }

        if (current->left == nullptr && current->right == nullptr) {
            if (parent == nullptr) {
                root = nullptr;
            } else if (parent->left == current) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete current;
        } else if (current->left == nullptr) {
            if (parent == nullptr) {
                root = current->right;
            } else if (parent->left == current) {
                parent->left = current->right;
            } else {
                parent->right = current->right;
            }
            delete current;
        } else if (current->right == nullptr) {
            if (parent == nullptr) {
                root = current->left;
            } else if (parent->left == current) {
                parent->left = current->left;
            } else {
                parent->right = current->left;
            }
            delete current;
        } else {
            Node *successor = current->right;
            Node *successor_parent = current;
            while (successor->left != nullptr) {
                successor_parent = successor;
                successor = successor->left;
            }

            current->data = successor->data;

            if (successor_parent->left == successor) {
                successor_parent->left = successor->right;
            } else {
                successor_parent->right = successor->right;
            }
            delete successor;
        }
    }

    void inOrder() {
        inOrder(root);
    }

private:
    void inOrder(Node *current) {
        if (current == nullptr) {
            return;
        }

        inOrder(current->left);
        cout << current->data << " ";
        inOrder(current->right);
    }
};

int main() {
    int n;
    cin >> n;

    BST bst;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        bst.insert(data);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int key;
        cin >> key;
        bst.deleteNode(key);
    }

    bst.inOrder();

    return 0;
}
