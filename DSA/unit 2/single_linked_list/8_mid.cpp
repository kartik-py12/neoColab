// Single File Programming Question
// Problem Statement



// Suppose you are working on a text editing application and you need to implement a feature that allows users to insert a character at a specific index in the text. You decide to implement this feature using a grounded header linked list to manage the text efficiently.



// Company Tags: Capgemini

// Input format :
// The first line of input consists of an integer n, representing the number of characters.

// The second line consists of n space-separated characters.

// The third line consists of an integer index representing the position(0- based) for insertion.

// The fourth line consists of a character to be inserted at the specified index.

// Output format :
// The output prints "Updated list: " followed by the list elements after inserting the character at the specified index.

// Print "Invalid position." for invalid inputs.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 0 ≤ n ≤ 10

// Sample test cases :
// Input 1 :
// 5
// A B C D E
// 2
// X
// Output 1 :
// Updated list: A B X C D E 
// Input 2 :
// 3
// P Q R
// 0
// S
// Output 2 :
// Updated list: S P Q R 
// Input 3 :
// 7
// p q r s t u v
// 10
// l
// Output 3 :
// Invalid position.
// Updated list: p q r s t u v

// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char val):data(val),next(nullptr) {}
};

// Node* createNode(char value) {
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->next = nullptr;
//     return newNode;
// }

void insertAfterPosition(Node *&head, int position, char value) {
    //Type your code here
    Node *temp=head;
    int current=0;
    Node *newNode= new Node(value);
    while(temp!=nullptr && current<position){
        temp=temp->next;
        current++;

        }
        newNode->next=temp->next;
        temp->next=newNode;
    
}

void displayList(Node* head) {
    Node* current = head->next;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node('\0'); 
    int n;
    char value;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> value;
        insertAfterPosition(head, i, value);
    }

    int position;
    std::cin >> position;

    std::cin >> value;
    if(n>position){
        insertAfterPosition(head, position, value);
    }
    else{
        cout<<"Invalid position."<<endl;
    }
    
    std::cout << "Updated list: ";

    displayList(head);

    deleteList(head);

    return 0;
}