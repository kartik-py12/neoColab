// Single File Programming Question
// Problem Statement



// Guide Ramesh in writing a program that simulates the management of customer records in a bank using a circular header linked list. 



// Customers arrive in two batches: the first batch of customer IDs is inserted at the front of the list, while the second batch is inserted at the end of the list. Finally, display the total number of customers in the list and their IDs in order of insertion.



// Company Tags: Capgemini

// Input format :
// The first line contains an integer n1, the number of customer IDs to be inserted at the front.

// The second line contains n1 space-separated integers, the customer IDs to be inserted at the front.

// The third line contains an integer n2, the number of customer IDs to be inserted at the end.

// The fourth line contains n2 space-separated integers, the customer IDs to be inserted at the end.

// Output format :
// The first line of output prints "Number of nodes in the CLL is " followed by the total number of customers in the circular header linked list.

// The second line prints the customer node values.



// Refer to the sample output for the exact text and format.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n1, n2 ≤ 50

// 1 ≤ customer IDs ≤ 500

// Sample test cases :
// Input 1 :
// 3
// 10 20 30
// 2
// 40 50
// Output 1 :
// Number of nodes in the CLL is 5
// 30 20 10 40 50 
// Input 2 :
// 1
// 15
// 2
// 40 50
// Output 2 :
// Number of nodes in the CLL is 3
// 15 40 50 


// You are using GCC
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr) {}
};

// typedef struct Node* NODE;

// NODE getnode() {
//     NODE x = (NODE)malloc(sizeof(struct Node));
//     return x;
// }

Node *insertAtFront(Node *&head, int item) {
    Node *newNode=new Node(item);

    if (head == NULL) {
        head = newNode;
        cout<<"head after newNode "<<head->data<<endl;
        head->next = head;
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }

    head->data++;
    return head;
}

Node *insertAtEnd(Node *&head, int item) {
    //Type your code here
    Node *newNode=new Node(item);
    Node *temp=head->next;
    while(temp->next!=head){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    
    head->data++;
    return head;
    
}

void display(Node *head) {
    //Type your code here
    if(head==nullptr ||head->next==head){
        return;
    }
    cout<<"head data: "<<head->data<<endl;
    Node *temp=head->next;

    cout<<"temp data: "<<temp->data<<endl;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    };
    
    cout<<endl;
}

int main() {
    Node *head = nullptr;
    int item, n;

    head=new Node(0);
    head->next = head; // Empty header node

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &item);
        head = insertAtFront(head, item);
    }

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &item);
        head = insertAtEnd(head, item);
    }

    // Display the linked list
    cout<<"Number of nodes in the CLL is "<<head->data<<endl;
    display(head);
    

    return 0;
}