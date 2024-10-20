// Single File Programming Question
// Problem Statement



// Emma is working with two sets of sensor data recorded in two separate grounded header linked lists. She wants to merge these two lists alternately to analyze the combined data more efficiently. 



// Help Emma by writing a program to merge the two grounded header linked lists alternately.



// Company Tags: TCS

// Input format :
// The first line of input consists of the number of elements n in the first list.

// The second line consists of n elements, separated by space.

// The third line consists of the number of elements m in the second list.

// The fourth line consists of m elements, separated by space.

// Output format :
// The output prints the merged linked list with nodes from both lists alternately.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n, m ≤ 15

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// 5
// 6 7 8 9 10
// Output 1 :
// 1 6 2 7 3 8 4 9 5 10 
// Input 2 :
// 4
// 12 26 34 48
// 4
// 56 59 64 78
// Output 2 :
// 12 56 26 59 34 64 48 78


// You are using GCC
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr) {}
};

// Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }


// Function to insert a new node at the end of a linked list
void insertNode(struct Node* head, int data) {
    Node* newNode = new Node(data);
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to merge two linked lists alternately
Node* mergeLists(Node *&list1, Node *&list2,int n) {
    //Type your code here
    Node *head=new Node(0);
    Node *current=head;
    
    Node *temp1=list1->next;
    Node *temp2=list2->next;
    
    for(int i=0;i<n;i++){
        
        if(temp1!=nullptr){
         current->next=temp1;
         current=current->next;
         temp1=temp1->next;
            
        }
        if(temp2!=nullptr){
            current->next=temp2;
            current=current->next;
            temp2=temp2->next;
        }
    }
    current->next=nullptr;
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head->next;  
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node* list1 = new Node(0);  // Grounded header node for list1
    Node* list2 = new Node(0);  // Grounded header node for list2

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertNode(list1, data);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertNode(list2, data);
    }

    Node* mergedList = mergeLists(list1, list2,n);

    displayList(mergedList);

    return 0;
}