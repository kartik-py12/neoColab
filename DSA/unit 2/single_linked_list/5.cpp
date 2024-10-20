// Single File Programming Question
// Problem Statement



// Aaron is building a text editor feature to check if a user-entered word is a palindrome using a singly linked list. Each character of the word is stored as a node in the linked list. Write a program for him to construct the linked list from user input and determine if the word is a palindrome.



// Company Tags: Amazon, Microsoft, Snapdeal

// Input format :
// The input consists of a series of space-separated characters (alphabets, digits, special symbols). Enter $ to stop.

// Output format :
// The output prints whether the given characters form a palindrome or not.



// Refer to the sample output for the exact text and format.

// Code constraints :
// The input will be valid ASCII characters.

// Sample test cases :
// Input 1 :
// 1 2 3 4 5 4 3 2 1 $
// Output 1 :
// The linked list is a palindrome
// Input 2 :
// a b c d e f $
// Output 2 :
// The linked list is not a palindrome
// Input 3 :
// ! @ # % ^ % # @ ! $
// Output 3 :
// The linked list is a palindrome

// You are using GCC
#include <iostream>
#include <stack>
using namespace std;

// Linked list node
struct Node {
    char data;
    struct Node* next;
    Node(int val):data(val),next(nullptr) {}
};



// Function to check if a linked list is a palindrome
bool isPalindrome(Node *head) {
    //Type your code here
    if(head==nullptr){
        return true;
    }
    
    stack<char> s;
    Node *temp=head;
    
    while(temp!=nullptr){
        s.push(temp->data);
        temp=temp->next;
    }
    
    temp=head;
    while(temp !=nullptr){
        char top =s.top();
        s.pop();
        if(temp->data !=top){
            return false;
        }
        temp=temp->next;
    }
    return true;
}



// Function to create a linked list based on user input
struct Node* createLinkedList() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    char val;
    while (true) {
        scanf(" %c", &val);
        if (val == '$') {
            break;
        }

        Node *newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    struct Node* head = createLinkedList();

    bool palindrome = isPalindrome(head);
    if (palindrome) {
        printf("The linked list is a palindrome\n");
    } else {
        printf("The linked list is not a palindrome\n");
    }

    return 0;
}