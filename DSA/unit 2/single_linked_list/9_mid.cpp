// Single File Programming Question
// Problem Statement



// In a warehouse, a system keeps track of packages using a grounded header linked list where each node represents a package. Each package is added to the end of the list. Sometimes, packages need to be removed from specific positions in the list. 



// Your task is to implement this system which can add packages to the list, display the list, and remove a package from a specified position.

// Input format :
// The first line contains an integer, n, which represents the number of packages to be added to the list.

// The second line contains n integers, each representing the ID of a package.

// The third line contains an integer, position, which indicates the position of the package to be removed from the list (1-based index).

// Output format :
// The first line of output represents the elements before deletion and the next line represents the remaining elements in the linked list after deleting the particular value.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 25

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 10 20 30 40 50
// 2
// Output 1 :
// Linked List before deletion: 10 20 30 40 50 
// Linked List after deletion: 10 30 40 50 
// Input 2 :
// 5
// 12 23 43 56 89
// 5
// Output 2 :
// Linked List before deletion: 12 23 43 56 89 
// Linked List after deletion: 12 23 43 56 

// You are using GCC
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int val):data(val),next(nullptr) {}
};

void insertNode(struct Node* header, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    struct Node* current = header;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void displayList(const struct Node* header) {
    const struct Node* current = header->next;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void deleteNodeAtPosition(Node *&head, int position) {
    //type your code here
    Node *temp=head;
    for(int i=1;i<position && temp!=nullptr;i++){
        temp=temp->next;
    }
    
    Node *todelete =temp->next;
    temp->next=temp->next->next;
    free(todelete);
    
    
}

void deleteList(struct Node* header) {
    struct Node* current = header;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    struct Node* header = (struct Node*)malloc(sizeof(struct Node));
    header->next = NULL;

    int newData;
    int listSize;
    scanf("%d", &listSize);

    for (int i = 0; i < listSize; i++) {
        scanf("%d", &newData);
        insertNode(header, newData);
    }

    printf("Linked List before deletion: ");
    displayList(header);

    int position;
    scanf("%d", &position);

    deleteNodeAtPosition(header, position);

    printf("Linked List after deletion: ");
    displayList(header);

    deleteList(header);

    return 0;
}