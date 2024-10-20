// Single File Programming Question
// Problem Statement



// Nina, a vet, keeps track of various pets for checkups using a circular linked list. Each pet is represented by an integer code. Nina wants to traverse the list of pets, add a new pet to the end of the list, and remove a pet based on its code. Implement a solution to help Nina with these tasks.

// Input format :
// The first line of input consists of an integer N, the number of pets currently in the circular linked list.

// The second line contains N integers, each representing a pet code.

// The third line contains an integer M, the code of the new pet to be added to the end of the list.

// The fourth line contains an integer R, the code of the pet to be removed from the list.

// Output format :
// The first line of output prints the list of pet codes after inserting the new pet at the end.

// The second line prints the list of pet codes after removing the specified pet code.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ pet code ≤ 100

// R is present in the list.

// Sample test cases :
// Input 1 :
// 7
// 12 59 23 70 71 34 78
// 88
// 12
// Output 1 :
// 12 59 23 70 71 34 78 88 
// 59 23 70 71 34 78 88 
// Input 2 :
// 5
// 32 28 49 26 18
// 99
// 28
// Output 2 :
// 32 28 49 26 18 99 
// 32 49 26 18 99 


// You are using GCC
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//206
struct Node {
    int petCode;
    struct Node *next;
    Node(int data):petCode(data),next(nullptr) {}
};

// Node* createNode(int petCode) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->petCode = petCode;
//     newNode->next = NULL;
//     return newNode;
// }

void printList(Node* head) {
    if (head == NULL) {
        return;
    }
    
    Node* temp = head;
    do {
        printf("%d ", temp->petCode);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

Node* insertAtEnd(Node* head, int newPetCode) {
    // Type your code here
    Node *temp=head;
    Node *newNode= new Node(newPetCode);
    while(temp->next!=head){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    
    return head;
    
}

Node* removeByCode(Node* head, int petToRemove) {
    // Type your code here
    
    Node *temp=head;
    Node *last=temp->next;
    while(last->next!=head){
        last=last->next;
    }
    if(temp->petCode==petToRemove){
        last->next=last->next->next;
        head=head->next;
        
        return head;
    }


    while(temp->next!=head){
        if(temp->next->petCode==petToRemove){
            temp->next=temp->next->next;
        }
        temp=temp->next;
        
    }
    

    return head;
}

int main() {
    int N;
    scanf("%d", &N);

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < N; i++) {
        int petCode;
        scanf("%d", &petCode);
        Node* newNode = new Node(petCode);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    int newPetCode, petToRemove;
    scanf("%d", &newPetCode);
    scanf("%d", &petToRemove);

    head = insertAtEnd(head, newPetCode);
    printList(head);

    head = removeByCode(head, petToRemove);
    printList(head);

    return 0;
}
