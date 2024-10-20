// Single File Programming Question
// Problem Statement



// Dinesh is learning linked lists and wants to create a program that manages a two-way linked list and performs the deletion of a node at a specified position. The program should allow the user to input the number of nodes, their values, and the position of the node to be deleted. After the deletion, the program should display the updated two-way linked list in reverse order.



// Guide Dinesh in completing the program.

// Input format :
// The input begins with an integer n, representing the number of nodes in the two-way linked list.

// The next line contains n space-separated integers representing the data values of each node.

// Finally, an integer p is provided, representing the position(1-based) of the node to be deleted.

// Output format :
// The program should output the two-way linked list before and after the deletion of the specified node.

// The linked list should be displayed in reverse order as a space-separated list of integers.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 20

// 1 ≤ elements ≤ 1000

// Sample test cases :
// Input 1 :
// 4
// 16 24 39 47
// 1
// Output 1 :
// Before deletion: 47 39 24 16 
// After deletion: 39 24 16 
// Input 2 :
// 5
// 5 2 4 8 10
// 7
// Output 2 :
// Before deletion: 10 8 4 2 5 
// After deletion: 10 8 4 2 5 
// Input 3 :
// 8
// 12 34 76 91 28 31 94 57
// 7
// Output 3 :
// Before deletion: 57 94 31 28 91 76 34 12 
// After deletion: 57 94 31 28 91 76 12 

// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
    Node(int val):data(val),next(nullptr),prev(nullptr) {}
};

void deleteNode( Node*& head_ref, Node* del)
{
    if (head_ref == NULL || del == NULL)
        return;

    if (head_ref == del)
        head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

int deleteNodeAtGivenPos(Node*& head, int n)
{
    //Type your code here
    Node *temp=head;
    
    if(n==1){
        Node *delp=temp;
        temp->next->prev=nullptr;
        head=temp->next;
        free(delp);
        
    }
    
    else{
    int count=1;
    for(int i=1;i<n && temp->next!=nullptr;i++){
        temp=temp->next;
        count++;
    }
    
    
    // [easy] deleting node with pre written deleteNode function
    
    // if(count>=n){
    // deleteNode(head,temp);
    // }
    
    // writing our own delete node function [mentos zindagi]
    
    // finding out what value temp holds;
    
    // cout<<endl<<temp->data<<endl; //it holds the value to be deleted as its a 
    //double linked list we can just use prev and next and delete the node easily 
    //but if it was a single linked list we would prefered to stop temp one step 
    //ahead of the value to be deleted and do this 
    //Node *delp=temp->next;  
    //temp->next=temp->next->next;  
    //free(delp);
    
    //now for dll;
    
    //these 3 line are wrong the correct part is highlighted
    // if(temp->next=nullptr){
    //     temp->prev->next=nullptr;
    //     return 0;
        
    // }
    
    if(count>=n){
        Node *delp=temp;
        if(temp->prev!=nullptr){
        temp->prev->next=temp->next;
        }
        if(temp->next!=nullptr){
        temp->next->prev=temp->prev;   
        }
        free(delp);
        }
    }
}


void push(Node*& head_ref, int new_data)
{
    Node *new_node=new Node(new_data);
    new_node->next = (head_ref);

    if ((head_ref) != NULL)
        (head_ref)->prev = new_node;

    (head_ref) = new_node;
}

void printList(struct Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
     Node* head = NULL;

    int n, data;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        push(head, data);
    }

    cout << "Before deletion: ";
    printList(head);

    int pos;
    cin >> pos;

    deleteNodeAtGivenPos(head, pos);

    cout << "\nAfter deletion: ";
    printList(head);

    return 0;
}