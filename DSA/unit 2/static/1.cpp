// Single File Programming Question
// Problem Statement



// Lena is a librarian managing a list of books in her library. Each book is represented by an integer ID. Lena needs to update her list by adding a new book ID to the beginning of the list, another ID to the end, and a third ID at a random position within the list. 



// Your task is to help Lena implement a function to perform these insertions and manage the book list efficiently.

// Input format :
// The first line of input consists of an integer N, the number of existing books in the list.

// The second line contains N integers, each representing the ID of a book.

// The third line contains an integer B, the ID of the book to be added at the beginning.

// The fourth line contains an integer E, the ID of the book to be added at the end.

// The fifth line contains an integer p, the position at which the third ID will be inserted (0-based index).

// The sixth line contains an integer R, the ID of the book to be added at p.

// Output format :
// The output prints the updated list of book IDs after performing the insertions.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the given test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ book ID ≤ 1000

// 0 ≤ p ≤ N

// Sample test cases :
// Input 1 :
// 3
// 100 200 300
// 10 
// 20
// 1
// 30
// Output 1 :
// 10 30 100 200 300 20 
// Input 2 :
// 5
// 101 102 103 104 105
// 200
// 300
// 4
// 400
// Output 2 :
// 200 101 102 103 400 104 105 300 
// Input 3 :
// 2
// 11 22
// 10 
// 20
// 2
// 30
// Output 3 :
// 10 11 30 22 20 

// You are using GCC
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int val):data(val),next(nullptr) {}
    
};

// Node* createNode(int data) {
//     Node *newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

void insertAtBeginning(Node *&head, int newID) {
    // Type your code here
    Node *newNode= new Node(newID);
    Node *temp=head;
    if(head==nullptr){
        head=newNode;
    }else{
        newNode->next=head;
        head=newNode;
    }
}

void insertAtEnd(Node *&head, int newID) {
    // Type your code here
    Node *newNode= new Node(newID);
    
    if(head==nullptr){
        head=newNode;
        return;
    }
    
    Node *temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    
    
}

void insertAtPosition(Node *&head, int position, int newID) {
    // Type your code here
    Node *newNode= new Node(newID);
    Node *temp=head;
    // cout<<temp->next->data<<endl;
    if(position==0){
        newNode->next=temp;
        head=newNode;
        // temp->next=newNode;
    }
    else{
    for(int i=0;i<position-1;i++){
        // cout<<"i="<<i<<" "<<"position = "<<position<<endl;
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Node *head = NULL;
    int bookID;

    for (int i = 0; i < N; i++) {
        scanf("%d", &bookID);
        insertAtEnd(head, bookID);
    }

    int newID1, newID2, randomPosition, newID3;
    scanf("%d", &newID1);
    scanf("%d", &newID2);
    scanf("%d", &randomPosition);
    scanf("%d", &newID3);

    insertAtBeginning(head, newID1);
    insertAtEnd(head, newID2);
    insertAtPosition(head, randomPosition, newID3);

    printList(head);
    freeList(head);

    return 0;
}
