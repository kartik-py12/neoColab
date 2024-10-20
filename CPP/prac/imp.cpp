// // // You are using GCC
// // #include <stdio.h>
// // #include <stdlib.h>

// // struct Node {
// //     int data;
// //     struct Node* next;
// // };

// // void insertNode(struct Node** head, int data) {
// //     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
// //     newNode->data = data;
// //     newNode->next = NULL;

// //     if (*head == NULL) {
// //         *head = newNode;
// //     } else {
// //         struct Node* temp = *head;
// //         while (temp->next != NULL) {
// //             temp = temp->next;
// //         }
// //         temp->next = newNode;
// //     }
// // }

// // void deleteEvenPositionNodes(struct Node*& head) {
// //     //Type your code here
// // }
// // void displayLinkedList(struct Node* head) {
// //     struct Node* temp = head;
// //     int run=1;
// //     while (temp != NULL) {
// //         if(run%2!=0){
// //         printf("%d ", temp->data);
// //         temp = temp->next->next;
// //         run+=2;
            
// //         }
    
// //     else{
// //         temp=temp->next;
// //     }
// //     }
// //     printf("\n");
    
// // }

// // int main() {
// //     struct Node* head = NULL;
// //     int size;

// //     scanf("%d", &size);

// //     for (int i = 0; i < size; i++) {
// //         int value;
// //         scanf("%d", &value);
// //         insertNode(&head, value);
// //     }

// //     printf("Original Linked List: ");
// //     displayLinkedList(head);

// //     deleteEvenPositionNodes(head);

// //     printf("Final Linked List: ");
// //     displayLinkedList(head);

// //     struct Node* temp = head;
// //     while (head != NULL) {
// //         head = head->next;
// //         free(temp);
// //         temp = head;
// //     }

// //     return 0;
// // }

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int val):data(val),next(nullptr) {}
};

void insertNode(Node*&head,int val){
    Node*newNode=new Node(val);
    Node*temp=head;
    if(head==nullptr){
        head=newNode;
    }
    else{
        // cout<<temp->data<<" ";
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    }
}

void displayNode(Node*head){
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteNode(Node*head,int n){
    Node*temp=head;
    // if(n%2==0){
    //     n-=2;
    // }
    if(n%2!=0){
    for(int i=1;i<n+1 &&temp->next->next!=nullptr;i++){
        if(i%2!=0){
            temp->next=temp->next->next;
        }
        else{
            temp=temp->next;
        }
    }
    }
    else{
    while(temp->next->next!=nullptr){
        
        temp->next=temp->next->next;
        temp=temp->next;
        // cout<<temp->data<<"d ";    
    }
    if(temp->next!=nullptr){
        temp->next=nullptr;
    }
    }
}

int main(){
    int n;
    Node*head=nullptr;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        insertNode(head,ele);
    }
    cout<<"Original Linked List: ";
    displayNode(head);
    cout<<"Final Linked List: ";
    deleteNode(head,n);
    displayNode(head);

}


// #include<iostream>
// using namespace std;
// #include <vector>

// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr;
//     for(int i=0;i<n;i++){
//         int ele;
//         cin>>ele;
//         arr.push_back(ele);
//     }
//     cout<<"Original Linked List: ";
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     cout<<"Final Linked List: ";
//     for(int i=1;i<n+1;i++){
//         if(i%2!=0){
//             cout<<arr[i-1]<<" ";
//         }
//     }
// }