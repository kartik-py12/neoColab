// Single File Programming Question
// Problem Statement



// Ashok, a retail store manager wants to keep track of the items in inventory using a two-way linked list. Each item has an ID, name, quantity, and price. The manager needs to be able to insert new items at the beginning of the list and search for an item by its ID to check its presence. 



// Your task is to create a program to help Ashok manage the inventory and perform searches efficiently.



// Company Tags: Amazon

// Input format :
// The first line of input contains an integer n representing the number of items to be added to the inventory.

// The next n lines each contain:

// An integer representing the item ID.
// A string representing the item name.
// An integer representing the item quantity.
// A double value representing the item price.
// The last line contains an integer representing the ID of the item to be searched.

// Output format :
// Print a message indicating whether the item with the given ID is present in the list.



// Refer to the sample output for the exact format.

// Code constraints :
// 1 ≤ n ≤ 20

// Sample test cases :
// Input 1 :
// 3
// 101
// Pen
// 10
// 5.99
// 102
// Notebook
// 5
// 12.99
// 103
// Pencil
// 20
// 1.99
// 101
// Output 1 :
// Item with ID 101 is present in the list.
// Input 2 :
// 2
// 201
// Chair
// 8
// 49.99
// 202
// Table
// 3
// 99.99
// 203
// Output 2 :
// Item with ID 203 is not found in the list.

// You are using GCC
#include <iostream>
using namespace std;
struct Item {
    int id;
    std::string name;
    int quantity;
    double price;
};

struct Node {
    Item data;
    Node* prev;
    Node* next;
    Node(Item item):data(item),prev(nullptr),next(nullptr) {}
};

void insertAtBeginning(Node*& head, Item newItem) {
    //Type your code here
    Node *newNode=new Node(newItem);
    if(head==nullptr){
        // newNode->next=head;
        head=newNode;
    }
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    
}

bool searchItem(Node* head, int searchId) {
    //Type your code here
    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data.id==searchId){
            return true;
        }

        temp=temp->next;
    }
    return 0;
}

int main() {
    Node* head = nullptr;
    int n, searchId;

    std::cin >> n;

    // Create the doubly linked list
    for (int i = 0; i < n; i++) {
        Item newItem;
        std::cin >> newItem.id;
        std::cin >> newItem.name;
        std::cin >> newItem.quantity;
        std::cin >> newItem.price;

        insertAtBeginning(head, newItem);
    }

    std::cin >> searchId;

    bool found = searchItem(head, searchId);

    if (found)
        std::cout << "Item with ID " << searchId << " is present in the list." << std::endl;
    else
        std::cout << "Item with ID " << searchId << " is not found in the list." << std::endl;

    return 0;
}