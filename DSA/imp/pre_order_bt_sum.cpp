
// Answered
// 2/2
// Bookmarked
// 0/2
// Skipped
// 0/2
// Not Viewed
// 0/2
// Saved in Server
// 2/2
// View More
// Question No : 2 / 2
// bookmarkIcon
// reportIcon
// Single File Programming Question
// Problem Statement



// In a small garment manufacturing company, the manager wants to track the production of different types of clothes each day. The factory produces three main types of garments: shirts, pants, and jackets. To better manage inventory, the manager decides to represent the daily production of these garments in a hierarchical structure, where each type of garment is assigned a specific production count.



// The production of shirts is considered the root of the structure.
// The production of pants is considered the left child of the shirts.
// The production of jackets is considered the right child of the shirts.


// The manager needs to calculate the total production count for the day by summing up the production numbers of all three types of garments.



// Write a program that takes the production count of shirts, pants, and jackets as input and outputs the total sum of all garments produced that day using preorder traversal.

// Input format :
// The first line contains an integer, val1, representing the number of shirts produced.

// The second line contains an integer, val2, representing the number of pants produced.

// The third line contains an integer, val3, representing the number of jackets produced.

// Output format :
// The output displays a single line as an integer, representing the total sum of all garments produced in the following format:

// "Total sum of all clothes: <totalSum>".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 0 <= val1, val2, val3 <= 1000

// Sample test cases :
// Input 1 :
// 6 7 8
// Output 1 :
// Total sum of all clothes: 21
// Input 2 :
// 76 89 78
// Output 2 :
// Total sum of all clothes: 243


// You are using GCC
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

int preorderTraversal(struct Node* root,int sum)
{
    //Type your code here
    if(root==nullptr){
        return 0;
    }
    

    return root->key+preorderTraversal(root->left,sum)+preorderTraversal(root->right,sum);
}


int main() {
    int val1, val2, val3;
    scanf("%d", &val1);
    scanf("%d", &val2);
    scanf("%d", &val3);

    struct Node* root = newNode(val1);
    root->left = newNode(val2);
    root->right = newNode(val3);

    int s=0;
    int totalSum = preorderTraversal(root,s);
    printf("Total sum of all clothes: %d", totalSum);

    return 0;
}