// Single File Programming Question
// Problem Statement



// Alice is preparing for a coding competition and wants to practice her skills with linked lists. She decides to write a program that allows her to create a linked list by inserting elements at the front. 



// Help Alice with her task.



// Company tags: HCL

// Input format :
// The first line of input consists of an integer n, representing the number of elements to be inserted.

// The second line of input consists of n space-separated integers, representing the elements to be inserted in the linked list.

// The third line of input consists of an integer m, representing the value to be inserted at the front of the linked list.

// Output format :
// The first line of output displays "Created Linked list: " followed by the elements of the linked list.

// The second line of output displays "Final List: " followed by the elements of the linked list after inserting the new element at the front.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ elements, m ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 6 5 4 3 2
// 1
// Output 1 :
// Created Linked list: 2 3 4 5 6 
// Final List: 1 2 3 4 5 6 
// Input 2 :
// 4
// -10 20 -30 40
// 5
// Output 2 :
// Created Linked list: 40 -30 20 -10 
// Final List: 5 40 -30 20 -10 

// You are using GCC
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val):data(val), next(nullptr) {}
};

void insertAtHead(Node *&head,const int &val){
    Node *newNode= new Node(val);
    newNode->next=head;
    head=newNode;
}

void printList(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    Node *head=nullptr;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        insertAtHead(head,val);
    }
    int num;
    cin>>num;
    cout<<"Created Linked list: ";
    printList(head);
    insertAtHead(head,num);
    cout<<"Final List: ";
    printList(head);
    
}