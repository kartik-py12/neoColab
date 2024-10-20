// Single File Programming Question
// Problem Statement



// Sarah keeps a two-way linked list of her favorite recipes, each represented by an integer code. She wants to traverse the list to review all recipes, insert a new recipe at the end, and remove a recipe based on its code. Write a program to assist Sarah with these tasks.

// Input format :
// The first line of input consists of an integer N, the number of recipes in the list.

// The second line contains N integers, each representing a recipe code.

// The third line contains an integer M, the code of the new recipe to be inserted at the end of the list.

// The fourth line contains an integer R, the code of the recipe to be removed from the list.

// Output format :
// The first line of output prints the list of recipe codes after inserting the new recipe at the end.

// The second line prints the list of recipe codes after removing the specified recipe code.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 10

// 100 ≤ recipe code ≤ 1000

// R is present in the list.

// Sample test cases :
// Input 1 :
// 5
// 101 202 303 404 505
// 606
// 303
// Output 1 :
// 101 202 303 404 505 606 
// 101 202 404 505 606 
// Input 2 :
// 5
// 101 102 103 104 105
// 106
// 101
// Output 2 :
// 101 102 103 104 105 106 
// 102 103 104 105 106 


// You are using GCC
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node {
    int recipeCode;
    struct Node *prev;
    struct Node *next;
    Node(int data):recipeCode(data),prev(nullptr),next(nullptr) {}
};

// Node* createNode(int recipeCode) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->recipeCode = recipeCode;
//     newNode->prev = NULL;
//     newNode->next = NULL;
//     return newNode;
// }

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->recipeCode);
        temp = temp->next;
    }
    printf("\n");
}

Node* insertAtEnd(Node* head, int newRecipeCode) {
    // Type your code here
    Node *temp=head;
    Node *newNode= new Node(newRecipeCode);
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    newNode->prev=temp;
    temp->next=newNode;
    return head;
    
}

Node* removeByCode(Node* head, int recipeToRemove) {
    // Type your code here
    Node *temp=head;
    if(temp->recipeCode==recipeToRemove){
        head->next->prev=head->prev;
        head=head->next;
        return head;
        
    }
    while(temp->next!=nullptr){
        if(temp->recipeCode==recipeToRemove){
            break;
        }
        temp=temp->next;
    }
    if(temp->next!=nullptr){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    else{
        temp->prev->next=temp->next;
    }
    return head;
}

int main() {
    int N;
    scanf("%d", &N);

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < N; i++) {
        int recipeCode;
        scanf("%d", &recipeCode);
        Node* newNode = new Node(recipeCode);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int newRecipeCode, recipeToRemove;
    scanf("%d", &newRecipeCode);
    scanf("%d", &recipeToRemove);

    head = insertAtEnd(head, newRecipeCode);
    printList(head);

    head = removeByCode(head, recipeToRemove);
    printList(head);

    return 0;
}
