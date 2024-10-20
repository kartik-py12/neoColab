// Single File Programming Question
// Problem Statement



// Raj, a mechanic, uses a linked list to track the cars waiting for repair. He needs to remove a car with a particular license plate number and also delete a car from a specific position in his list. Assist Raj by writing a program that allows him to perform these deletions based on given inputs.

// Input format :
// The first line of input consists of an integer N, the number of cars in the list.

// The second line contains N integers, each representing the license plate number of a car.

// The third line contains an integer R, the license plate number of the car to be removed.

// The fourth line contains an integer P, the position (0-based index) of the car to be removed.

// Output format :
// The output prints the updated list of license plate numbers after performing the deletions.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the given test cases will fall under the following constraints:

// 3 ≤ N ≤ 10

// 1000 ≤ license plate number ≤ 9999

// R is present in the list.

// Sample test cases :
// Input 1 :
// 3
// 1111 2222 3333
// 1111
// 0
// Output 1 :
// 3333 
// Input 2 :
// 5
// 1011 1034 1900 8789 9899
// 9899
// 3
// Output 2 :
// 1011 1034 1900 


// You are using GCC
#include <stdio.h>
#include <stdlib.h>
//4:25
#include <iostream>
using namespace std;
struct Node {
    int licensePlate;
    struct Node *next;
    Node(int val):licensePlate(val),next(nullptr) {}
    
};

// Node* createNode(int licensePlate) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->licensePlate = licensePlate;
//     newNode->next = NULL;
//     return newNode;
// }

Node* deleteByPlate(Node* head, int plateToRemove) {
    // Type your code here
    Node *temp=head;
    if(temp->licensePlate==plateToRemove){
        head=temp->next;
    }
    
    
    else{
    while(temp->next->licensePlate!=plateToRemove){
        temp=temp->next;
        }

    temp->next=temp->next->next;
    }
    return head;
}

Node* deleteByPosition(Node* head, int position) {
    // Type your code here
    Node *temp=head;
    if(position==0){
        head=temp->next;
        return head;
    }
    for(int i=0;i<position-1;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->licensePlate);
        temp = temp->next;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < N; i++) {
        int licensePlate;
        scanf("%d", &licensePlate);
        Node* newNode = new Node(licensePlate);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int plateToRemove, positionToRemove;
    scanf("%d", &plateToRemove);
    scanf("%d", &positionToRemove);

    head = deleteByPlate(head, plateToRemove);
    head = deleteByPosition(head, positionToRemove);

    printList(head);

    return 0;
}
