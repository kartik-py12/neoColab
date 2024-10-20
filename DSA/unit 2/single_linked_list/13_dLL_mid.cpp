// Single File Programming Question
// Problem Statement



// In a customer service system, interactions between users and the service team are recorded in a log. Each interaction is represented by a unique identifier. Your task is to analyze the log and determine the number of unique user interactions.



// Utilize a two-way linked list to solve the program.



// Company Tags: Amazon

// Input format :
// The first line of input consists of an integer N, representing the number of interactions.

// This is followed by N lines of strings, each representing an interaction identifier.

// Output format :
// The output prints a single line containing the number of unique user interactions.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ N ≤ 20﻿

// Sample test cases :
// Input 1 :
// 3
// ABC123
// DEF456
// GHI789
// Output 1 :
// Number of unique user interactions: 3
// Input 2 :
// 5
// ABC123
// DEF456
// ABC123
// JKL987
// DEF456
// Output 2 :
// Number of unique user interactions: 3
// Input 3 :
// 2
// XYZ789
// XYZ789
// Output 3 :
// Number of unique user interactions: 1


// You are using GCC
#include <iostream>
#include <string>
using namespace std;

struct Node {
    std::string data;
    Node* prev;
    Node* next;
    Node(string val):data(val),prev(nullptr),next(nullptr) {}
};

void insertAtBeginning(Node** head, const std::string& newData) {
    Node* newNode = new Node(newData);
    newNode->next = *head;

    if (*head != nullptr)
        (*head)->prev = newNode;

    *head = newNode;
}

int countUniqueInteractions(Node* head) {
    //Type your code here
    // cout<<head->data<<endl;
    Node *temp1=head;
    Node *temp2=head->next;
    
    int count=0;
    while(temp1!=nullptr){
        bool found =false;
        temp2=temp1->next;
        while(temp2!=nullptr){
            if(temp1->data==temp2->data){
                found=true;
                // cout<<"temp 1 data if : "<<temp1->data<<endl;
                // cout<<"temp 2 data if : "<<temp2->data<<endl;
                break;
            }
            else{
                // cout<<"temp 2 data: "<<temp2->data<<endl;
                // cout<<"temp 1 data: "<<temp1->data<<endl;
                temp2=temp2->next;
            }

        }
        if(found==false){
            count++;
        }
        temp1=temp1->next;
        
    }
    return count;
}

int main() {
    Node* head = nullptr;
    int n;
    std::string data;

    std::cin >> n;

    // Create the doubly linked list
    for (int i = 0; i < n; i++) {
        std::cin >> data;
        insertAtBeginning(&head, data);
    }

    int uniqueInteractions = countUniqueInteractions(head);

    std::cout << "Number of unique user interactions: " << uniqueInteractions << std::endl;

    return 0;
}