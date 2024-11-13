// You are using GCC
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int value):data(value),left(nullptr),right(nullptr) {};
};


Node* insert(Node* root, int value) {
    //Type your code here
    if(root==nullptr){
        return new Node(value);
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }
    else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
    
}

void inorderTraversal(Node* root) {
    //Type your code here
    if(root==nullptr){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main() {
    Node* root =nullptr;
    int value;
    int count = 0;

    while (true) {
        scanf("%d", &value);
        if (value == -1){
             break;
        }
        root = insert(root, value);
    }

    inorderTraversal(root);
    // printf("\n%d\n", count);

    return 0;
}