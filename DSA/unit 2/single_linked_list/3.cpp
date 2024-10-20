// Single File Programming Question
// Problem Statement



// Sarath is developing a text document editor that supports adding text lines at both the beginning and the end of the document. The editor should first read a list of initial lines to insert at the beginning of the document and then read an additional line to append at the end. 



// Guide Sarath in implementing the functionality to handle these operations using a singly linked list and display the final state of the document.



// Company tags: Capgemini

// Input format :
// The first line of input consists of an integer, n representing the number of lines in the document.

// The next n lines consist of the lines of text that constitute the document.

// The last line of input consists of a string s, which needs to be appended at the end of the document.

// Output format :
// The first line of output prints "Document: " followed by the initial document content, which inserts the given n values at the beginning.

// The second line prints "Updated Document: " followed by the final document content, which appends the given value s at the end of the document.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 10

// Sample test cases :
// Input 1 :
// 3
// Apple
// Banana
// Orange
// Grapes
// Output 1 :
// Document: Orange Banana Apple
// Updated Document: Orange Banana Apple Grapes
// Input 2 :
// 2
// Hello
// World
// Space
// Output 2 :
// Document: World Hello
// Updated Document: World Hello Space


// You are using GCC
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node{
    string data;
    Node *next;
    Node(string val):data(val),next(nullptr) {}
};

//with linked list

void insertAtHead(Node *&head,const string &val){
    Node *newNode= new Node(val);
    newNode->next=head;
    head=newNode;
}

void insertAtEnd(Node *head, const string &val){
    Node *newNode= new Node(val);
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
    cin.ignore();
    Node *head=nullptr;
    
    for(int i=0;i<n;i++){
        string line;
        getline(cin,line);
        insertAtHead(head,line);
    }
    cout<<"Document: ";
    printList(head);
    string insert;
    cin>>insert;
    insertAtEnd(head,insert);
    cout<<"Updated Document: ";
    printList(head);
    
    
}

//without linked list

// int main(){
//     int n;
//     cin>>n;
//     vector<string> str(n+1);
//     for(int i=0;i<n;i++){
//         cin>>str[i];
//     }
//     cout<<"Document: ";
//     for(int i=n-1;i>=0;i--){
//         cout<<str[i]<<" ";
//     }
//     cout<<endl;
//     string word;
//     cin>>word;
//     cout<<"Updated Document: ";
//     for(int i=n-1;i>=0;i--){
//         cout<<str[i]<<" ";
//     }
//     cout<<word<<endl;
// }