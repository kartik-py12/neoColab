// Single File Programming Question
// Problem Statement



// You are given a circular header linked list. The program should allow the insertion of elements at the end of the list and the deletion of nodes at a given position. The program should display the contents of the circular linked list after each operation.



// Company Tags: CTS 

// Input format :
// The first line contains an integer n representing the number of elements to be inserted into the circular linked list.

// The second line contains n space-separated integers representing the elements to be inserted.

// The last line contains an integer representing the position(1-based) for deletion.

// Output format :
// The output should display the contents of the circular linked list after each operation.

// If the position for deletion is invalid, the output should display "Invalid position."



// Refer to the sample output for the exact text and formatting specifications.

// Code constraints :
// The data values in the circular linked list are integers.

// The program should handle an empty list appropriately.

// Sample test cases :
// Input 1 :
// 4
// 1 2 3 4
// 3
// Output 1 :
// Contents of the CLL:
// |1| --> |2| --> |3| --> |4| --> 
// After deleting at position 3:
// Contents of the CLL:
// |1| --> |2| --> |4| --> 
// Input 2 :
// 5
// 1 2 3 4 5
// 5
// Output 2 :
// Contents of the CLL:
// |1| --> |2| --> |3| --> |4| --> |5| --> 
// After deleting at position 5:
// Contents of the CLL:
// |1| --> |2| --> |3| --> |4| --> 
// Input 3 :
// 5
// 1 2 3 4 5
// 6
// Output 3 :
// Contents of the CLL:
// |1| --> |2| --> |3| --> |4| --> |5| --> 
// Invalid position.

// You are using GCC

// with circular linked list [without header (special node containg len of nodes)]


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr) {}
};

// typedef Node* NODE;

// NODE getnode() {
//     NODE x = new Node();
//     return x;
// }

Node* insertAtEnd(Node *&head, int item) {
    Node *temp=new Node(item);

    if (head == nullptr) {
        head = temp;
        head->next = head; //creating a circular linked list as it points back to head
    } else {
        Node *cur = head;
        while (cur->next != head) {
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = head; //same pointing the last node back to head
    }
    return head;
}

Node *deleteAtPosition(Node *&head, int position) {
    //Type your code here
    Node *temp=head;
    for(int i=1;i<position-1;i++){
        // cout<<temp->data<<" ";
        temp=temp->next;
    }
    // cout<<endl<<temp->data<<endl;
    Node *delp=temp->next;
    temp->next=temp->next->next;
    delete delp;
    
    // head->data--;
    return head;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Contents of the CLL:" << endl;
    Node* cur = head;
    do {
        cout << "|" << cur->data << "| --> ";
        cur = cur->next;
    } while (cur != head);
    cout << endl;
}

int main() {
    Node *head = nullptr;
    int item, position;
    int n;
    cin >> n;
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            cin >> item;
            head = insertAtEnd(head, item);
        }
        display(head);
        cin >> position;
        if (position <= n) {
            head = deleteAtPosition(head, position);
            cout << "After deleting at position " << position << ":" << endl;
            display(head);
        } else {
            cout << "Invalid position." << endl;
        }
    } else {
        cout << "List is empty." << endl;
    }

    return 0;
}


// with circularly header linked list [containing header (special node)]

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node(int val): data(val), next(nullptr) {}
// };

// Node* insertAtEnd(Node *&head, int item) {
//     Node *temp=new Node(item);

//     if (head == nullptr) {
//         head = temp;
//         head->next = head; //creating a circular linked list as it points back to head
//     } else {
//         Node *cur = head;
//         while (cur->next != head) {
//             cur = cur->next;
//         }
//         cur->next = temp;
//         temp->next = head; //same pointing the last node back to head
//     }
//     head->data++;
//     return head;
// }


// Node* deleteAtPosition(Node *&head, int position) {
//     // head=head->next;
//     if (head == nullptr) {
//         return nullptr;
//     }
//     Node *temp=head->next;
//     Node *cur = head;
//     cout<<"header data: "<<head->data<<endl;
//     Node *prev = nullptr;

//     // If the node to be deleted is the head node (position 1)
//     if (position == 1) {
//         // Find the last node to update its next pointer
//         while (cur->next != temp) {
//             cur = cur->next;
//         }

//         if (head->next == head) {
//             delete head;
//             head = nullptr;
//         } else {
//             cur->next = head->next;
//             Node *temp = head;
//             head = head->next;
//             delete temp;
//         }
//         return head;
//     }

//     // For other positions
//     cur = temp;
//     for (int i = 1; i < position; i++) {
//         prev = cur;
//         cur = cur->next;
//         if (cur == head) {
//             cout << "Invalid position." << endl;
//             return head;
//         }
//     }

//     prev->next = cur->next;
//     delete cur;
//     return head;
// }

// void display(Node* head) {
//     Node *temp=head;
//     head=head->next;
//     if (head == nullptr) {
//         cout << "List is empty." << endl;
//         return;
//     }

//     cout << "Contents of the CLL:" << endl;
//     Node* cur = head;
//     do {
//         cout << "|" << cur->data << "| --> ";
//         cur = cur->next;
//     } while (cur != temp);
//     cout << endl;
// }

// int main() {
//     Node *head=new Node(0);// creating an header with 0 val
//     head->next=head;
//     int item, position;
//     int n;
    
//     // Input number of elements and insert them
//     cin >> n;
//     if (n > 0) {
//         for (int i = 0; i < n; i++) {
//             cin >> item;
//             head = insertAtEnd(head, item);
//         }

//         // Display the list after insertion
//         display(head);
        
//         // Input position for deletion
//         cin >> position;

//         // Check for valid position and delete node if valid
//         if (position > 0 && position <= n) {
//             head = deleteAtPosition(head, position);
//             cout << "After deleting at position " << position << ":" << endl;
//             display(head);
//         } else {
//             cout << "Invalid position." << endl;
//         }
//     } else {
//         cout << "List is empty." << endl;
//     }

//     return 0;
// }