// Single File Programming Question
// Problem Statement



// Alex is organizing a competition where participants' scores are inserted into a binary search tree. He wants to find the k-th smallest score from the tree. Write a program that takes multiple scores as input, constructs the tree, and returns the k-th smallest score based on the input value of k.

// Input format :
// The input consists of multiple integers representing scores (a negative number ends input) followed by an integer k.

// Output format :
// The output prints the k-th smallest score.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ score ≤ 100

// Sample test cases :
// Input 1 :
// 2 3 4 5 6 7 8 -1
// 3
// Output 1 :
// 4
// Input 2 :
// 5 6 3 8 2 -1
// 2
// Output 2 :
// 3


// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

void append(Node **rootadd, int data) {
    Node *temp, *newnode;
    temp = *rootadd;
    newnode = new Node();
    newnode->left = NULL;
    newnode->data = data;
    newnode->right = NULL;
    if (*rootadd == NULL)
        *rootadd = newnode;
    else
    {
        while (1)
        {
            if (data > temp->data)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = newnode;
                    break;
                }
            }
            else
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = newnode;
                    break;
                }
            }
        }
    }
}


//coded

void inorder(Node *root,int &k,int &result){
    if(root==nullptr || k<=0) return;
    inorder(root->left,k,result);
    k--;
    
    if(k==0){
        result=root->data;
        return;
    }
    
    inorder(root->right,k,result);
    
}

int KSmallest(Node *root, int k) {
    //Type your code here
    int result=-1;
    inorder(root,k,result);
    return result;
    
}

//above coded

int main() {
    Node *root = NULL;
    int data, k;
    do
    {
        cin >> data;
        if (data > 0)
            append(&root, data);
    } while (data > 0);
    cin >> k;
    cout << KSmallest(root, k);
    return 0;
}