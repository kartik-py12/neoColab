#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int customerID;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue operation
    void enqueue(int id) {
        Node* newNode = new Node();
        newNode->customerID = id;
        newNode->next = nullptr;
        
        if (rear != nullptr) {
            rear->next = newNode; // Link the old rear to the new node
        }
        rear = newNode; // Update rear to the new node
        if (front == nullptr) {
            front = newNode; // If queue was empty, front is also the new node
        }
        cout << "Customer ID " << id << " is enqueued" << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued customer ID: " << front->customerID << endl;
        Node* temp = front;
        front = front->next; // Move front to the next node
        delete temp; // Free the old front node
        
        if (front == nullptr) {
            rear = nullptr; // If the queue is empty after dequeue
        }
    }

    // Display operation
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Customer IDs in the queue are: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->customerID;
            if (temp->next != nullptr) {
                cout << " ";
            }
            temp = temp->next;
        }
        cout << endl;
    }


};

int main() {
    Queue queue;
    int choice, customerID;

    while (true) {
        cin >> choice;
        if (choice == 1) {
            cin >> customerID;
            queue.enqueue(customerID);
        } else if (choice == 2) {
            queue.dequeue();
        } else if (choice == 3) {
            queue.display();
        } else if (choice == 4) {
            break; // Exit the program
        } else {
            cout << "Invalid option" << endl;
        }
    }

    return 0;
}