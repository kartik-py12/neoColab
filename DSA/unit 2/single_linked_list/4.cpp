// Single File Programming Question
// Problem Statement



// A software engineer is developing a function for a new feature in an editor application that rearranges numerical data. To test this, they need to create a singly linked list where each node contains an integer. 



// The task is to swap every two adjacent nodes in the linked list and print the list before and after swapping.



// Company Tags: Amazon, Microsoft, Moonfrog Labs

// Input format :
// The first line of input consists of an integer n, representing the number of nodes in the linked list.

// The second line consists of n integers, representing the data values for each node in the linked list.

// Output format :
// The first line of output prints the linked list before swapping.

// The second line prints the linked list after swapping.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 30

// 0 ≤ data values ≤ 100

// Sample test cases :
// Input 1 :
// 6
// 3 1 5 4 2 8
// Output 1 :
// Before swapping: 3 1 5 4 2 8 
// After swapping: 1 3 4 5 8 2 
// Input 2 :
// 5
// 1 2 3 4 5
// Output 2 :
// Before swapping: 1 2 3 4 5 
// After swapping: 2 1 4 3 5

// You are using GCC
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val):data(val),next(nullptr) {}
};

void insertAtEnd(Node *&head,int val){
    Node *newNode=new Node(val);
    // newNode->next=head;
    // head=newNode;
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

void sortList(Node *&head,int n){
    Node *temp=head;
    if(n%2!=0){
        n--;
    }
    for(int i=0;i<n;i+=2){
        
        int val=temp->data;
        temp->data=temp->next->data;
        temp->next->data=val;
        
        temp=temp->next->next;
    }
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
        int num;
        cin>>num;
        insertAtEnd(head,num);
    }
    cout<<"Before swapping: ";
    printList(head);
    cout<<"After swapping: ";
    sortList(head,n);
    printList(head);
}

