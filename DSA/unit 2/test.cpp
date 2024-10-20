// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// void traverseList(Node* head) {
//     int count = 0;
//     while (head != NULL) {
//         count++;
//         head = head->next;
//     }
//     cout << count;
// }

// int main() {
//     Node* head = nullptr;
//     Node* second = nullptr;
//     Node* third = nullptr;

//     head = new Node();
//     second = new Node();
//     third = new Node();

//     head->data = 1;
//     head->next = second;
//     second->data = 2;
//     second->next = third;
//     third->data = 3;
//     third->next = nullptr;

//     traverseList(head);

//     return 0;
// }

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < 5; i++) {
        Node* temp = new Node;
        temp->data = i + 1;
        temp->prev = tail;
        temp->next = NULL;
        if (tail != NULL) {
            tail->next = temp;
        } else {
            head = temp;
        }
        tail = temp;
    }
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}