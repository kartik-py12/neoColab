// Single File Programming Question
// Problem Statement



// Jake maintains a linked list of his gym members, each represented by a unique membership number. Jake needs to check if a particular membership number is part of his list of active members. Write a solution to help Jake find out if the membership number exists in his linked list.

// Input format :
// The first line of input consists of an integer N, the number of active gym members in the list.

// The second line contains N integers, each representing a unique membership number of an active gym member.

// The third line contains an integer M, representing the membership number that Jake needs to check in the list.

// Output format :
// The output prints "Membership number M is active" if the membership number exists in the list.

// Otherwise, the output prints "Membership number M is not in the list".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the given test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ membership number ≤ 1000

// Sample test cases :
// Input 1 :
// 2
// 889 911
// 977
// Output 1 :
// Membership number 977 is not in the list
// Input 2 :
// 3
// 100 200 300
// 100
// Output 2 :
// Membership number 100 is active

// You are using GCC
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node {
    int membershipNumber;
    struct Node *next;
    Node(int data): membershipNumber(data),next(nullptr) {}
};

// Node* createNode(int membershipNumber) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->membershipNumber = membershipNumber;
//     newNode->next = NULL;
//     return newNode;
// }

int isMemberInList(Node* head, int membershipToCheck) {
    // Type your code here
    Node *temp=head;
    bool found=false;
    if(temp==nullptr){
        cout<<"Membership number "<<membershipToCheck<<"is not in the list";
    }
    while(temp!=nullptr){
        if(temp->membershipNumber==membershipToCheck){
            cout<<"Membership number "<<membershipToCheck<<"is active";
            found =true;
        }
        temp=temp->next;
    }
    if(!found){
        cout<<"Membership number "<<membershipToCheck<<" is not in the list";
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Node* head = NULL;
    Node* tail = NULL;

    // Read the initial list of membership numbers
    for (int i = 0; i < N; i++) {
        int membershipNumber;
        scanf("%d", &membershipNumber);
        Node* newNode = new Node(membershipNumber);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int membershipToCheck;
    scanf("%d", &membershipToCheck);

    // Type your code here
    isMemberInList(head,membershipToCheck);
    return 0;
}
