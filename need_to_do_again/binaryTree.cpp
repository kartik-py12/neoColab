// Single File Programming Question
// Problem Statement



// Ragul wants to write a program that performs a specific operation on a binary tree. The program should take an array of elements as input and construct a binary tree. Once the tree is constructed, the program should reverse the alternate levels of the binary tree. Finally, it should print the in-order traversal of the modified tree.

// Input format :
// The first line will contain an integer n, representing the number of elements in the array.

// The second line will contain n space-separated integers, representing the elements of the array.

// Output format :
// The output will be a single line containing the elements of the binary tree after reversing the alternate levels, displayed in the in-order traversal. The elements should be separated by spaces.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 <= n <= 10

// 1 <= array elements <= 1000

// Sample test cases :
// Input 1 :
// 4 
// 1 2 3 4
// Output 1 :
// 4 3 1 2 


// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* maketree(int arr[], Node* root, int i, int n) {
    if (i < n) {
        Node* temp = new Node(arr[i]);
        root = temp;

        root->left = maketree(arr, root->left, 2 * i + 1, n);
        root->right = maketree(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

void preorder(Node* root1, Node* root2, int lvl) 
{
    //Type your code here
    if(root1==nullptr || root2==nullptr) return;
    
    if(lvl%2==0){
        swap(root1->data,root2->data);
    }
    preorder(root1->left,root2->right,lvl+1);
    preorder(root1->right,root2->left,lvl+1);
}

void reverseAlternate(Node* root) {
    preorder(root->left, root->right, 0);
}

void printInorder(Node* node) 
{
   //Type your code here
    if(node==nullptr) return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = maketree(arr, root, 0, n);
    reverseAlternate(root);

    printInorder(root);

    return 0;
}
